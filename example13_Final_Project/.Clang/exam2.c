#include <stdio.h>
#include <stdarg.h>

static void printValue(char *types, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, types);

    while(types[i] != '\0')
    {
        switch(types[i])
        {
            case  'i' :
                printf("%d ", va_arg(ap, int));
                break;

            case 'd':
                printf("%f ", va_arg(ap, double));
                break;

            case 'c' :
                printf("%c ", va_arg(ap, int));
                break;

            case 's' :
                printf("%s", va_arg(ap, char*));
                break;

            default :
                break;
        }
        i+=1;
    }
    va_end(ap);

    printf("\n");
}

int main(int argc, char* argv[])
{
    //printValue("i", 10);
    printValue("i", 20);
    printValue("i", 30);
    printValue("ci", 'a', 10);
    printValue("ci", 'a', 20);
    printValue("ci", 'a', 30);
    printValue("dci", 1.234567, 'a', 10);
    printValue("dci", 1.234567, 'a', 20);
    printValue("dci", 1.234567, 'a', 30);
    printValue("sicd", "Hello World", 10, 'a', 1.234567);
    printValue("sicd", "Hello World", 20, 'a', 12.34567);
}