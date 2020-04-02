#include "GeneratePrimeNumbersSet.h"

void GetPrimesByQuadraticForms(vector<bool> &isPrime)
{
	int sqrtUpperBound = int(sqrt(isPrime.size() - 1));

	for (int x = 1; x <= sqrtUpperBound; x++)
	{
		for (int y = 1; y <= sqrtUpperBound; y++)
		{
			int eqSolution;
			eqSolution = ((4 * x * x) + (y * y));
			if (eqSolution <= isPrime.size() - 1 && (eqSolution % 12 == 1 || eqSolution % 12 == 5))
			{
                isPrime[eqSolution] = !isPrime[eqSolution];
			}
			eqSolution = (3 * x * x) + (y * y);
			if (eqSolution <= isPrime.size() - 1 && (eqSolution % 12 == 7))
			{
                isPrime[eqSolution] = !isPrime[eqSolution];
			}
			if (x > y)
			{
				eqSolution = ((3 * x * x) - (y * y));
				if (eqSolution <= isPrime.size() - 1 && eqSolution % 12 == 11)
				{
                    isPrime[eqSolution] = !isPrime[eqSolution];
				}
			}
		}
	}
}

void DeleteMultipleSquaresOfNumbers(vector<bool> &isPrime)
{
	for (int i = 5; i < sqrt(isPrime.size()); i++)
	{
		if (isPrime[i])
		{
			int n = i * i;
			for (int j = n; j < isPrime.size(); j += n)
			{
                isPrime[j] = false;
			}
		}
	}
}

vector<bool> SearchPrimeNumbers(int upperBound)
{
	vector<bool> isPrime(upperBound + 1, false);
	for (int i = 2; i <= upperBound && i <= 3; i++)
	{
        isPrime[i] = true;
	}
	GetPrimesByQuadraticForms(isPrime);
	DeleteMultipleSquaresOfNumbers(isPrime);
	return isPrime;
}

set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int> primeNumbers;
	if (upperBound > -1)
	{
		vector<bool> sieve = SearchPrimeNumbers(upperBound);

		for (int i = 1; i <= upperBound; i++)
		{
			if(sieve[i])
			{
				primeNumbers.emplace_hint(primeNumbers.end(), i);
			}
		}
	}
	return primeNumbers;
}