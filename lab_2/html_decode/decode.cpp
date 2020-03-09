#include "Decode.h"
std::string ReplacementSearch(std::string str)
{
    if (str == "&quot;")
    {
        str = "\"";
    }
    else if (str == "&apos;")
    {
        str = "\'";
    }
    else if (str == "&lt;")
    {
        str = "<";
    }
    else if (str == "&gt;")
    {
        str = ">";
    }
    else if (str == "&amp;")
    {
        str = "&";
    }
    return str;
}

std::string HtmlDecode(std::string const& html)
{
    std::string decodingText;
    decodingText.reserve(html.size());

    std::string::const_iterator iter = html.begin();

    while(iter != html.end())
    {
        if (*iter == START_SYMBOL_DECODER)
        {
            std::string::const_iterator rightBorder = std::find(iter, html.end(), END_SYMBOL_DECODER);
            if (rightBorder != html.end())
            {
                int current = iter - html.begin();
                long lengthSubStr = rightBorder - iter + 1;
                std::string subStr = html.substr(current, lengthSubStr);
                std::string symbol = ReplacementSearch(subStr);
                if (subStr == symbol)
                {
                    decodingText += *iter;
                    ++iter;
                }
                else
                {
                    decodingText += symbol;
                    iter += lengthSubStr;
                }
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
