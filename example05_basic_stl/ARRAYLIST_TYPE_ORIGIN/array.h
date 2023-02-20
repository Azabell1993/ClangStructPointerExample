//
// Created by azabell on 2022/05/26.
//
#pragma once
#ifndef C_STL_ARRAY_H
#define C_STL_ARRAY_H

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

    /*static __attribute__((visibility("default"))) void helloworld##_set_hello(helloworld *self, int age);*/
    /*static __attribute__((visibility("default"))) int helloworld##_get_hello(helloworld *self);*/

    static __attribute__((visibility("default"))) void arraylist##_iterator_next(arraylist##_iterator *);
    static __attribute__((visibility("default"))) void arraylist##_iterator_prev(arraylist##_iterator *);
    static __attribute__((visibility("default"))) type arraylist##_iterator_get(const arraylist##_iterator *);
    static __attribute__((visibility("default"))) type *arraylist##_iterator_get_ptr(arraylist##_iterator *);
    static __attribute__((visibility("default"))) bool arraylist##_iterator_equals(const arraylist##_iterator *, const arraylist##_iterator *);
    static __attribute__((visibility("default"))) size_t arraylist##_size(const arraylist *);
    static __attribute__((visibility("default"))) type arraylist##_get(const arraylist *, size_t);
    static __attribute__((visibility("default"))) type *arraylist##_get_ptr(arraylist *, size_t);
    static __attribute__((visibility("default"))) const type *arraylist##_get_cptr(const arraylist *, size_t);
    static __attribute__((visibility("default"))) size_t arraylist##_indexof(const arraylist *, const type);
    static __attribute__((visibility("default"))) size_t arraylist##_indexof_by(const arraylist *, int (*)(const type *));
    static __attribute__((visibility("default"))) bool arraylist##_contains(const arraylist *, const type);
    static __attribute__((visibility("default"))) bool arraylist##_contains_by(const arraylist *, int (*)(const type *));
    static __attribute__((visibility("default"))) size_t arraylist##_bindexof(const arraylist *, const type);
    static __attribute__((visibility("default"))) size_t arraylist##_bindexof_by(const arraylist *, const type *, int (*)(const type *, const type *));
    static __attribute__((visibility("default"))) bool arraylist##_bcontains(const arraylist *, const type);
    static __attribute__((visibility("default"))) bool arraylist##_bcontains_by(const arraylist *, const type *, int (*)(const type *, const type *));
    static __attribute__((visibility("default"))) void arraylist##_fill(arraylist *, const type);
    static __attribute__((visibility("default"))) void arraylist##_fill_ptr(arraylist *, const type *);
    static __attribute__((visibility("default"))) void arraylist##_sort(arraylist *);
    static __attribute__((visibility("default"))) void arraylist##_sort_by(arraylist *, int (*)(const type *, const type *));
    static __attribute__((visibility("default"))) void arraylist##_for_each(const arraylist *, void (*)(const type));
    static __attribute__((visibility("default"))) void arraylist##_for_each_ptr(arraylist *, void (*)(type *));
    static __attribute__((visibility("default"))) void arraylist##_for_each_cptr(const arraylist *, void (*)(const type *));

    arraylist##_iterator arraylist##_bfind(const arraylist *, const type);
    arraylist##_iterator arraylist##_bfind_by(const arraylist *, const type *, int (*)(const type *, const type *));

    arraylist arraylist##_clone(const arraylist *);
    arraylist##_iterator arraylist##_begin(arraylist *);
    arraylist##_iterator arraylist##_end(arraylist *);
    arraylist##_iterator arraylist##_find(const arraylist *, const type);
    arraylist##_iterator arraylist##_find_by(const arraylist *, int (*)(const type *));

    arraylist##_iterator new_##arraylist##_iterator(type *);
    arraylist new_##arraylist(void);

    static inline __attribute__((visibility("default")))    void    arraylist##_init(type* e);
    static inline __attribute__((visibility("default")))    void    arraylist##_print(int e);
#endif

