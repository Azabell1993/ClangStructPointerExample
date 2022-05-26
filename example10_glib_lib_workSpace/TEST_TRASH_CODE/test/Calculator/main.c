#include <stdio.h>
#include "c_str.h"

decl_Calculator(SumLib, int)

int main() {
    printf("Hello, World!\n");
    SumLib sum = new_SumLib();
    SumLib_iterator it = sum.add(&sum, 20, 20);
    printf("result : ", it.get(&sum));
    return 0;
}