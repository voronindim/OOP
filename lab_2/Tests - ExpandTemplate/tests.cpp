#include "catch.hpp"
#include "../ExpandTemplate/ExpendTeplate.h"

TEST_CASE()
{
    Replacement resultParams = {
            {"хорошо", "плохо"},
            {"зло", "добро"}
    };
    int argc = 4;
    char ** ptr = new char*[4];
    char *argv[] = {"хорошо", "плохо", "зло", "добро"};
    CHECK(CreateVocabulary(ptr, argv) == resultParams);
}