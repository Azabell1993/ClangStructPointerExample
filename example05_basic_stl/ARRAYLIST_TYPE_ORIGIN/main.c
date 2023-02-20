#include <stdio.h>
#include <assert.h>
#include "array.h"

ArrayList(IntArray, int,10)

int main()
{
    IntArray arr = new_IntArray();
    arr.for_each_ptr(&arr, init);
    arr.for_each(&arr, print);

    IntArray_iterator it = arr.find(&arr, 8);
    IntArray_iterator end = arr.end(&arr);
    assert(!it.equals(&it, &end));
    printf("find %d", it.get(&it));

    return EXIT_SUCCESS;
}

