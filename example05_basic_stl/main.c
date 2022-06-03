#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "include/program.h"

say_hello(hellofunc, int)
ArrayList()
int main(int argc, char* argv[])
{
    hellofunc hello = new_hellofunc();
    hello.sethello(&hello, 30);
    hello.gethello(&hello);

    GString *my_string = g_string_new("This Hello world is %d chars long\n");
    g_print(my_string->str, my_string->len);
    g_string_free(my_string, TRUE);
}