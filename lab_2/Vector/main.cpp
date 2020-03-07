#include <iostream>
#include <vector>
#include <iomanip>

const int AMOUNT_MIN_ELEMENTS = 3;

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
int main()
{
    VectorOfDouble numbers (std::istream_iterator<double>(std::cin), (std::istream_iterator<double>()));
    if (!ProcessVector(numbers))
    {
        return 1;
    }
    std::sort(numbers.begin(),numbers.end());
    std::cout << std::fixed << std::setprecision(3);
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(std::cout," "));
    return 0;
}
