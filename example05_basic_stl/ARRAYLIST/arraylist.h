/*
    * Azabell1993
    * 2023-02-19
*/
#pragma once
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
    /* 함수 전방 선언 */
    static void ArrayList##_push_back(struct ArrayList* self, type value);
    static void ArrayList##_pop_back(struct ArrayList* self)      ;
    static type ArrayList##_at(const struct ArrayList* self, size_t index);
    static type* ArrayList##_data(const struct ArrayList* self);
    static size_t ArrayList##_size(const struct ArrayList* self);
    static size_t ArrayList##_capacity(const struct ArrayList* self);
    static void ArrayList##_reserve(struct ArrayList* self, size_t new_capacity);
    static void ArrayList##_resize(struct ArrayList* self, size_t new_size);
    static void ArrayList##_clear(struct ArrayList* self);
    static void ArrayList##_free(struct ArrayList* self);


    /* 비멤버 생성자 전방 선언 */
    static inline ArrayList new_##ArrayList();
#endif

#define DECLARE_ARRAY_LIST(ArrayList, type) \
                                            \
    struct ArrayList;                                                    \
    typedef struct ArrayList ArrayList;                                  \
                                                                    \
    struct ArrayList {                                                \
        type* buffer;                                               \
        size_t size;                                                \
        size_t capacity;                                            \
        void (*push_back)(struct ArrayList*, type);                      \
        void (*pop_back)(struct ArrayList*);                             \
        type (*at)(const struct ArrayList*, size_t);                     \
        type* (*data)(const struct ArrayList*);                          \
        size_t (*get_size)(const struct ArrayList*);                         \
        size_t (*get_capacity)(const struct ArrayList*);                     \
        void (*reserve)(struct ArrayList*, size_t);                      \
        void (*resize)(struct ArrayList*, size_t);                       \
        void (*clear)(struct ArrayList*);                                \
        void (*free)(struct ArrayList*);                                 \
    } ;                                                         \
                                            \
                                            \
    static void ArrayList##_push_back(struct ArrayList* self, type value) {   \
        if (self->size == self->capacity) {                         \
            size_t new_capacity = self->capacity * 2 + 1;            \
            self->buffer = (type*)realloc(self->buffer, new_capacity * sizeof(type)); \
            self->capacity = new_capacity;                          \
        }                                                            \
        self->buffer[self->size++] = value;                         \
    }                                                                \
                                                                     \
    static void ArrayList##_pop_back(struct ArrayList* self) {                 \
        if (self->size > 0) {                                        \
            --self->size;                                            \
        }                                                            \
    }                                                                \
                                                                     \
    static type ArrayList##_at(const struct ArrayList* self, size_t index) {   \
        if (index >= self->size) {                                   \
            return (type){0};                                        \
        }                                                            \
        return self->buffer[index];                                  \
    }                                                                \
                                                                     \
    static type* ArrayList##_data(const struct ArrayList* self) {              \
        return self->buffer;                                         \
    }                                                                \
                                                                     \
    static size_t ArrayList##_size(const struct ArrayList* self) {             \
        return self->size;                                           \
    }                                                                \
                                                                     \
    static size_t ArrayList##_capacity(const struct ArrayList* self) {         \
        return self->capacity;                                       \
    }                                                                \
                                                                     \
    static void ArrayList##_reserve(struct ArrayList* self, size_t new_capacity) { \
        if (new_capacity > self->capacity) {                         \
            self->buffer = (type*)realloc(self->buffer, new_capacity * sizeof(type)); \
            self->capacity = new_capacity;                          \
        }                                                            \
    }                                                                \
                                                                     \
    static void ArrayList##_resize(struct ArrayList* self, size_t new_size) {  \
        if (new_size > self->capacity) {                             \
            ArrayList##_reserve(self, new_size);                          \
        }                                                            \
        self->size = new_size;                                        \
    }                                                                   \
                                                                        \
    static void ArrayList##_clear(struct ArrayList* self) {                    \
        self->size = 0;                                              \
    }                                                                \
    \
    static void ArrayList##_free(struct ArrayList* self) {                     \
        free(self->buffer);                                          \
        self->buffer = NULL;                                         \
        self->size = self->capacity = 0;                             \
    }                                                                \
                                            \
    static inline ArrayList new_##ArrayList();                           \
    \
    static inline ArrayList new_##ArrayList() {                                \
        return (ArrayList) {                                              \
            .buffer = NULL,                                          \
            .size = 0,                                               \
            .capacity = 0,                                           \
            .push_back = ArrayList##_push_back,                           \
            .pop_back = ArrayList##_pop_back,                             \
            .at = ArrayList##_at,                                         \
            .data = ArrayList##_data,                                     \
            .get_size = ArrayList##_size,                            \
            .get_capacity = ArrayList##_capacity,                             \
            .reserve = ArrayList##_reserve,                               \
            .resize = ArrayList##_resize,                                 \
            .clear = ArrayList##_clear,                                   \
            .free = ArrayList##_free                                      \
        };                                                           \
    }
#ifdef __cplusplus
}
#endif //__cplusplus
#endif