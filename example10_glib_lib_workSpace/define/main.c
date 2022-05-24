#include <stdio.h>
#include <stdlib.h>
#include "program.h"

decl_Calculator(SUM, int)

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
/*
 *
int main()
{
    PERSON* this = PersonPtr.create(100, 100, 98, "박지우");

    puts("이 메세지가 뜨면 성공입니다.");
    printf("%s\n", this->hello(this));

    this->destory(this);
}
 */