#include <iostream>
#include "catch_amalgamated.hpp"

bool isPrime(int x) {
    if (x < 2 || (x % 2 == 0 && x != 2))
        return false;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

TEST_CASE("isPrime_isGood") {
    REQUIRE(isPrime(2));
    REQUIRE(isPrime(3));
    REQUIRE(!isPrime(4));
    REQUIRE(!isPrime(0));
    REQUIRE(!isPrime(1));
    REQUIRE(isPrime(5));
    REQUIRE(!isPrime(10));
    REQUIRE(!isPrime(1));
}