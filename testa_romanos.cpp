#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
#include "romanos.hpp"

#include <iostream>

using namespace std;

TEST_CASE( "Numeros Romanos", "[romanos]" ) {
    REQUIRE( RomanToInt("MDCCCXIX") == 1819 );
    REQUIRE( RomanToInt("XXV") == 25 );
}

