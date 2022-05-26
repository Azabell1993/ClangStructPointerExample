#ifndef PROGRAM_H
#define PROGRAM_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define test_hello(helloStruct, type, length)          \
          \
struct helloStruct;          \
typedef struct helloStruct helloStruct;          \
          \
struct helloStruct##_iterator;          \
typedef struct helloStruct##_iterator helloStruct##_iterator;          \
          \
struct helloStruct##_iterator {          \
    type *ptr;          \
          \
void (*next)(helloStruct##_iterator *);          \
};          \
          \
void helloStruct##_iterator_next(helloStruct##_iterator *);          \
static void helloStruct##_name(const helloStruct *, void(*)(const type)); \
static void helloStruct##_hello(const helloStruct *);\
helloStruct##_iterator new_##helloStruct##_iterator(type *);          \
          \
struct helloStruct {          \
    type name[length];          \
          \
    void (*HELLO)(const helloStruct *);          \
          \
};          \
          \
          \
helloStruct new_##helloStruct(void);          \
          \
static void helloStruct##_name(const helloStruct *this, void(*f)(const type))          \
{          \
    for(int i=0; i<length; ++i)          \
        f(this->name[i]);          \
}          \
          \
static void helloStruct##_hello(const helloStruct *this)          \
{          \
    puts("hello world!");          \
}          \
                                                       \
 helloStruct new_##helloStruct(void) {          \
    static helloStruct temp =                          \
    {          \
            .name  = helloStruct##_name,          \
            .hello = helloStruct##_hello };          \
    return temp;          \
}          \
\
type helloStruct##_iterator_get_name(const helloStruct##_iterator * this) {\
    return *(this->name);          \
}          \
          \
type helloStruct##_iterator_get_hello(const helloStruct##_iterator * this) {          \
    return puts("hello world!");          \
}          \
          \
helloStruct##_iterator new_##helloStruct##_iterator(type *p) {      \
    helloStruct##_iterator this = {          \
            p,          \
            helloStruct##_iterator_get_name,          \
            helloStruct##_iterator_get_hello          \
        };          \
        return this;          \
}          \

#endif
