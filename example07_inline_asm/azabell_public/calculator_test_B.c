#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

char strInputMessage[] = "2개의 정수를 입력하십시오. : ";
char addMessage[] = "ADD RESULT : ";
char subMessage[] = "SUB RESULT : ";
char strScanf[] = "%d %d";
char strResultADD[] = "%d + %d = %d\n";
char strResultSUB[] = "%d - %d = %d\n";
char strResultDIV[] = "%d / %d = %d\n";
char strResultMUL[] = "%d * %d = %d\n";

int    add(int x, int y);
int    sub(int x, int y);
int    divf(int x, int y);
int    mul(int x, int y);

int    add(int x, int y)
{
    __asm {
        add esp, 20
        lea eax, [y]
        push eax
        lea ecx, [x]
        push ecx
        push offset[strScanf]

        push offset[addMessage]
        call dword ptr[printf]
        call dword ptr[scanf]
        add esp, 0Ch
        mov eax, [x]
        mov ebx, [y]
        add eax, ebx
        push eax
        push[y]
        push[x]
        push offset[strResultADD]
        call dword ptr[printf]
    }

    return;
}

int    sub(int x, int y)
{
    __asm {
        add esp, 20
        lea eax, [y]
        push eax
        lea ecx, [x]
        push ecx
        push offset[strScanf]

        push offset[subMessage]
        call dword ptr[printf]
        add esp, 0ch
        mov eax, [x]
        mov ebx, [y]
        sub eax, ebx
        push eax
        push[y]
        push[x]
        push offset[strResultSUB]
        call dword ptr[printf]
    }

    return;
}

int    divf(int x, int y)
{
    __asm {
        add esp, 20
        lea eax, [y]
        push eax
        lea ecx, [x]
        push ecx
        push offset[strScanf]

        push offset[subMessage]
        call dword ptr[printf]
        add esp, 0ch
        mov eax, [x]
        mov ecx, [y]
        sub edx, edx
        div ecx
        push eax
        push[y]
        push[x]
        push offset[strResultDIV]
        call dword ptr[printf]
    }

    return;
}

int    mul(int x, int y)
{
    __asm {
        add esp, 20
        lea eax, [y]
        push eax
        lea ecx, [x]
        push ecx
        push offset[strScanf]

        push offset[subMessage]
        call dword ptra[printf]
        add esp, 0ch
        mov eax, [x]
        mov ebx, [y]
        mul ebx
        push eax
        push[y]
        push[x]
        push offset[strResultMUL]
        call dword ptr[printf]
    }

    return;
}

int main()
{
    int x, y;
    printf("%s", strInputMessage);
    scanf("%d %d", &x, &y);
    add(x, y);

    printf("%s", strInputMessage);
    scanf("%d %d", &x, &y);
    sub(x, y);

    printf("%s", strInputMessage);
    scanf("%d %d", &x, &y);
    divf(x, y);

    printf("%s", strInputMessage);
    scanf("%d %d", &x, &y);
    mul(x, y);

    return (0);
}
