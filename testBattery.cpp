#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BatteryMeasurements.h"
#include "A2dRangeConversion.h"


//TDD_STEP1: Write only the test code without the actual definition in .c file
TEST_CASE("test1-no definition") {
   int sampleRange[] ={4,5};
   int arrayLength = sizeof(sampleRange)/ sizeof(sampleRange[0]);
   REQUIRE(getBatteryRange(sampleRange,arrayLength) == 1);
}

//TDD_STEP2: Write the actual definition in .c file but without any content, so test will fail
TEST_CASE("test2 2 different consecutive readings") {
   int sampleRange[] ={3,3,5,4,10,11,12};
   int arrayLength = sizeof(sampleRange)/ sizeof(sampleRange[0]);
   REQUIRE(getBatteryRange(sampleRange,arrayLength) == 1);
}
   
//TDD_STEP3: 
TEST_CASE("test3 - No continuous reading found") {
   int sampleRange[] ={3,6,10,12};
   int arrayLength = sizeof(sampleRange)/ sizeof(sampleRange[0]);
   REQUIRE(getBatteryRange(sampleRange,arrayLength) == 0);
}

//TDD_STEP4:
TEST_CASE("test4 - checking if all the sensor values are giving valid current ranges for 12 bit  - by getting the count ") {
   int AnalogArray[] = {1146,4094, 2045};
   int arrayLength = sizeof(AnalogArray) / sizeof(AnalogArray[0]);  
   int Amperearray[] = {0};
   int maxAmp = 10;
   int bitresolution = 12;
   REQUIRE(convertA2DToAmpereRange(AnalogArray, arrayLength, Amperearray, maxAmp, bitresolution) == 3);
}

//TDD_STEP5:
TEST_CASE("test5 - checking if all the sensor values are giving valid current ranges for 15 bit- by getting the count ") {
   int AnalogArray[] = {1022,0,511};
   int arrayLength = sizeof(AnalogArray) / sizeof(AnalogArray[0]);  
   int Amperearray[] = {0};
   int maxAmp = 15;
   int bitresolution = 10;
   REQUIRE(convertA2DToAmpereRange(AnalogArray, arrayLength, Amperearray, maxAmp, bitresolution) == 3);
}

//TDD_STEP6:
TEST_CASE("test6 - a2d values converted used to split battery range ") {
   int AnalogArray[] = {1022,0,511, 1022};
   int arrayLength = sizeof(AnalogArray) / sizeof(AnalogArray[0]);  
   int Amperearray[] = {0};
   int maxAmp = 15;
   int bitresolution = 10;
   int ampereArraySize = convertA2DToAmpereRange(AnalogArray, arrayLength, Amperearray, maxAmp, bitresolution);
   REQUIRE(getBatteryRange(Amperearray,ampereArraySize) == 3);
   
}
