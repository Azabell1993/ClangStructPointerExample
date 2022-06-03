#ifndef EXAMPLE05_BASIC_STL_PROGRAM_H
#define EXAMPLE05_BASIC_STL_PROGRAM_H

#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

#define class struct
#define public static __attribute__((visibility("default")))
#define private static __attribute__((visibility("hidden")))

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
    public void helloworld##_set_hello(helloworld *, type);
    public int helloworld##_get_hello(helloworld *);
#endif

#define ArrayList(arraylist, type)                                                                          \
#define say_hello(helloworld, type)                                                                         \
                                                                                                            \
    class helloworld;                                                                                      \
    typedef class helloworld helloworld;                                                                   \
                                                                                                            \
    class helloworld                                                                                       \
    {                                                                                                       \
        type age;                                                                                           \
                                                                                                            \
        void (*sethello)(helloworld *, type);                                                               \
        int (*gethello)(const helloworld *);                                                                \
    };                                                                                                      \
                                                                                                            \
    helloworld new_##helloworld(void);                                                                      \
                                                                                                            \
    public void helloworld##_set_hello(helloworld *self, type age)        									\
    {                                                                                                       \
        self -> age = age;                                                                                  \
    }                                                                                                       \
                                                                                                            \
    public int helloworld##_get_hello(const helloworld *self)        										\
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
    }                                                                                                       \
                                                                                                            \
                                                                                                            \
    class arraylist;                                                                                        \
    typedef class arraylist arraylist;                                                                      \
                                                                                                            \
    class arraylistType;                                                                                    \
    typedef arraylistType arraylistNode;                                                                    \
                                                                                                            \
    class arraylistType {                                                                                   \
        type data;                                                                                          \
    };                                                                                                      \
                                                                                                            \
    class arraylist                                                                                         \
    {                                                                                                       \
        type element;                                                                                       \
        type currentElement;                                                                                \
        arraylist* node;                                                                                    \
                                                                                                            \
        void (*DeleteArrayList)(arraylist **);                                                              \
        int (*IsArrayListFull)(arraylist *);                                                                \
        int (*AddALLElement)(arraylist *, int, arraylistType element);                                      \
        int (*RemoveALLElement)(arraylist *, int);                                                          \
        void (*DisplayArraylist)(arraylist *);                                                              \
        int(*GetARrayList)(arraylist *);                                                                    \
        arraylistNode* (*GetALLElement)(arraylist *, int);                                                  \
    };                                                                                                      \
                                                                                                            \
    public void deleteArrayList(arraylist *pnode) {                                                         \
        if(pnode == NULL *nbode == NULL) {
            return ;
        }
        free(((*pnode)->p))
    }





    #endif
#endif //EXAMPLE05_BASIC_STL_PROGRAM_H
