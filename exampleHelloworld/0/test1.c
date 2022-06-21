#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

static inline void __attribute__((noreturn)) Helloworld(void) {
	char Message[] = "Test Printf Hello, World!";
	char hello[] = "hello";
	char world[] = "world";
	char format[] = "%s %s\n";

	__asm {
		mov eax, offset world
		push eax
		mov eax, offset hello
		push eax
		mov eax, offset format
		push eax
		call dword ptr[printf]
		pop ebx
		pop ebx
		pop ebx
	}
}

int main(int argc, char* argv[]) {
	Helloworld();
}