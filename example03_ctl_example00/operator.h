#pragma once
#ifndef OPERATOR_H
#define OPERATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
char  op_tb[4] = {'+', '-', '*', '/'};

#define operatorStack(operatorname, double, char);

#ifdef _stack_header file
struct operatorname;
typedef struct operatorname operatorname;

struct operatorname##calcu;
typedef struct operatorname##calcu operatorname##calcu;

struct operatorname##calcu {
    type data;
    operatorname##calcu* pbtr;
};

struct operatorname {
    // operatorname##calcu const RV;
    // const size_t RT;
    operatorname##calcu const double operand1;
    operatorname##calcu const double operand2;
    operatorname##calcu const char operator;
    operatorname##calcu const double result;

    // 메서드 선언
    double    (*SETCUL)(operator *this, double operand1, double operand2, char operator, double result);
    double    (*GETCUL)(const operator *this);
}

double  operatorname##add(operator *this, double, double, char, double);
double  operatorname##sub(operator *this, double, double, char, double);
double  operatorname##mul(operator *this, double, double, char, double);
double  operatorname##divf(operator *this, double, double, char, double);

double
operatorname##add(operator *this, double operand1, double operand2, char operator, double result)
{
    // operatorname##add *ptr = (operatorname##add*)malloc(sizeof(operatorname##add));
    // ptr -> operand1 = this -> operand1;
    // ptr -> operand2 = this -> operand2;
    // ptr -> result = this -> result;
    // (*(operatorname##add **)&this -> R) = ptr;
    // ++*(size_t *)&this -> RT;
    return this -> result = this -> operand1 + this -> operand2;
}

double
operatorname##sub(operator *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 - this -> operand2;
}

double
operatorname##mul(operator *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 * this -> operand2;
}

double
operatorname##divf(operator *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = (double)this -> operand1 / (double)this -> operand2;
}

operatorname new_##operatorname(void);
operatorname new_##operatorname(void)
{
    operatorname temp = {
        .add = operator##add,
        .sub = operator##sub,
        .mul = operator##mul,
        .divf = operator##divf
    };
    RV = NULL;

    return temp;
}

double
operatorname##mul(const operator *this)
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
Init(operator *this)
{
    if(this -> operator == op_tb[0]) this -> SETCUL = add;
    else if(this -> operator == op_tb[1]) this -> SETCUL = sub;
    else if(this -> operator == op_tb[2]) this -> SETCUL = mul;
    else if(this -> operator == op_tb[3]) this -> SETCUL = divf;
    this -> GETCUL = getCalcul;
}

void
Destory(operator *this)
{

}

#endif
#endif