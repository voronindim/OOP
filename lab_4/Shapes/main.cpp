#include <iostream>
#include "CShapeProcessor.h"

int main()
{
    std::string inputString;
    CShapeProcessor processor;
    while (getline(std::cin, inputString))
    {
        if (!processor.HandleCommand(inputString))
        {
            std::cout << "Неправильный ввод!" << std::endl;
        }
    }
    processor.DrawShapes();
    return 0;
}
