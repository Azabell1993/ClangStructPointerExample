#include "CalculatorLib.h"
#include "Calculator.c"

int
main (int NumA, char Ch, int NumB)
{
    NumA = 0;
    NumB = 0;

    scanf("%d%c%d", &NumA, &Ch, &NumB);
    printf("the final formula : "); 
    CallCalc(NumA, Ch, NumB);
}