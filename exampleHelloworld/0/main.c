#include <stdio.h>
#include <stdlib.h>
#include "program.h"

test_hello(helloFun, char, 6)

void    init(int* e) {
    static int i = 0;
    *e = i;
    ++i;
}

int main(void) {

    helloFun he = new_helloFun();
    helloFun_name(&he,"박지우");
    helloFun_hello(&he);

    return 0;
}

