#include "02_if.h"

int main(int argc, char* argv)
{
    // 구조체 지역 선언
    CAL new_sum;

    // 생성자 지역 변수 선언
    new_sum.x = 10;
    new_sum.y = 20;
    new_sum.operator = '+';
    new_sum.result = 0;

    // 생성자 함수 선언
    CAL_INIT(&new_sum);

    // 객체 메서드 출력
    new_sum.INPUT(&new_sum, new_sum.x, new_sum.operator, new_sum.y, new_sum.result);
    new_sum.PUTS(&new_sum);

    // 빼기 객체
    CAL new_sub;
    new_sub.x = 60;
    new_sub.y = 20;
    new_sub.operator = '-';
    new_sub.result = 0;
    CAL_INIT(&new_sub);
    new_sub.INPUT(&new_sub, new_sub.x, new_sub.operator, new_sub.y, new_sub.result);
    new_sub.PUTS(&new_sub);

    // 곱셈 객체
    CAL new_mul;
    new_mul.x = 60;
    new_mul.y = 6;
    new_mul.operator = '*';
    new_mul.result = 0;
    CAL_INIT(&new_mul);
    new_mul.INPUT(&new_mul, new_mul.x, new_mul.operator, new_mul.y, new_mul.result);
    new_mul.PUTS(&new_mul);

    // 나눗셈 객체
    CAL new_div;
    new_div.x = 60;
    new_div.y = 6;
    new_div.operator = '/';
    new_div.result = 0;
    CAL_INIT(&new_div);
    new_div.INPUT(&new_div, new_div.x, new_div.operator, new_div.y, new_div.result);
    new_div.PUTS(&new_div);
}
