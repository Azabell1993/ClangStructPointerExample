#include <stdio.h>
#pragma warning(disable:4996)

char strInputMessage[] = "2개의 정수를 입력하십시오. : ";
char strScanf[] = "%d %d";
char strResult[] = "%d + %d = %d\n";

int main()
{
    int x, y;
    printf("%s", strInputMessage);
    scanf("%d %d", &x, &y);
    __asm {
        /*
        push offset strInputMessage
        call dword ptr printf
        add esp, 4
        lea eax, [y]
        push eax
        lea ecx, [x]
        push ecx
        push offset strScanf
        */
        call dword ptr scanf
        add esp, 0Ch
        mov eax, x
        mov ebx, y
        add eax, ebx
        push eax
        push y
        push x
        push offset strResult
        call dword ptr printf
        //add esp, 10h
    }
    exit(0);
}