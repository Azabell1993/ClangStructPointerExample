#include "lib/test.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

say_add(addFunction , int)

int main(int argc, char* argv[])
{
    int a = 20;
    int b = 40;
    addFunction add = new_addFunction();
    add.setAdd(&add, a, b);
    printf("%d", add.getAdd(&add));

    int result = add.getAdd(&add);
    printf("\n \t %d", result);
}