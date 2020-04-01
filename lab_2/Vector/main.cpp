#include <iostream>
#include <iomanip>
#include "ProcessVector_7.h"

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
