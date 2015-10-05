#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "vector.h"

typedef double Vec3[3];

void cmp_vec_arr(const Vector &lhs, const Vec3 &rhs) {
    assert(Vector::n == sizeof(rhs)/sizeof(rhs[0]));
    for (unsigned i = 0; i < Vector::n; ++i) {
        REQUIRE(lhs[i] == rhs[i]);
    }    
}

TEST_CASE("Vector default ctor") {
    Vector v;
    Vec3 expected = {0.0, 0.0, 0.0};
    cmp_vec_arr(v, expected);
}

TEST_CASE("Vector init value ctor") {
    SECTION("Zeros") {
        Vector v{0};
        Vec3 expected = {0.0, 0.0, 0.0};
        cmp_vec_arr(v, expected);
    }
    SECTION("Ones") {
        Vector v{1.0};
        Vec3 expected = {1.0, 1.0, 1.0};
        cmp_vec_arr(v, expected);
    }
    SECTION("Minus ones") {
        Vector v{-1.0};
        Vec3 expected = {-1.0, -1.0, -1.0};
        cmp_vec_arr(v, expected);
    }
    SECTION("42") {
        Vector v{42};
        Vec3 expected = {42.0, 42.0, 42.0};
        cmp_vec_arr(v, expected);
    }
}

TEST_CASE("Vector copy ctor") {
    SECTION("Zeros") {
        Vector v{0};
        Vector copy{v};
        Vec3 expected = {0.0, 0.0, 0.0};
        cmp_vec_arr(copy, expected);
    }
    SECTION("Ones") {
        Vector v{1.0};
        Vector copy{v};
        Vec3 expected = {1.0, 1.0, 1.0};
        cmp_vec_arr(copy, expected);
    }
    SECTION("Minus ones") {
        Vector v{-1.0};
        Vector copy{v};
        Vec3 expected = {-1.0, -1.0, -1.0};
        cmp_vec_arr(copy, expected);
    }
    SECTION("42") {
        Vector v{42};
        Vector copy{v};
        Vec3 expected = {42.0, 42.0, 42.0};
        cmp_vec_arr(copy, expected);
    }
}

TEST_CASE("Vector copy assignment") {
    SECTION("Zeros") {
        Vector v{0}, copy;
        copy = v;
        Vec3 expected = {0.0, 0.0, 0.0};
        cmp_vec_arr(copy, expected);
    }
    SECTION("Ones") {
        Vector v{1.0}, copy;
        copy = v;
        Vec3 expected = {1.0, 1.0, 1.0};
        cmp_vec_arr(copy, expected);
    }
    SECTION("Minus ones") {
        Vector v{-1.0}, copy;
        copy = v;
        Vec3 expected = {-1.0, -1.0, -1.0};
        cmp_vec_arr(copy, expected);
    }
    SECTION("42") {
        Vector v{42}, copy;
        copy = v;
        Vec3 expected = {42.0, 42.0, 42.0};
        cmp_vec_arr(copy, expected);
    }
}

TEST_CASE("Indexing operator") {
    Vector v;
    Vec3 expected = {1.0, 2.0, 3.0};
    for (unsigned long i = 0; i < Vector::n; ++i) {
        v[i] = expected[i];
    }
    cmp_vec_arr(v, expected);
}