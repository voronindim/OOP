#include <iostream>
#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <string>

int main()
{
    std::string input;
    while(getline(std::cin, input))
    {
        try
        {
            CHttpUrl url(input);
            std::cout << "url: " << url.GetURL() << std::endl;
            std::cout << "Protocol: " << CHttpUrl::GetProtocolToString(url.GetProtocol()) << std::endl;
            std::cout << "Domain: " << url.GetDomain() << std::endl;
            std::cout << "Port: " << url.GetPort() << std::endl;
            std::cout << "Document: " << url.GetDocument() << std::endl;
        }
        catch (const CUrlParsingError& error)
        {
            std::cout << error.what() << std::endl;
        }
        catch (const std::runtime_error& error1)
        {
            std::cout << error1.what() << std::endl;
        }
    }
    return 0;
}
