#include <stdexcept>

class CUrlParsingError : public std::invalid_argument
{
public:
    explicit CUrlParsingError(const std::string& errorMessage);
};
