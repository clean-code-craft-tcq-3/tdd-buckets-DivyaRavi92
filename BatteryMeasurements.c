#include "BatteryMeasurements.h"


int getBatteryRange(int *RangeInput, int startRange, int endRange)
{
   int arrayLength =0;
   int valueInRange =0;
   arrayLength = sizeof(RangeInput);
   for(int rangeElm=0; rangeElm < arrayLength ; rangeElm++)
   {
      valueInRange = checkValueInRange(RangeInput[rangeElm],startRange,endRange, valueInRange))
      
   }
  printf("\n%d-%d,%d",startRange,endRange,valueInRange);
  return valueInRange;  
}

int checkValueInRange(int value,int startRange ,int endRange, int RangeCheck)
{
  if((value >= startRange) && (value <= endRange))
  {
    RangeCheck++;
  }
  return RangeCheck;
}


