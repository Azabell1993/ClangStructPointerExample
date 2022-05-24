//
// Created by azabell on 2022/05/25.
//

#ifndef CALCULATOR_C_STR_H
#define CALCULATOR_C_STR_H

#include <stdlib.h>
#include <stdbool.h>
\
#define decl_Calculator(declname, type)\
\
struct declname;\
typedef struct declname declname;\
\
struct declname##_iterator;\
typedef struct declname##_iterator declname##_iterator;\
\
struct declname##_iterator\
{\
int num1;\
int num2;\
type *ptr;\
\
int (*add)(declname##_iterator *);\
int (*sub)(declname##_iterator *);\
type (*set)(const declname##_iterator *);\
type (*get)(declname##_iterator *);\
\
};\
int declname##_iterator_add(declname##_iterator *);\
int declname##_iterator_sub(declname##_iterator *);\
type declname##_iterator_set(const declname##_iterator *);\
type *declname##_iterator_get(declname##_iterator *);\
declname##_iterator new_##declname##_iterator(type *);\
\
struct declname\
{\
    type num1;\
    type num2;\
    type (*set)(const declname *);\
    type (*get)(declname *);\
};\
\
type declname##_set(const declname *, size_t);\
type declname##_get(declname *, size_t);\
declname new_##declname(void);\
\
type declname##_set(const declname *self)\
{\
    self->num1;                        \
    self->num2;                         \
}\
type declname##_get(declname *self)\
{\
return (self->num1+self->num2);\
}\
\
declname new_##declname(void)\
{\
    static declname temp =\
            {\
                .set = declname##_set,\
                .get = declname##_get};\
                                       \
                return temp;\
            }                          \
                                       \
    int declname##_iterator_add(declname##_iterator *self)\
    {\
        return self->num1 + self->num2;    \
    }\
\
    int declname##_iterator_sub(declname##_iterator *self)\
    {\
        return self->num1 - self->num2;\
    }\
\
    declname##_iterator new_##declname##_iterator(type *p)\
    {\
        declname##_iterator it =\
        {\
            p,                      \
            declname##_iterator_add,\
            declname##_iterator_sub};\
            return it;\
        }\

#endif //CALCULATOR_C_STR_H
