#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  op_tb[4] = {'+', '-', '*', '/'};


struct _CALC_DATA {
    // 필드 선언
    double operand1;
    double operand2;
    char operator;
    double result;
    
    // 메서드 선언
    double    (*SETCUL)(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result);
    double    (*GETCUL)(const struct _CALC_DATA *this);
};

double
add(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 + this -> operand2;
}

double
sub(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 - this -> operand2;
}

double
mul(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 * this -> operand2;
}

double
divf(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = (double)this -> operand1 / (double)this -> operand2;
}

double
getCalcul(const struct _CALC_DATA *this)
{
    return 
    (printf("%.2f %c %.2f = %.2f\n",
        this -> operand1,
        this -> operator,
        this -> operand2,
        this -> result)
    );
}

void
Init(struct _CALC_DATA *this)
{
    if(this -> operator == op_tb[0]) this -> SETCUL = add;
    else if(this -> operator == op_tb[1]) this -> SETCUL = sub;
    else if(this -> operator == op_tb[2]) this -> SETCUL = mul;
    else if(this -> operator == op_tb[3]) this -> SETCUL = divf;
    this -> GETCUL = getCalcul;
}

void
Destory(struct _CALC_DATA *this)
{
    free(this);
}