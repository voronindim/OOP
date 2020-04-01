#include "GeneratePrimeNumbersSet.h"

void GetPrimesByQuadraticForms(vector<bool> &sieveAtkina)
{
    int sqrtUpperBound = int(sqrt(sieveAtkina.size() - 1));

    for (int x = 1; x <= sqrtUpperBound; x++)
    {
        for (int y = 1; y <= sqrtUpperBound; y++)
        {
            int result;
            result = ((4 * x * x) + (y * y));
            if (result <= sieveAtkina.size() - 1 && (result % 12 == 1 || result % 12 == 5))
            {
                sieveAtkina[result] = !sieveAtkina[result];
            }
            result = (3 * x * x) + (y * y);
            if (result <= sieveAtkina.size() - 1 && (result % 12 == 7))
            {
                sieveAtkina[result] = !sieveAtkina[result];
            }
            if (x > y)
            {
                result = ((3 * x * x) - (y * y));
                if (result <= sieveAtkina.size() - 1 && result % 12 == 11)
                {
                    sieveAtkina[result] = !sieveAtkina[result];
                }
            }
        }
    }
}

void DeleteSquaresNumbers(vector<bool> &sieveAtkina)
{
	for (int j = 5; j < sqrt(sieveAtkina.size() - 1); j++)
	{
		if (sieveAtkina[j])
		{
			int n = j * j;
			for (int i = n; i <= sieveAtkina.size() - 1; i += n)
			{
				sieveAtkina[i] = false;
			}
		}
	}
}

vector<bool> SearchPrimeNumbers(int upperBound)
{
	vector<bool> sieveAtkina(upperBound + 1, false);
	GetPrimesByQuadraticForms(sieveAtkina);
	DeleteSquaresNumbers(sieveAtkina);
	return sieveAtkina;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> PrimeNumbers;
	if (upperBound >= 3)
	{
		PrimeNumbers.insert(2);
		PrimeNumbers.insert(3);
	}
	vector<bool> sieve = SearchPrimeNumbers(upperBound);
	for (int i = 5; i <= upperBound; i++)
	{
		if(sieve[i])
		{
			PrimeNumbers.insert(i);
		}
	}
	cout << PrimeNumbers.size() << endl;
	return PrimeNumbers;
}