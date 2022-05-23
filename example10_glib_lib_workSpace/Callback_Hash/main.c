#include "main.h"

int main(int argc, char* argv[])
{
    int start_argc = 0;
    puts("반복할 싸이클을 입력하시오.");
    if(scanf("%d", &start_argc)) {
        if (start_argc != '\0') {
            HelloWorld();

            LoopTest(start_argc);

            setCallback(printHelloWorld);
            callCallback();
        } else {
            HelloWorldDefault();
        }
    }
    return EXIT_SUCCESS;
}
