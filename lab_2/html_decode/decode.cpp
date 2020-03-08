#include "Decode.h"
std::string ReplacementSearch(std::string& str)
{
    if (str == "&quot;")
    {
        str = "\"";
        return str;
    }
    if (str == "&apos;")
    {
        str = "\'";
        return str;
    }
    if (str == "&lt;")
    {
        str = "<";
        return str;
    }
    if (str == "&gt;")
    {
        str = ">";
        return str;
    }
    if (str == "&amp;")
    {
        str = "&";
        return str;
    }
    return str;
}

std::string DecodeHtml(std::string& str)
{
    std::string decodingText;
    decodingText.reserve(str.size());

    std::string::iterator iter = str.begin();

    while(iter != str.end())
    {
        if (*iter == START_SYMBOL_DECODER)
        {
            std::string::iterator rightBorder = std::find(iter, str.end(), END_SYMBOL_DECODER);
            if (rightBorder != str.end())
            {
                int current = iter - str.begin();
                long lengthSubStr = rightBorder - iter + 1;
                std::string cipherLetters = str.substr(current, lengthSubStr);
                std::string symbol = ReplacementSearch(cipherLetters);
                decodingText += symbol;
                iter += lengthSubStr;
            }
            else
            {
                decodingText += *iter;
                ++iter;
            }
        }
        else
        {
            decodingText += *iter;
            ++iter;
        }
    }
    return decodingText;
}
