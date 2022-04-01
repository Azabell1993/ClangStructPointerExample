#pragma once
#ifdef  PROGRAM_H
#define PROGRAM_H

#define testDefine(test, type)

// 유사 클래스 전역 선언
struct test;
typedef struct teststruct test;

// 전용 반복자 전역 선언
struct teststruct##namespace;
typedef struct teststruct##namespace teststruct##name;

// 반복자 유사 클래스
struct teststurct##namespace name
{
    type *ptr;

    // 유사 메서드
    double    (*SETCUL)(teststurct##namespace *);
    double    (*GETCUL)(teststurct##namespace *);
} // namespace name

// 유사 method 전역 선언
double teststurct##namespace_add(teststurct##namespace *);
double teststurct##namespace_sub(teststurct##namespace *);
double teststurct##namespace_mul(teststurct##namespace *);
double teststurct##namespace_divf(teststurct##namespace *);
// new 함수 선언
teststurct##namespace new_##teststurct##namespace(type *)

sturct teststurct
{

    double teststurct##namespace_add(const teststruct *, double operand1, const type1 operand2, const type2 operator, const type1 result);
    double teststurct##namespace_sub(const teststruct *, const type1 operand1, const type1 operand2, const type2 operator, const type1 result);
    double teststurct##namespace_mul(const teststruct *, const type1 operand1, const type1 operand2, const type2 operator, const type1 result);
    double teststurct##namespace_divf(const teststruct *, const type1 operand1, const type1 operand2, const type2 operator, const type1 result);
}

double add(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result)
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

}


#endif