#define ArrayList(arraylist, type, length)  \
                                                                                                                            \
    struct arraylist;                                                                                                        \
    typedef struct arraylist arraylist;                                                                                       \
                                                                                                                            \
    struct arraylist##_iterator;                                                                                             \
    typedef struct arraylist##_iterator arraylist##_iterator;                                                                 \
                                                                                                                            \
    struct arraylist##_iterator                                                                                              \
    {                                                                                                                       \
        type *ptr;                          \
                                            \
        void (*next)(arraylist##_iterator *);                                                                                \
        void (*prev)(arraylist##_iterator *);                                                                                \
        type (*get)(const arraylist##_iterator *);                                                                           \
        type *(*get_ptr)(arraylist##_iterator *);                                                                            \
        bool (*equals)(const arraylist##_iterator *, const arraylist##_iterator *);                                           \
    };                                      \
                                            \
    static __attribute__((visibility("default"))) void arraylist##_iterator_next(arraylist##_iterator *);                                                                   \
    static __attribute__((visibility("default"))) void arraylist##_iterator_prev(arraylist##_iterator *);                                                                   \
    static __attribute__((visibility("default"))) type arraylist##_iterator_get(const arraylist##_iterator *);                                                              \
    static __attribute__((visibility("default"))) type *arraylist##_iterator_get_ptr(arraylist##_iterator *);                                                               \
    static __attribute__((visibility("default"))) bool arraylist##_iterator_equals(const arraylist##_iterator *, const arraylist##_iterator *);\
    arraylist##_iterator new_##arraylist##_iterator(type *);                                                                  \
                                                                                                                            \
    struct arraylist                                                                                                         \
    {                                                                                                                       \
        type data[length];                                                                                                  \
                                                                                                                            \
        size_t (*size)(const arraylist *);                                                                                   \
                                                                                                                            \
        type (*get)(const arraylist *, size_t);                                                                              \
        type *(*get_ptr)(arraylist *, size_t);                                                                               \
        const type *(*get_cptr)(const arraylist *, size_t);                                                                  \
                                                                                                                            \
        arraylist (*clone)(const arraylist *);                                                                                \
                                                                                                                            \
        arraylist##_iterator (*begin)(arraylist *);                                                                           \
        arraylist##_iterator (*end)(arraylist *);                                                                             \
                                                                                                                            \
        arraylist##_iterator (*find)(const arraylist *, const type);                                                          \
        arraylist##_iterator (*find_by)(const arraylist *, int (*)(const type *));                                            \
                                                                                                                            \
        size_t (*indexof)(const arraylist *, const type);                                                                    \
        size_t (*indexof_by)(const arraylist *, int (*)(const type *));                                                      \
                                                                                                                            \
        bool (*contains)(const arraylist *, const type);                                                                     \
        bool (*contains_by)(const arraylist *, int (*)(const type *));                                                       \
                                                                                                                            \
        arraylist##_iterator (*bfind)(const arraylist *, const type);                                                         \
        arraylist##_iterator (*bfind_by)(const arraylist *, const type *, int (*)(const type *, const type *));               \
                                                                                                                            \
        size_t (*bindexof)(const arraylist *, const type);                                                                   \
        size_t (*bindexof_by)(const arraylist *, const type *, int (*)(const type *, const type *));                         \
                                                                                                                            \
        bool (*bcontains)(const arraylist *, const type);                                                                    \
        bool (*bcontains_by)(const arraylist *, const type *, int (*)(const type *, const type *));                          \
                                                                                                                            \
        void (*fill)(arraylist *, const type);                                                                               \
        void (*fill_ptr)(arraylist *, const type *);                                                                         \
                                                                                                                            \
        void (*sort)(arraylist *);                                                                                           \
        void (*sort_by)(arraylist *, int (*)(const type *, const type *));                                                   \
                                                                                                                            \
        void (*for_each)(const arraylist *, void (*)(const type));                                                           \
        void (*for_each_ptr)(arraylist *, void (*)(type *));                                                                 \
        void (*for_each_cptr)(const arraylist *, void (*)(const type *));                                                    \
    };                                      \
                                            \
    /*?œ ?‚¬ ë©”ì„œ?“œ ?„ ?–¸*/                                                                                             \
    static __attribute__((visibility("default"))) size_t arraylist##_size(const arraylist *);                                                                               \
    static __attribute__((visibility("default"))) type arraylist##_get(const arraylist *, size_t);                                                                          \
    static __attribute__((visibility("default"))) type *arraylist##_get_ptr(arraylist *, size_t);                                                                           \
    static __attribute__((visibility("default"))) const type *arraylist##_get_cptr(const arraylist *, size_t);                                                              \
    arraylist arraylist##_clone(const arraylist *);                                                                            \
    arraylist##_iterator arraylist##_begin(arraylist *);                                                                       \
    arraylist##_iterator arraylist##_end(arraylist *);                                                                         \
    arraylist##_iterator arraylist##_find(const arraylist *, const type);                                                      \
    arraylist##_iterator arraylist##_find_by(const arraylist *, int (*)(const type *));                                        \
    static __attribute__((visibility("default"))) size_t arraylist##_indexof(const arraylist *, const type);                                                                \
    static __attribute__((visibility("default"))) size_t arraylist##_indexof_by(const arraylist *, int (*)(const type *));                                                  \
    static __attribute__((visibility("default"))) bool arraylist##_contains(const arraylist *, const type);                                                                 \
    static __attribute__((visibility("default"))) bool arraylist##_contains_by(const arraylist *, int (*)(const type *));                                                   \
    arraylist##_iterator arraylist##_bfind(const arraylist *, const type);                                                     \
    arraylist##_iterator arraylist##_bfind_by(const arraylist *, const type *, int (*)(const type *, const type *));           \
    static __attribute__((visibility("default"))) size_t arraylist##_bindexof(const arraylist *, const type);                                                               \
    static __attribute__((visibility("default"))) size_t arraylist##_bindexof_by(const arraylist *, const type *, int (*)(const type *, const type *));                     \
    static __attribute__((visibility("default"))) bool arraylist##_bcontains(const arraylist *, const type);                                                                \
    static __attribute__((visibility("default"))) bool arraylist##_bcontains_by(const arraylist *, const type *, int (*)(const type *, const type *));                      \
    static __attribute__((visibility("default"))) void arraylist##_fill(arraylist *, const type);                                                                           \
    static __attribute__((visibility("default"))) void arraylist##_fill_ptr(arraylist *, const type *);                                                                     \
    static __attribute__((visibility("default"))) void arraylist##_sort(arraylist *);                                                                                       \
    static __attribute__((visibility("default"))) void arraylist##_sort_by(arraylist *, int (*)(const type *, const type *));                                               \
    static __attribute__((visibility("default"))) void arraylist##_for_each(const arraylist *, void (*)(const type));                                                       \
    static __attribute__((visibility("default"))) void arraylist##_for_each_ptr(arraylist *, void (*)(type *));                                                             \
    static __attribute__((visibility("default"))) void arraylist##_for_each_cptr(const arraylist *, void (*)(const type *));\
    static inline __attribute__((visibility("default")))    void    init(int* e);                                 \
    static inline __attribute__((visibility("default")))    void    print(int e);\
                                            \
    arraylist new_##arraylist(void);                                                                                          \
                                                                                                                            \
    static __attribute__((visibility("default"))) size_t arraylist##_size(const arraylist *self)                                                                            \
    {                                                                                                                       \
        return length;                                                                                                      \
    }                                                                                                                       \
    static __attribute__((visibility("default"))) type arraylist##_get(const arraylist *self, size_t index)                                                                 \
    {                                                                                                                       \
        return self->data[index];                                                                                           \
    }                                                                                                                       \
    static __attribute__((visibility("default"))) type *arraylist##_get_ptr(arraylist *self, size_t index)                                                                  \
    {                                                                                                                       \
        return &(self->data[index]);                                                                                        \
    }                                                                                                                       \
    static __attribute__((visibility("default"))) const type *arraylist##_get_cptr(const arraylist *self, size_t index)                                                     \
    {                                                                                                                       \
        return &(self->data[index]);                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) int arraylist##_comparer(const void *lhs, const void *rhs)                                                               \
    {                                                                                                                       \
        return *(type *)lhs - *(type *)rhs;                                                                                 \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_sort(arraylist *self)                                                                                    \
    {                                                                                                                       \
        qsort(self->data, length, sizeof(type), arraylist##_comparer);                                                       \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_sort_by(arraylist *self, int (*comp)(const type *, const type *))                                        \
    {                                                                                                                       \
        qsort(self->data, length, sizeof(type), (int (*)(const void *, const void *))comp);                                 \
    }                                                                                                                       \
                                                                                                                            \
    arraylist arraylist##_clone(const arraylist *self)                                                                         \
    {                                                                                                                       \
        arraylist temp = new_##arraylist();                                                                                   \
        for (int i = 0; i < length; ++i)                                                                                    \
            temp.data[i] = self->data[i];                                                                                   \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    arraylist##_iterator arraylist##_begin(arraylist *self)                                                                    \
    {                                                                                                                       \
        return new_##arraylist##_iterator(self->data);                                                                       \
    }                                                                                                                       \
                                                                                                                            \
    arraylist##_iterator arraylist##_end(arraylist *self)                                                                      \
    {                                                                                                                       \
        return new_##arraylist##_iterator(self->data + length);                                                              \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_fill(arraylist *self, const type value)                                                                  \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            self->data[i] = value;                                                                                          \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_fill_ptr(arraylist *self, const type *value)                                                             \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            self->data[i] = *value;                                                                                         \
    }                                                                                                                       \
                                                                                                                            \
    arraylist##_iterator arraylist##_find(const arraylist *self, const type key)                                               \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return new_##arraylist##_iterator((type *)&(self->data[i]));                                                 \
                                                                                                                            \
        return self->end((arraylist *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    arraylist##_iterator arraylist##_find_by(const arraylist *self, int (*comp)(const type *))                                 \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return new_##arraylist##_iterator((type *)&(self->data[i]));                                                 \
                                                                                                                            \
        return self->end((arraylist *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    arraylist##_iterator arraylist##_bfind(const arraylist *self, const type key)                                              \
    {                                                                                                                       \
        type *p = bsearch(&key, self->data, length, sizeof(type), arraylist##_comparer);                                     \
        if (self->data <= p && p <= &(self->data[length - 1]))                                                              \
            return new_##arraylist##_iterator(p);                                                                            \
        return self->end((arraylist *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) int arraylist##_bsearch(const arraylist *self, const type *key, int (*comp)(const type *, const type *))                  \
    {                                                                                                                       \
        int head = 0;                                                                                                       \
        int tail = length - 1;                                                                                              \
        int middle;                                                                                                         \
                                                                                                                            \
        while (1)                                                                                                           \
        {                                                                                                                   \
            int comp_head = comp(key, &self->data[head]);                                                                   \
            int comp_tail = comp(key, &self->data[tail]);                                                                   \
            if (comp_head < 0 || comp_tail > 0)                                                                             \
                return length;                                                                                              \
            if (comp_head == 0)                                                                                             \
                return head;                                                                                                \
            if (comp_tail == 0)                                                                                             \
                return tail;                                                                                                \
                                                                                                                            \
            middle = (tail - head) / 2;                                                                                     \
            int comp_mid = comp(key, &self->data[middle]);                                                                  \
            if (comp_mid == 0)                                                                                              \
                return middle;                                                                                              \
            else if (0 < comp_mid) /*keyê°? ì¤‘ê°„ì¹˜ë³´?‹¤ ?¼*/                                                           \
                --tail, head = middle;                                                                                      \
            else /*keyê°? ì¤‘ê°„ì¹˜ë³´?‹¤ ?‘?Œ*/                                                                          \
                ++head, tail = middle;                                                                                      \
        }                                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    arraylist##_iterator arraylist##_bfind_by(const arraylist *self, const type *key, int (*comp)(const type *, const type *)) \
    {                                                                                                                       \
        int index = arraylist##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < length)                                                                                   \
            return new_##arraylist##_iterator((type *)&self->data[index]);                                                   \
        return self->end((arraylist *)&self);                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) size_t arraylist##_indexof(const arraylist *self, const type key)                                                         \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return i;                                                                                                   \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) size_t arraylist##_indexof_by(const arraylist *self, int (*comp)(const type *))                                           \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return i;                                                                                                   \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) size_t arraylist##_bindexof(const arraylist *self, const type key)                                                        \
    {                                                                                                                       \
        type *p = bsearch(&key, self->data, length, sizeof(type), arraylist##_comparer);                                     \
        if (self->data <= p && p <= &(self->data[length - 1]))                                                              \
            return p - self->data;                                                                                          \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) size_t arraylist##_bindexof_by(const arraylist *self, const type *key, int (*comp)(const type *, const type *))           \
    {                                                                                                                       \
        int index = arraylist##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < length)                                                                                   \
            return index;                                                                                                   \
        return length;                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) bool arraylist##_contains(const arraylist *self, const type key)                                                          \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (self->data[i] == key)                                                                                       \
                return 1;                                                                                                   \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) bool arraylist##_contains_by(const arraylist *self, int (*comp)(const type *))                                            \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            if (comp(&self->data[i]))                                                                                       \
                return 1;                                                                                                   \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) bool arraylist##_bcontains(const arraylist *self, const type key)                                                         \
    {                                                                                                                       \
        type *p = bsearch(&key, self->data, length, sizeof(type), arraylist##_comparer);                                     \
        if (self->data <= p && p <= &(self->data[length - 1]))                                                              \
            return 1;                                                                                                       \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) bool arraylist##_bcontains_by(const arraylist *self, const type *key, int (*comp)(const type *, const type *))            \
    {                                                                                                                       \
        int index = arraylist##_bsearch(self, key, comp);                                                                    \
        if (0 <= index && index < length)                                                                                   \
            return 1;                                                                                                       \
        return 0;                                                                                                           \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_for_each(const arraylist *self, void (*f)(const type))                                                   \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            f(self->data[i]);                                                                                               \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_for_each_ptr(arraylist *self, void (*f)(type *))                                                         \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            f(&self->data[i]);                                                                                              \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_for_each_cptr(const arraylist *self, void (*f)(const type *))                                            \
    {                                                                                                                       \
        for (int i = 0; i < length; ++i)                                                                                    \
            f(&self->data[i]);                                                                                              \
    }                                                                                                                       \
                                                                                                                            \
    static inline __attribute__((visibility("default"))) void init(type* e) {                                    \
        static int i = 0;                                                                                                   \
        *e = i;                                                                                                             \
        ++i;                                                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    static inline __attribute__((visibility("default"))) void print(type e) {                                               \
        printf("%d ", e);                                                                                                   \
    }                                       \
                                            \
    arraylist new_##arraylist(void)                                                                                           \
    {                                                                                                                       \
        static arraylist temp =                                                                                              \
            {                                                                                                               \
                .size = arraylist##_size,                                                                                    \
                .get = arraylist##_get,                                                                                      \
                .get_ptr = arraylist##_get_ptr,                                                                              \
                .get_cptr = arraylist##_get_cptr,                                                                            \
                .sort = arraylist##_sort,                                                                                    \
                .sort_by = arraylist##_sort_by,                                                                              \
                .clone = arraylist##_clone,                                                                                  \
                .begin = arraylist##_begin,                                                                                  \
                .end = arraylist##_end,                                                                                      \
                .fill = arraylist##_fill,                                                                                    \
                .fill_ptr = arraylist##_fill_ptr,                                                                            \
                .find = arraylist##_find,                                                                                    \
                .find_by = arraylist##_find_by,                                                                              \
                .bfind = arraylist##_bfind,                                                                                  \
                .bfind_by = arraylist##_bfind_by,                                                                            \
                .indexof = arraylist##_indexof,                                                                              \
                .indexof_by = arraylist##_indexof_by,                                                                        \
                .bindexof = arraylist##_bindexof,                                                                            \
                .bindexof_by = arraylist##_bindexof_by,                                                                      \
                .contains = arraylist##_contains,                                                                            \
                .contains_by = arraylist##_contains_by,                                                                      \
                .bcontains = arraylist##_bcontains,                                                                          \
                .bcontains_by = arraylist##_bcontains_by,                                                                    \
                .for_each = arraylist##_for_each,                                                                            \
                .for_each_ptr = arraylist##_for_each_ptr,                                                                    \
                .for_each_cptr = arraylist##_for_each_cptr};                                                                \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    /*ë°˜ë³µ? ë©”ì„œ?“œ ? •?˜*/                                                                                          \
    static __attribute__((visibility("default"))) void arraylist##_iterator_next(arraylist##_iterator *self)                                                                \
    {                                                                                                                       \
        ++(self->ptr);                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) void arraylist##_iterator_prev(arraylist##_iterator *self)                                                                \
    {                                                                                                                       \
        --(self->ptr);                                                                                                      \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) type arraylist##_iterator_get(const arraylist##_iterator *self)                                                           \
    {                                                                                                                       \
        return *(self->ptr);                                                                                                \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) type *arraylist##_iterator_get_ptr(arraylist##_iterator *self)                                                            \
    {                                                                                                                       \
        return self->ptr;                                                                                                   \
    }                                                                                                                       \
                                                                                                                            \
    static __attribute__((visibility("default"))) bool arraylist##_iterator_equals(const arraylist##_iterator *self, const arraylist##_iterator *other)                      \
    {                                                                                                                       \
        return self->ptr == other->ptr;                                                                                     \
    }                                                                                                                       \
                                                                                                                                \
    arraylist##_iterator new_##arraylist##_iterator(type *p)                                                                  \
    {                                                                                                                       \
        arraylist##_iterator it =                                                                                            \
            {                                                                                                               \
                p,                                                                                                          \
                arraylist##_iterator_next,                                                                                   \
                arraylist##_iterator_prev,                                                                                   \
                arraylist##_iterator_get,                                                                                    \
                arraylist##_iterator_get_ptr,                                                                                \
                arraylist##_iterator_equals};                                                                                \
        return it;                                                                                                          \
    }


#endif