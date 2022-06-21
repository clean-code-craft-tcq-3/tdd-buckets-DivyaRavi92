#include "BatteryMeasurements.h"
#include "stdbool.h"

void sortArray(int *RangeInput, int length)
{
    int tempElm;
    for (int startEl=0; startEl < length; ++startEl)
    {
       for (int nextElm=startEl+1; nextElm < length; ++nextElm)
      {
         if (RangeInput[startEl] > RangeInput[nextElm])
        {
          tempElm = RangeInput[startEl];
          RangeInput[startEl] = RangeInput[nextElm];
          RangeInput[nextElm] = tempElm;
        }
 
       }
    }
    
}

bool checkConsecutive(int *RangeInput, int size)
{
    int readings[size];
    int begin[size];
    int end[size];
    bool rangeCheckIsConsecutive = false;
    int isConsecutive = 0, k=0, startEl;
    for (startEl=0; startEl < size-1; ++startEl) 
    {
        if (RangeInput[startEl+1] - RangeInput[startEl] == 0 || RangeInput[startEl+1] - RangeInput[startEl] == 1)
        {
          isConsecutive +=1;
          if(isConsecutive == 1)
          {
            begin[k] = RangeInput[startEl];
            rangeCheckIsConsecutive = true;
          }
        }
        else  if(isConsecutive >= 1)
        {   
            readings[k] = isConsecutive+1; end[k] = RangeInput[startEl];
            k++;
            isConsecutive = 0;
        }
    }
    if(isConsecutive >= 1)
    {   
        readings[k] = isConsecutive+1; end[k] = RangeInput[startEl];
        isConsecutive = 0;
    } 
    int readingsLength = k;
    printOnConsole(readings, begin, end, readingsLength);
    return rangeCheckIsConsecutive;
}
bool getBatteryRange(int *RangeInput, int length, int startRange, int endRange)
{
   sortArray(RangeInput, length);
   printf("sorted array\n");
   for(int i=0;i<length;i++)
   {
       printf("%d\n",RangeInput[i]);
   }
   bool  rangeCheckIsConsecutive = checkConsecutive(RangeInput, length);
   return rangeCheckIsConsecutive;
}  

void printOnConsole(int* readings, int* begin, int* end, int* length)   
{
   for(int i  = 0; i <= length; i++)
   {
        printf("readings=%d\n", readings[i]);
        printf("begin=%d\n", begin[i]);
        printf("end=%d\n", end[i]);
   }

}
