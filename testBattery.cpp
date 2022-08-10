#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BatteryMeasurements.h"


//TDD_STEP1: Write only the test code without the actual definition in .c file
TEST_CASE("test1-no definition") {
   int sampleRange[] ={4,5};
   int arrayLength = sizeof(sampleRange)/ sizeof(sampleRange[0]);
   REQUIRE(getBatteryRange(sampleRange,arrayLength) == 1);
}

//TDD_STEP2: Write the actual definition in .c file but without any content, so test will fail
TEST_CASE("test2-test condition fails") {
   int sampleRange[] ={3,3,5,4,10,11,12};
   int arrayLength = sizeof(sampleRange)/ sizeof(sampleRange[0]);
   REQUIRE(getBatteryRange(sampleRange,arrayLength) == 1);
}
