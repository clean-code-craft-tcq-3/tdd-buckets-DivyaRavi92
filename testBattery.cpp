#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BatteryMeasurements.h"


//TDD_STEP1: Write only the test code without the actual definition in .c file
TEST_CASE("detect set of values  from  specified range within input array of integers") {
   int sampleRange[] ={4,5};
   int startBatteryRange = 4;
   int endBatteryRange = 5;
   REQUIRE(getBatteryRange(sampleRange,startBatteryRange,endBatteryRange) == 2);
}
