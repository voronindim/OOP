#include "catch.hpp"
#include "GeneratePrimeNumbersSet.h"

TEST_CASE("если upper меньше двух должно вернуться пустое множество")
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
}

TEST_CASE("Если upperBound == 100'000'000 количество простых чисел должно быть 5761255")
{
	int upperBound = 100000000;
	set<int> startPrime = GeneratePrimeNumbersSet(upperBound);
	CHECK(startPrime.size() == 5761455);
}


