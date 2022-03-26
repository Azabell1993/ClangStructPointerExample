#include "CalculatorLib.h"

/*  Addition, subtraction and addition using bitwise operations */
int SUM(int x, int y) { return y ? SUM(x^y,(x&y)<<1):x; } 
int SUB(int x, int y) { return y ? SUB(x^y,(~x&y)<<1):x; }

void
Dot_Putchar(char c)
/* 
    Add Char '.'
*/
{
    write(1, &c, 1);
}

int
MUL(int x, int y) 
/* 
    Multiplication adder using bitwise operation 
*/
{
    int temp = 0;
    while (y != 0)
    {
        if (y&1)
        {
            temp += x;
        }
        x = x << 1;
        y = y >> 1;
    }
    return temp;
}

int 
DIV(int x, int y)
/*  
    Division adder using bitwise operation 
*/
{
    int result = 1;
    int remainder = 0;

    int neg = 1;
    if ((x>0 &&y<0)||(x<0 && y>0))
    {
        neg = -1;
    }
        
    unsigned int tempx = (x < 0) ? -x : x;
    unsigned int tempy = (y < 0) ? -y : y;

    if (tempy == tempx) {
        remainder = 0;
        return 1*neg;
    }
    else if (tempx < tempy) {
        if (x < 0)
            remainder = tempx*neg;
        else
            remainder = tempx;
        return 0;
    }

    while (tempy<<1 <= tempx)
    {
        tempy = tempy << 1;
        result = result << 1;
    }

    if(x < 0)
        result = result*neg + DIV(-(tempx-tempy), y);
    else
        result = result*neg + DIV(tempx-tempy, y);

     return ((float)result);
}

int 
SelectSUM (int NumA, char Ch, int NumB) 
/*
    Using function pointer macros - SUM
*/
{ 
    return 
    (printf("%d %c %d = %d", NumA, Ch, NumB, (*CalFunc[0])(NumA,NumB))); 
}

int 
SelectSUB (int NumA, char Ch, int NumB)
/*
    Using function pointer macros - SUB
*/
{ 
    return 
    (printf("%d %c %d = %d", NumA, Ch, NumB, (*CalFunc[1])(NumA,NumB))); 
}

int 
SelectMUL (int NumA, char Ch, int NumB) 
/*
    Using function pointer macros - MUL
*/
{ 
    return 
    (printf("%d %c %d = %d", NumA, Ch, NumB, (*CalFunc[2])(NumA,NumB))); 
}

int 
SelectDIV (int NumA, char Ch, int NumB)
/*
    Using function pointer macros - DIV
*/
{ 
    return 
    (printf("%d %c %d = %d", NumA, Ch, NumB, (*CalFunc[3])(NumA, NumB)));
}

int
DivWhereNumBGreter (int NumA, char Ch, int NumB)
/*
    Using function pointer macros

    DIV Function(if (NumA < NumB))
*/
{
    float Output_Div = (float)NumA / (float)NumB;

    return
    (printf("%d %c %d = %.2f", NumA, Ch, NumB, Output_Div));
}

void
ft_putchar(char c)
/*
    if 
    putchar
*/
{
    write(1, &c, 1);
}

int 
SelectFunc(int NumA, char Ch, int NumB)
/*
    function pointer calculation function character condition branch
*/
{
    if(Ch == op_tb[0])
    {
        return 
        (SelectSUM(NumA,Ch, NumB));
    }
    else if(Ch == op_tb[1])
    {
        return 
        (SelectSUB(NumA, Ch, NumB));
    }
    else if(Ch == op_tb[2])
    {
        return 
        (SelectMUL(NumA, Ch, NumB));
    }
    else 
    {
        return 
        (SelectDIV((float)NumA, Ch, (float)NumB));
    }
}

int
CallCalc(int NumA, char Ch, int NumB)
/*
    Final conditional branch result derivation function
*/
{
    if(Ch != '/')
    {
        SelectFunc(NumA, Ch, NumB);
    } else {
        if(NumB > NumA)
        {
            DivWhereNumBGreter (NumA, Ch, NumB);
        } else /* NumA > NumB */
        {
            SelectFunc(NumA, Ch, NumB);
        }
    }
    return 
    (1);
}
