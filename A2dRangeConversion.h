#include <stdio.h>
#include "math.h"

int convertA2DToAmpereRange(int A2Dvaluearray[], int arraysize, int* Amperearray, int maxAmp, int bitresolution);
int convertA2DToAmpere(int maxAmp,int A2Dvalue,int bitresolution);
void convertA2DtoAmpere12BitA2D(int maxAmp, int A2Dvalue, int maxA2Dvalue, int *ampereVal);
void convertA2DtoAmpere10BitA2D(int maxAmp,int A2Dvalue, int maxA2Dvalue, int *ampereVal);
