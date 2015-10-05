#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "vector.h"

TEST_CASE("Vector default ctor") {
    Vector v;
    for (unsigned i = 0; i < v.n; ++i) {
        REQUIRE(v[i] == 0.0);
    }
}