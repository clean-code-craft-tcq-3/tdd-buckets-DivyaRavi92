#include "BatteryMeasurements.h"


int getBatteryRange(int *RangeInput, int startRange, int endRange)
{
   int arrayLength =0;
   int valueInRange =0;
   arrayLength = sizeof(RangeInput);
   for(int rangeElm=0; rangeElm < arrayLength ; rangeElm++)
   {
       checkValueInRange(RangeInput[i],startRange,endRange, &valueInRange))
      
   }
  printf("\n%d-%d,%d",startRange,endRange,valueInRange);
  return valueInRange;  
}

#include <stdio.h>
#include "main.h"

void checkValueInRange(int value,int startRange ,int endRange, int * RangeCheck)
{
  if((value >= startRange) && (value <= endRange))
  {
    *RangeCheck++;
  }
}

int getNoOfRValuesInRange(int* array_p,int startRange ,int endRange)
{
  int arrayLength =0;
  int valueInRange =0;
  arrayLength = sizeof(array_p);
  for(int i=0; i< arrayLength ;i++)
  {
       if(true == checkInRange(array_p[i],startRange,endRange))
       {
         valueInRange ++;
       }
       else
       {
         
       }
  }
  printf("\n%d-%d,%d",startRange,endRange,valueInRange);
  return valueInRange;
}
        
