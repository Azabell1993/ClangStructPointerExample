#include <stdio.h>

// 구조체 구성
typedef struct _Hello {
    // 필드 값

    // 입,출력 메서드 
		// 입력할 인자가 없으므로 출력할 메서드만 선언
    void (*HELLO)();
} HELLOWORLD;

// 함수 전역 선언
void HELLO_PRINT(); /* 피라메타 비어두기 */
void HELLO_INIT(HELLOWORLD *this); /* 구조체 포인터 */

// 출력 메서드
void/* 메서드 자료형 */  
HELLO_PRINT /* 메서드 이름 */ ( /* 넣을 인자 값이 없음 */  )
{
    // printf 대체 출력 함수
    puts("Hello World");
}

// 생성자 선언 함수
void HELLO_INIT(HELLOWORLD *this)
{
		// 아래 두가지 표현식이 동일하게 작동
    // this -> HELLO = HELLO_PRINT;
    (*this).HELLO = HELLO_PRINT;
}

void main(int argc, char* argv)
{
    // 구조체 지역 선언
    HELLOWORLD HELLO;
    // 생성자 선언
    HELLO_INIT(&HELLO);

    // 아래 동일한 출력 함수
    // HELLO_PRINT(&HELLO);
    HELLO.HELLO();
}