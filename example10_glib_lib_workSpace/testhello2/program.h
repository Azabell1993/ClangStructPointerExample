#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-non-const-parameter"
#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
#define NORETERN _attribute_ ((_noreturn_))
    static __attribute__((visibility("default"))) void helloworld##_set_hello(helloworld *self, int age);
    static __attribute__((visibility("default"))) int helloworld##_get_hello(helloworld *self);
#endif

#define say_hello(helloworld, type)                                                                         \
                                                                                                            \
    struct helloworld;                                                                                      \
    typedef struct helloworld helloworld;                                                                   \
                                                                                                            \
    struct helloworld                                                                                       \
    {                                                                                                       \
        type age;                                                                                           \
                                                                                                            \
        void (*sethello)(helloworld *, type);                                                               \
        int (*gethello)(const helloworld *);                                                                \
    };                                                                                                      \
                                                                                                            \
    static __attribute__((visibility("default"))) void helloworld##_set_hello(helloworld *self, type age);  \
    static __attribute__((visibility("default"))) int helloworld##_get_hello(const helloworld *self);       \
                                                                                                            \
    helloworld new_##helloworld(void);                                                                      \
                                                                                                            \
    static __attribute__((visibility("default"))) void helloworld##_set_hello(helloworld *self, type age)   \
    {                                                                                                       \
        self -> age = age;                                                                                  \
    }                                                                                                       \
                                                                                                            \
    static __attribute__((visibility("default"))) int helloworld##_get_hello(const helloworld *self)        \
    {                                                                                                       \
        return printf("my age : %d\nHello World!!!!!!\n", self->age);                                       \
    }                                                                                                       \
                                                                                                            \
    helloworld new_##helloworld(void)                                                                       \
    {                                                                                                       \
        static helloworld temp =                                                                            \
            {                                                                                               \
                .age = 0,                                                                                   \
                .sethello = helloworld##_set_hello,                                                         \
                .gethello = helloworld##_get_hello,                                                         \
            };                                                                                              \
        return temp;                                                                                        \
    }
#endif
#pragma clang diagnostic pop





