//
// Created by azabell on 2022/06/22.
//
#include <stdlib.h>
#include "compare.h"

int main(int argc, char* argv[])
{
    int numArr[10] = {8,4,2,5,3,7,10,1,6,9};

    /* bubble sort */
    bubble_sort(numArr, sizeof(numArr)/sizeof(int));

    for(int i=0; i<10; i+=1) {
        printf("%d ", numArr[i]);
    }

    puts("");

    qsort(numArr, sizeof(numArr)/sizeof(int), sizeof(int), compareFunc);

    for(int i=0; i<10; i+=1) {
        printf("%d ", numArr[i]);
    }

    puts("");

    return 0;
}