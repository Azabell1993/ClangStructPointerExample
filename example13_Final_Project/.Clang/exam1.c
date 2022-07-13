#include <stdio.h>
#include <stdarg.h>

void printNuymbers(int args, ...)
{
    va_list ap;                     // 가변인자 포인터

    va_start(ap, args);             // 가변인자 목록 포인터 설정
    for(int i=0; i<args; i+=1) {    // 가변인자 개수만큼 반복
        int num = va_arg(ap, int);  // int크기만큼 가변 인자 목록 포인터에서 값을 가져옴, ap를 int 크기만큼 순방향으로 이동 
        printf("%d ", num);         // 가변인자 값 출력
    }
    va_end(ap);                     //  가변 인자 목록 포인터를 NULL로 초기화

    printf("\n");                   // 줄바꿈
}

int main()
{
    printNuymbers(1, 10);           // 인수 개수 1개
    printNuymbers(2, 10, 20);       // 인수 개수 2개
    printNuymbers(3, 10,20,30);     // 인수 개수 3개
    printNuymbers(4, 10,20,30,40);  // 인수 개수 4개

    return (0);
}