/*
    * Azabell1993
    * 2023-02-19
*/
#pragma once
#ifndef PAIR_H
#define PAIR_H

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
    /* 함수 전방 선언 */
    static void Vector##_push_back(Vector* self, type value);
    static void Vector##_pop_back(Vector* self);
    static type Vector##_at(const Vector* self, size_t index);
    static type* Vector##_get_data(const Vector* self);
    static size_t Vector##_get_size(const Vector* self);
    static size_t Vector##_get_capacity(const Vector* self);
    static void Vector##_reserve(Vector* self, size_t new_capacity);
    static void Vector##_clear(Vector* self);
    static void Vector##_free(Vector* self);
    static void Vector##_resize(Vector* self, size_t new_size);

    /* 비멤버 생성자 전방 선언 */
    static inline Vector new_##Vector();
#endif


#define DECLARE_PAIR(Pair, T1, T2) \
    struct Pair; \
    typedef struct Pair Pair; \
    struct Pair { \
        T1 first; \
        T2 second; \
        bool (*equals)(const Pair* self, const Pair* other); \
    }; \
    static bool Pair##_equals(const Pair* self, const Pair* other) { \
        return self->first == other->first && self->second == other->second; \
    } \

#define DEFINE_PAIR(Pair, T1, T2) \
    static inline Pair Pair##_make(T1 first, T2 second) { \
        return (Pair) { \
            .first = first, \
            .second = second, \
            .equals = &Pair##_equals, \
        }; \
    }

#ifdef __cplusplus
}
#endif //__cplusplus
#endif