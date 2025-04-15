#include <iostream>
#include <cstdlib>

int findIndex(int* szamok, int meret, int element) {
	int result = -1;
	for (int i = 0; i < meret; i++) {
		if (szamok[i] == element) result = i;
	}

	return result;
}

int main(int argc, char* argv[])
{
	int szamok[20] = { 0 };
	float count_talalat[20] = { 0 };

	int counter = 0;
	do
	{
		int value = rand() % 100 + 1;
		if (findIndex(szamok, 20, value) == -1) {
			szamok[counter] = value;
			counter += 1;
		}
	}while (counter < 20);

	int tipp=0;
	float korok[3] = { 0 };
	for (int i = 1; i <= 3; i++) {
		std::cout << i << " kor:\n";
		for (int j = 0; j < 10; j++) {
			std::cout << "Tippelj egy szamra: ";
			std::cin >> tipp;

			int index = findIndex(szamok, 20, tipp);
			if (index> -1) {
				count_talalat[index] += 1;
				korok[i-1] += 1;
			}
		}
		std::cout << "Talalati statisztika: " << korok[i-1] / 10 * 100 << "%"<<std::endl;
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << szamok[i] << "," << count_talalat[i] / 3 * 100 << "%" << std::endl;
	}

	return 0;
}