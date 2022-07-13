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
    /* 함수 전방 선언 */
    extern public void addFunction##_set_Add(addFunction *, type, type);
    extern public int addFunction##_get_Add(const addFunction *);

    /* 비멤버 생성자 전방 선언 */
    addFunction new_##addFunction(void);
#endif

#define say_add(addFunction, int)                                                                           \
                                                                                                            \
    class addFunction;                                                                                      \
    typedef class addFunction addFunction;                                                                  \
                                                                                                            \
    class addFunction                                                                                       \
    {                                                                                                       \
        /* 필드 변수 선언 */                                                                                   \
        int num1;                                                                                           \
        
        int num2;                                                                                           \
                                                                                                            \
        /* 캡슐화를 돕는 구조체 포인터 전방에 선언해주고 후방에는 피라메터로 함수 포인터와 지역 인수들을 선언해준다.*/                \
        /* 피라메타의 선언이 짧아지고 쉬워졌다. */                                                                   \
        void (*setAdd)(addFunction *, int, int);                                                            \
        int (*getAdd)(const addFunction *);                                                                 \
    };                                                                                                      \
                                                                                                            \
    public void addFunction##_set_Add(addFunction *this, int num1, int num2)                                \
    {                                                                                                       \
        this -> num1 = num1;                                                                                \
        this -> num2 = num2;                                                                                \
    }                                                                                                       \
                                                                                                            \
    public int addFunction##_get_Add(const addFunction *this)                                               \
    {                                                                                                       \
        int result = 0;                                                                                     \
        result = this->num1 + this->num2;                                                                   \
        /*return printf("my result : %d\n\n", result);*/                                                    \
        return result;                                                                                      \
    }                                                                                                       \
                                                                                                            \
    addFunction new_##addFunction(void)                                                                     \
    {                                                                                                       \
    static addFunction temp =                                                                               \
            {                                                                                               \
                .num1 = 0,                                                                                  \
                .num2 = 0,                                                                                  \
                .setAdd = addFunction##_set_Add,                                                            \
                .getAdd = addFunction##_get_Add,                                                            \
            };                                                                                              \
        return temp;                                                                                        \
    }
#ifdef __cplusplus
}
#endif //__cplusplus
#endif
