#include "ProcessVector_7.h"

typedef std::vector<double> VectorOfDouble;

void AddNumberToVector(VectorOfDouble &vector, double number)
{
    for (double & i : vector)
    {
        i = i + number;
    }
}

double SearchMinNumbers(VectorOfDouble vector)
{
    std::sort(vector.begin(), vector.end());
    double sum = 0;
    for (int i = 0; i < AMOUNT_MIN_ELEMENTS; i++)
    {
        sum = sum + vector[i];
    }
    return sum;
}

bool ProcessVector(VectorOfDouble &numbers)
{
    if (numbers.size() < AMOUNT_MIN_ELEMENTS)
    {
        std::cout << "Введено меньше трех чисел!" << std::endl;
        return false;
    }
    double number;
    number = SearchMinNumbers(numbers);
    AddNumberToVector(numbers, number);
    return true;
}

