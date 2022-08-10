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

void printOnConsole(int* RangeInput, int size)   
{
    printf("Range - Readings\n");
    printf("%d - %d, %d\n", RangeInput[0], RangeInput[size-1], size);
}

int isConsecutive(int diff)
{
   int consecutive = 0;
   if((diff==0) || (diff)==1)
     consecutive=1;
   return consecutive;
}

void sortedArrayPrintOnConsole(int * RangeInput,int length)
{
   printf("sorted array\n");
   for(int i=0;i<length;i++)
   {
       printf("%d\n",RangeInput[i]);
   }
}

bool getBatteryRange(int *RangeInput, int length, int startRange, int endRange)
{
   int consecutivecount = 0;
   bool isRangeContinuous = false;
   sortArray(RangeInput, length);
   int startvalue = RangeInput[0];
   int endvalue = RangeInput[0];
   sortedArrayPrintOnConsole(RangeInput,length);
   for(int index = 0 ; index < arraysize; index++ ) 
   {                                                                
      int diff = RangeInput[index+1] - RangeInput[index];           
      int isconsecutive=0;
      isconsecutive = isConsecutive(diff);
      if(isconsecutive == 1)
      {
         consecutivecount++;
         endvalue = RangeInput[index+1];
      }
      else if(consecutivecount >= 1) 
      {
        isRangeContinuous = true;
        consecutivecount++;
        printOnConsole(startvalue,endvalue, consecutivecount);
        startvalue = RangeInput[index+1];
        endvalue = RangeInput[index];
        consecutivecount=0;
      }
      else
      {
         startvalue = RangeInput[index+1];
         endvalue = RangeInput[index];
      }
    }
    return isRangeContinuous;
}  
