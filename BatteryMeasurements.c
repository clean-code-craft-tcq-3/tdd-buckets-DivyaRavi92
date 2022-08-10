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

int checkConsecutive(int *RangeInput, int size)
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
        }
        else
        {
            return isConsecutive;  
        }
    }
    return isConsecutive;  
}

void printOnConsole(int* RangeInput, int size)   
{
   for(int i  = 0; i <= size; i++)
   {
        printf("Range - Readings\n");
        printf("%d - %d, %d\n", RangeInput[0], RangeInput[size-1], size);
   }

}

bool getBatteryRange(int *RangeInput, int length, int startRange, int endRange)
{
   sortArray(RangeInput, length);
   printf("sorted array\n");
   for(int i=0;i<length;i++)
   {
       printf("%d\n",RangeInput[i]);
   }
   int  ConsecutiveVal  = checkConsecutive(RangeInput, length);
   if(ConsecutiveVal >= 1)
   {
       int size = ConsecutiveVal+1;
       printOnConsole(RangeInput, size);
   }
   return true;
}  
