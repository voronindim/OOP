#include "Decode.h"
#include <iostream>

int main()
{
    std::string encodingLine;

    while(std::getline(std::cin, encodingLine))
    {
        std::string decodeLine = HtmlDecode(encodingLine);
        std::cout << decodeLine << std::endl;
    }
    return 0;
}
