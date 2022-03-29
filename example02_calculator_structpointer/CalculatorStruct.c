#include "CalculatorStruct.h"

int main()
{
    // 첫번째 객체 생성
    struct _CALC_DATA test;
    // 필드 -> 객체의 데이터가 저장되는 곳
    test.operand1 = 10;
    test.operand2 = 30;
    test.operator = '+'; 
    test.result=0; 
    // 생성자 호출 -> 객체 생성 시 초기화 역할 담당
    Init(&test);
    // 출력 / 메서드 -> 객체의 동작에 해당사는 실행 블록
    test.SETCUL(&test, test.operand1, test.operand2, test.operator, test.result);
    test.GETCUL(&test);
    //소멸자
    Destory(&test);

    // 두번째 객체 생성
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

    // 세번째 객체 생성
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
    
    // 네번째 객체 생성
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