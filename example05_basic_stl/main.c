#include <stdio.h>
#include <assert.h>
#include "include/array.h"

ArrayList(IntArray, int,10)

void    init(int* e) {
    static int i = 0;
    *e = i;
    ++i;
}

void    ptr(int e) {
    printf("%d ", e);
}

int main()
{
    IntArray arr = new_IntArray();
    arr.for_each_ptr(&arr, init);
    arr.for_each(&arr, ptr);

    IntArray_iterator it = arr.find(&arr, 8);
    IntArray_iterator end = arr.end(&arr);
    assert(!it.equals(&it, &end));
    printf("find %d", it.get(&it));
}

