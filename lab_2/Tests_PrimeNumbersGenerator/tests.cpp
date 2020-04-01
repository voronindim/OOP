#include "catch.hpp"
#include "GeneratePrimeNumbersSet.h"

TEST_CASE("Проверка функции GeneratePrimeNumbersSet от 0")
{
	int upperBound = 0;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	set<int> resultPrime = {};
	CHECK(startPrime == resultPrime);
}

TEST_CASE("Проверка функции GeneratePrimeNumbersSet от 3")
{
	int upperBound = 3;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	set<int> resultPrime = {2, 3};
	CHECK(startPrime == resultPrime);
}

TEST_CASE("Проверка функции GeneratePrimeNumbersSet от 100'000'000")
{
	int upperBound = 100000000;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	CHECK(startPrime.size() == 5761455);
}

TEST_CASE("Проверка функции GeneratePrimeNumbersSet от 12")
{
    int upperBound = 12;
    set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
    set<int> resultPrime = {2, 3, 5, 7, 11};
    CHECK(startPrime == resultPrime);
}
