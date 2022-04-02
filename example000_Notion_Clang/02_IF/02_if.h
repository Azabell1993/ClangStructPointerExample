#pragma once
#ifndef IF_H
#define IF_H

#include <stdio.h>

// 구조체 구성
typedef struct _Calculator {
    // 필드 값
    const char operator; 
    double x;
    double y;
    double result;
    /* 연산자 캐릭터는 유동적이므로 아래에 지역/전역 함수선언 메서드에도 const를 사용하지 않는다.*/

    // 입,출력 메서드 
	double (*INPUT)(struct _Calculator *this, const double x,const double y,double result,char operator);
    double (*PUTS)(const struct _Calculator *this);
} CAL;

// 함수 전역 선언
double     CAL_INPUT       (struct _Calculator *this, const double x, const double y, double result,char operator);
double     CAL_RESULT      (const struct _Calculator *this);
void       CAL_INIT       (CAL *this);

// 입력 메서드
double /* 메서드 자료형 */  
CAL_INPUT /* 입력 메서드 함수명 */
(struct _Calculator *this, const double x, const double y, double result,char operator) /* 입력 메서드 피라메타에는 구조체 포인터와 필드 인자들을 넣어준다. */
{
    if (this->operator == '+')
        return this -> result = this -> x + this -> y;
    else if(this->operator == '-')
        return this -> result = this -> x - this -> y;
    else if(this->operator == '/')
        return this -> result = this -> x / this -> y;
    else if(this->operator == '*')
        return this -> result = this -> x * this -> y;
    else
        return puts("예외처리");
}

// 출력 메서드
double /* 메서드 자료형 */
CAL_RESULT /* 출력 메서드 함수명 */
(const struct _Calculator *this) /* 출력 메서드 피라메타에는 구조체 포인터만 명시한다 .*/
{
    return
    (
        printf("%.2f %c %.2f = %.2f\n",
        this -> x,
        this -> operator,
        this -> y,
        this -> result)
    );
}

// 생성자 선언 함수
void CAL_INIT(CAL *this) /* 이미 구조체안에 포인터로 선언이 되어있으므로 구조체 포인터만 명시한다. */
{
    this -> INPUT   = CAL_INPUT;
    this -> PUTS    = CAL_RESULT;
}

#endif