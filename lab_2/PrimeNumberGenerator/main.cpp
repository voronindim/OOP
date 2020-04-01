#include "GeneratePrimeNumbersSet.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cout << "Парметры ввода: <name.exe> <number>" << endl;
		return 1;
	}
	int upperBound = atoi(argv[1]);
	if (upperBound > MAX_UPPER_BOUND)
	{
		return 1;
	}
	GeneratePrimeNumbersSet(upperBound);
	return 0;
}

