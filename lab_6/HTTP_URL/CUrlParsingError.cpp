#include "CUrlParsingError.h"


CUrlParsingError::CUrlParsingError(const std::string &errorMessage)
: std::invalid_argument(errorMessage)
{
}
