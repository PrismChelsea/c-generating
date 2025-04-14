/*
Az alapfeladat egy számkitalálós játék implementálása lesz. A játék szabályai az
alábbiak lesznek:
• A számítógép 20 számot fog véletlenszerűen generálni 1 és 100 között
• A felhasználó ezekre fog tippet adni három körben. Ehhez a program be fog
kérni 10 számot 3x, majd statisztikát készít, hogy körönként hányat talált el a
felhasználó
• A harmadik kör végén százalékos találati eredményeket ad vissza a program,
hogy melyik számot a felhasználó hányszor találta el
*/

#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	unsigned int szamok[20];
	float tippek[20] = {}; //bool

	for (int i = 0; i < 20; i++) {
		szamok[i] = rand() % 100 + 1;
	}
	
	for (int i = 0; i < 3; i++) {
		float talalatok = 0;
		bool talalt_szamok[20] = {};
		std::cout << i << ".kör\n"; // \n ugyanaz mint az std::cout
		for (int j = 0; j < 10; j++)
		{
			int tipp = 0;
			std::cin >> tipp;
			for (int k = 0; k < 20; k++) {
				if (tipp == szamok[k] && !talalt_szamok[k]) {
					tippek[k] += 1;
					++talalatok;
					talalt_szamok[k] = true;
					break;
				}
			}
		}
		std::cout << "talalati arany: " << talalatok / 10;
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << szamok[i];
		std::cout << " : " << 100*tippek[i] / 3;
		std::cout << std::endl;
	}
	return 0;
}