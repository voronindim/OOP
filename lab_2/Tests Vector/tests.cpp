#include "catch.hpp"
#include "ProcessVector.h"

TEST_CASE("Check the result of ProcessVector()")
{
    VectorOfDouble vector;
    VectorOfDouble resultVector;
    CHECK(!ProcessVector(vector));

    vector = {2, 2};
    CHECK(!ProcessVector(vector));

    vector = {0.1, 0.1, 0.1};
    resultVector = {0.4, 0.4, 0.4};
    ProcessVector(vector);
    CHECK(vector == resultVector);

    vector = {-2, -1, 0};
    resultVector = {-5, -4, -3};
    ProcessVector(vector);
    CHECK(vector == resultVector);
}
