/*
Készítsék el az alábbi szoftver implementációját az következőek szerint:
• A szoftver foglaljon le dinamikusan egy 100 elemű egész típusú előjel nélküli
tömböt nulla kezdőértékkel! (1p)
• A szoftver feltölti az előzőleg lefoglalt tömb elemeit véletlenszerű értékekkel!
(1p)
• A szoftver kérjen be a felhasználótól számpárokat 0 és 99 között egészen addig,
amíg -1-et nem kap a felhasználótól bármelyik szám esetében! (2p)
• A szoftver egy eljárást alkalmazva a beolvasás alatt kicseréli a tömb megfelelő
elemeit 29%-os eséllyel cseréli ki a számpárokat indexként és értékként
felhasználva! (2p)
• A szoftver kiírja azokat a tömbelemek értékeit, melyek az ASCII szerint
karaktereknek feleltethetőek meg! A kiírás során a szoftver átkonvertálja ezeket
a számértékeket a táblázatban található karakterkódnak megfelelően (2p)
• A szoftver külön karaktertömbbe kigyűjti a kiírható értékeket! (2p)
*/

#include <iostream>
#include <cstdlib>

void feltolt(unsigned int* tomb, unsigned int index, unsigned int value) {
	unsigned int rand_value = rand() % 100;
	if (rand_value <29)	tomb[index] = value;
}

int main(int argc, char* argv[])
{
	unsigned int* tomb = (unsigned int*)calloc(100, sizeof(unsigned int));
	char karakterek[100];

	unsigned int value1 = 0, value2 = 0;
	while (value1 !=-1 && value2 !=-1) {
		std::cin >> value1 >> value2;
		if (value1 >= 0 && value1 <= 99 &&
			value2 >= 0 && value2 <= 99)
			feltolt(tomb, value1, value2);

	}

	int karakterindex = 0;
	for (int i = 0; i < 100; i++)
	{
		if (tomb[i] >= 33 && tomb[i] <= 99) {
			karakterek[karakterindex] = tomb[i];
			std::cout << karakterek[karakterindex];
			++karakterindex;
		}
	}
	std::cout << std::endl;

	free(tomb);
	return 0;
}