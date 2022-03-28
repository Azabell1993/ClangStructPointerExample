#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char  op_tb[4] = {'+', '-', '*', '/'};

struct _CALC_DATA {
    double operand1;
    double operand2;
    char operator;
    double result;

    double    (*SETCUL)(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result);
    double     (*GETCUL)(const struct _CALC_DATA *this);
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

}

int main()
{
    // 첫 번째 클래스 선언
    struct _CALC_DATA test;
    test.operand1 = 10;
    test.operand2 = 30;
    test.operator = '+';
    test.result=0; 
    // 생성자 호출
    Init(&test);
    // 출력
    test.SETCUL(&test, test.operand1, test.operand2, test.operator, test.result);
    test.GETCUL(&test);
    //소멸자
    Destory(&test);

    // 두번째 클래스 선언
    struct _CALC_DATA test2;
    test2.operand1 = 110;
    test2.operand2 = 100;
    test2.operator = '-';
    test2.result = 0; 
    // 생성자 호출
    Init(&test2);
    // 출력
    test2.SETCUL(&test2, test2.operand1, test2.operand2, test2.operator, test2.result);
    test2.GETCUL(&test2);
    //소멸자
    Destory(&test2);

    // 세 번째 클래스 선언
    struct _CALC_DATA test3;
    test3.operand1 = 30;
    test3.operand2 = 100;
    test3.operator = '*';
    test3.result = 0; 
    // 생성자 호출
    Init(&test3);
    // 출력
    test3.SETCUL(&test3, test3.operand1, test3.operand2, test3.operator, test3.result);
    test3.GETCUL(&test3);
    //소멸자
    Destory(&test3);
    
    // 네 번째 클래스 선언
    struct _CALC_DATA test4;
    test4.operand1 = 20;
    test4.operand2 = 100;
    test4.operator = '/';
    test4.result=0; 
    // 생성자 호출
    Init(&test4);
    // 출력
    test4.SETCUL(&test4, test4.operand1, test4.operand2, test4.operator, test4.result);
    test4.GETCUL(&test4);
    //소멸자
    Destory(&test4);
}