/*
    * Azabell1993
    * 2023-02-19
*/
#pragma once
#ifndef VECTOR_H
#define VECTOR_H

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

#define DECLARE_VECTOR(Vector, type) \
    struct Vector; \
    typedef struct Vector Vector; \
    struct Vector { \
        type* data; \
        size_t size; \
        size_t capacity; \
        void (*push_back)(Vector* self, type value); \
        void (*pop_back)(Vector* self); \
        type (*at)(const Vector* self, size_t index); \
        type* (*get_data)(const Vector* self); \
        size_t (*get_size)(const Vector* self); \
        size_t (*get_capacity)(const Vector* self); \
        void (*reserve)(Vector* self, size_t new_capacity); \
        void (*resize)(Vector* self, size_t new_size); \
        void (*clear)(Vector* self); \
        void (*free)(Vector* self); \
    }; \
    static void Vector##_push_back(Vector* self, type value) { \
        if (self->size == self->capacity) { \
            size_t new_capacity = (self->capacity == 0 ? 1 : self->capacity * 2); \
            self->data = (type*)realloc(self->data, new_capacity * sizeof(type)); \
            assert(self->data != NULL && "Memory allocation error!"); \
            self->capacity = new_capacity; \
        } \
        self->data[self->size++] = value; \
    } \
    static void Vector##_pop_back(Vector* self) { \
        if (self->size > 0) { \
            --self->size; \
        } \
    } \
    static type Vector##_at(const Vector* self, size_t index) { \
        assert(index < self->size && "Index out of range!"); \
        return self->data[index]; \
    } \
    static type* Vector##_get_data(const Vector* self) { \
        return self->data; \
    } \
    static size_t Vector##_get_size(const Vector* self) { \
        return self->size; \
    } \
    static size_t Vector##_get_capacity(const Vector* self) { \
        return self->capacity; \
    } \
    static void Vector##_reserve(Vector* self, size_t new_capacity) { \
        if (new_capacity > self->capacity) { \
            self->data = (type*)realloc(self->data, new_capacity * sizeof(type)); \
            assert(self->data != NULL && "Memory allocation error!"); \
            self->capacity = new_capacity; \
        } \
    } \
    static void Vector##_resize(Vector* self, size_t new_size) { \
        if (new_size > self->capacity) { \
            Vector##_reserve(self, new_size); \
        } \
        self->size = new_size; \
    } \
    static void Vector##_clear(Vector* self) { \
        self->size = 0; \
    } \
    static void Vector##_free(Vector* self) { \
        free(self->data); \
        self->data = NULL; \
        self->size = self->capacity = 0; \
    } \
    static inline Vector new_##Vector() { \
        return (Vector) { \
            .data = NULL, \
            .size = 0,      \
            .capacity = 0,           \
            .get_size = &Vector##_get_size,          \
            .get_capacity = &Vector##_get_capacity, \
            .push_back = &Vector##_push_back, \
            .pop_back = &Vector##_pop_back, \
            .at = &Vector##_at,      \
            .reserve = &Vector##_reserve, \
            .resize = &Vector##_resize, \
            .clear = &Vector##_clear, \
            .free = &Vector##_free, \
        }; \
    }

#define declare_Vector(type) \
    declare_Vector_struct(type) \
    declare_Vector_functions(type)

#define define_Vector(type) \
    define_Vector_struct(type) \
    define_Vector_functions(type)
#ifdef __cplusplus
}
#endif //__cplusplus
#endif