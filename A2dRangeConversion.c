#include "A2dRangeConversion.h"

int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution)
{
   int ampereVal = -1;
   A2Dvalue = abs(A2Dvalue);
   int maxA2Dvalue = pow(2,bitresolution) - 2;
   if(bitresolution == 12)
   {
      convertA2DtoAmpere12BitA2D(maxAmp, A2Dvalue, maxA2Dvalue, &ampereVal);
   }
   else 
   {
      convertA2DtoAmpere10BitA2D(maxAmp, A2Dvalue, maxA2Dvalue, &ampereVal);
   }

   return ampereVal;
}

void convertA2DtoAmpere12BitA2D(int maxAmp, int A2Dvalue, int maxA2Dvalue, int *ampereVal)
{
    if(A2Dvalue <= maxA2Dvalue)
    {
        float convertedvalue = (float)maxAmp * (float)A2Dvalue/(float)maxA2Dvalue; 
        *ampereVal = round(convertedvalue);
    }
}

void convertA2DtoAmpere10BitA2D(int maxAmp, int A2Dvalue,int maxA2Dvalue, int *ampereVal)
{
    if(A2Dvalue <= maxA2Dvalue)
    {
        float convertedvalue = (float)(2*maxAmp) * (float)A2Dvalue/(float)maxA2Dvalue; 
        *ampereVal = round(convertedvalue);
        *ampereVal = *ampereVal - maxAmp;
        *ampereVal = abs(*ampereVal);
    }
}


int convertA2DToAmpereRange(int A2Dvaluearray[], int arraysize, int* Amperearray, int maxAmp, int bitresolution)
{
   int count=0;
   for(int index=0; index < arraysize; index++)
   {
     int Ampere = convertA2DToAmpere(maxAmp,A2Dvaluearray[index],bitresolution);
      if(Ampere != -1)
      {
         Amperearray[count] = Ampere;
         count++;
      }
   }
   return count;
}
