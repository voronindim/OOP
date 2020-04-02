#include "catch.hpp"
#include "../PrimeNumberGenerator/GeneratePrimeNumbersSet.h"



TEST_CASE("Если upperBound меньше двух должно вернуться пустое множество")
{
	int upperBound = 0;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	set<int> resultPrime = {};
	CHECK(startPrime == resultPrime);
}

TEST_CASE("При верхней границы больше двух должно вернуться множество простых чисел, непрвышающих заданную границу")
{
	int upperBound = 3;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	set<int> resultPrime = {2, 3};
	CHECK(startPrime == resultPrime);

	upperBound = 12;
	startPrime = GeneratePrimeNumbersSet(upperBound);
	resultPrime = {2, 3, 5, 7, 11};
	CHECK(startPrime == resultPrime);

    upperBound = 25;
    startPrime = GeneratePrimeNumbersSet(upperBound);
    resultPrime = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    CHECK(startPrime == resultPrime);
}

TEST_CASE("Если upperBound == 100'000'000 количество простых чисел должно быть 5761255")
{
	int upperBound = 100000000;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	CHECK(startPrime.size() == 5761455);
}

TEST_CASE("Если upperBound == -100'000'000 должно вернуться пустое множенство")
{
    int upperBound = -100000000;
    set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
    set<int> resultPrime = {};
    CHECK(startPrime == resultPrime);
}



