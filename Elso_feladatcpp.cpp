#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	//lefoglalas
	int meret = 100;
	unsigned int* tomb = (unsigned int*)calloc(sizeof(int), meret);

	//feltoltes
	for (int i = 0; i < meret; i++)
		tomb[i] = rand() % 1000;

	int index = 0, value = 0;
	do {
		std::cin >> index >> value;

		if (index != -1 && value != -1) {
			float probability = (float)rand() / RAND_MAX;

			if (probability <= 0.29) tomb[index] = value;
		}
	} while (index !=-1 && value != -1 );

	char characters[100];
	int c_index = 0;
	for (int i = 0; i < meret; i++)
	{
		if (tomb[i] >= 33 && tomb[i] <= 126) {
			std::cout << tomb[i];
			characters[c_index] = tomb[i];
			c_index++;
		}
	}

	free(tomb);
	return 0;
}