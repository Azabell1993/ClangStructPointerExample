#include <stdio.h>
#include <stdlib.h>
#include "test.h"

say_hello(hellofunc, int)

int main(int argc, char* argv[])
{
    hellofunc hello = new_hellofunc();
    hello.hello(&hello, 30);
}
