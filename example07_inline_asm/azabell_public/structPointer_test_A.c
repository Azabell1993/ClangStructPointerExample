// #include <stdio.h>

// typedef struct S
// {
//     int member;
//     int m2;
// }S;

// typedef struct Calculator {
//     int x;
//     int y;
// } CAL;

// int Add(CAL* cal)
// {
//     int x, y;
//     __asm
//     {
//         mov eax, cal
//         mov eax, [eax]cal.x
//         mov x, eax
//         mov ebx, cal
//         mov ebx, [ebx]cal.y
//         mov y, ebx
//         add eax, ebx
//         mov x, eax
//     }
//     return x;
// }

// void TestPrint(S* s)
// {
//     int m;

//     _asm {
//         mov eax, s
//         mov eax, [eax]s.m2
//         mov m, eax
//     }

//     printf("Test Function Value : %d\n", m);
// }

// int main()
// {
//     S s;
//     s.member = 10;
//     s.m2 = 20;
//     TestPrint(&s);

//     CAL cal;
//     cal.x = 20;
//     cal.y = 10;
//     printf("SUM : %d\n", Add(&cal));
// }


#include <stdio.h>
#include <stdlib.h>

typedef struct Member {


}