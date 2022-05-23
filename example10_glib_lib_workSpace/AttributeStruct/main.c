#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "program.h"

int main() {
    int age = 10;
    HE *helloObj = new_Hello(age);
    (*helloObj).He_Printf(helloObj);
    return 0;
}