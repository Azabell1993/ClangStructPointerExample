/*
    * Azabell1993
    * 2023-02-19
*/
#include "pair.h"
#include <stdio.h>

DECLARE_PAIR(IntPair, int, int)
DEFINE_PAIR(IntPair, int, int)

int main() {
    IntPair pair = IntPair_make(1, 2);
    IntPair other_pair = IntPair_make(1, 2);
    bool equal = pair.equals(&pair, &other_pair);
    printf("%d",  pair.equals(&pair, &other_pair));
    return 0;
}