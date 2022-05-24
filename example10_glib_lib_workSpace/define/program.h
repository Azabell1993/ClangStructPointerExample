#ifndef C_STL_ARRAY_H
#define C_STL_ARRAY_H

#include <stdlib.h>
#include <stdbool.h>

#define decl_Calculator(declname, type)                                                                                  \
                                                                                                                        \
    struct declname;                                                                                                        \
    typedef struct declname declname;                                                                                       \
                                                                                                                      \
    struct declname##_iterator;                                                                                             \
    typedef struct declname##_iterator declname##_iterator;                                                                 \
                                                                                                                         \
    struct declname##_iterator                                                                                              \
    {                                                                                                                       \
        int num1;                                                                                                           \
        int num2;                                                                                                           \
        type *ptr;                                                                                                          \
                                                                                                                            \
        int (*add)(declname##_iterator *);                                                                                \
        int (*sub)(declname##_iterator *);                                                                                                                                                                                                    \
                                                                                                                            \
        type (*set)(const declname##_iterator *);                                                                           \
        type *(*get)(declname##_iterator *);                                                                            \
                                                                                                                       \
    };                                                                                                                      \
    int declname##_iterator_add(declname##_iterator *);                                                                   \
    int declname##_iterator_sub(declname##_iterator *);                                                                   \
    type declname##_iterator_set(const declname##_iterator *);                                                              \
    type *declname##_iterator_get(declname##_iterator *);                                                                   \
    declname##_iterator new_##declname##_iterator(type *);                                                                  \
                                                                                                                            \
    struct declname                                                                                                         \
    {                                                                                                                       \
        type (*set)(const declname *, size_t);                                                                              \
        type *(*get)(declname *, size_t);                                                                                   \
    };                                                                                                                      \
                                                                                                                            \
    type declname##_set(const declname *, size_t);                                                                          \
    type *declname##_get(declname *, size_t);                                                                           \
    declname new_##declname(void);                                                                                          \
                                                                                                                            \
    type declname##_set(const declname *self)                                                                 \
    {                                                                                                                            \
        int result = self->num1+self->num2;                                                                      \
    }                                                                                                                       \
    type *declname##_get(declname *self, size_t index)                                                                  \
    {                                                                                                                       \
        return (self->num1+self->num2);                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    declname new_##declname(void)                                                                                           \
    {                                                                                                                       \
        static declname temp =                                                                                              \
            {                                                                                                               \
                .set = declname##_set,                                                                                      \
                .get = declname##_get,                                                                                  \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    int declname##_iterator_add(declname##_iterator *self)                                                                \
    {                                                                                                                       \
        return self->num1 + self->num2;    \
    }                                                                                                                       \
                                                                                                                            \
    int declname##_iterator_sub(declname##_iterator *self)                                                                \
    {                                                                                                                       \
        return self->num1 - self->num2;                                                                                       \
    }                                                                                                                       \
    declname##_iterator new_##declname##_iterator(type *p)                                                                  \
    {                                                                                                                       \
        declname##_iterator it =                                                                                            \
            {                                                                                                               \
                p,                                                                                                          \
                declname##_iterator_add,                                                                                   \
                declname##_iterator_sub,                                                                                   \
        return it;                                                                                                          \
    }

#endif
