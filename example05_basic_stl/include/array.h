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
    static __attribute__((visibility("default"))) arraylist arraylist##_clone(const arraylist *);
    static __attribute__((visibility("default"))) arraylist##_iterator arraylist##_begin(arraylist *);
    static __attribute__((visibility("default"))) arraylist##_iterator arraylist##_end(arraylist *);
    static __attribute__((visibility("default"))) arraylist##_iterator arraylist##_find(const arraylist *, const type);
    static __attribute__((visibility("default"))) arraylist##_iterator arraylist##_find_by(const arraylist *, int (*)(const type *));
    static __attribute__((visibility("default"))) size_t arraylist##_indexof(const arraylist *, const type);
    static __attribute__((visibility("default"))) size_t arraylist##_indexof_by(const arraylist *, int (*)(const type *));
    static __attribute__((visibility("default"))) bool arraylist##_contains(const arraylist *, const type);
    static __attribute__((visibility("default"))) bool arraylist##_contains_by(const arraylist *, int (*)(const type *));
    static __attribute__((visibility("default"))) arraylist##_iterator arraylist##_bfind(const arraylist *, const type);
    static __attribute__((visibility("default"))) arraylist##_iterator arraylist##_bfind_by(const arraylist *, const type *, int (*)(const type *, const type *));
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

    /*비멤버 new 함수 선언*/
    arraylist##_iterator new_##arraylist##_iterator(type *);
    /*비멤버 함수*/
    arraylist new_##arraylist(void);

#endif

#define ArrayList(arraylist, type, length)  \
                                                                                                                            \
    /*배열 유사클래스 전방선언*/                                                                                 \
    struct arraylist;                                                                                                        \
    typedef struct arraylist arraylist;                                                                                       \
                                                                                                                            \
    /*전용 반복자 유사클래스 전방선언*/                                                                       \
    struct arraylist##_iterator;                                                                                             \
    typedef struct arraylist##_iterator arraylist##_iterator;                                                                 \
                                                                                                                            \
    /*반복자 유사클래스.*/                                                                                          \
    struct arraylist##_iterator                                                                                              \
    {                                                                                                                       \
        type *ptr;                                                                                                          \
                                                                                                                            \
        /*반복을 하거나 역반복을 수행*/                                                                         \
        void (*next)(arraylist##_iterator *);                                                                                \
        void (*prev)(arraylist##_iterator *);                                                                                \
                                                                                                                            \
        /*반복자에 담긴 값이나 그 포인터를 가져옴.*/                                                       \
        type (*get)(const arraylist##_iterator *);                                                                           \
        type *(*get_ptr)(arraylist##_iterator *);                                                                            \
                                                                                                                            \
        /*두 반복자를 비교. 같으면 true*/                                                                         \
        bool (*equals)(const arraylist##_iterator *, const arraylist##_iterator *);                                           \
    };                                                                                                                      \
    /*유사 메서드 선언*/                                                                                             \
    static __attribute__((visibility("default"))) void arraylist##_iterator_next(arraylist##_iterator *);                                                                   \
    static __attribute__((visibility("default"))) void arraylist##_iterator_prev(arraylist##_iterator *);                                                                   \
    static __attribute__((visibility("default"))) type arraylist##_iterator_get(const arraylist##_iterator *);                                                              \
    static __attribute__((visibility("default"))) type *arraylist##_iterator_get_ptr(arraylist##_iterator *);                                                               \
    static __attribute__((visibility("default"))) bool arraylist##_iterator_equals(const arraylist##_iterator *, const arraylist##_iterator *);                              \
    /*비멤버 new 함수 선언*/                                                                                         \
    arraylist##_iterator new_##arraylist##_iterator(type *);                                                                  \
                                                                                                                            \
    /*실체화되는 배열 유사클래스*/                                                                              \
    struct arraylist                                                                                                         \
    {                                                                                                                       \
        type data[length];                                                                                                  \
                                                                                                                            \
        /*길이를 가져옴*/                                                                                             \
        size_t (*size)(const arraylist *);                                                                                   \
                                                                                                                            \
        /*요소 액세스*/                                                                                                \
        type (*get)(const arraylist *, size_t);                                                                              \
        type *(*get_ptr)(arraylist *, size_t);                                                                               \
        const type *(*get_cptr)(const arraylist *, size_t);                                                                  \
                                                                                                                            \
        arraylist (*clone)(const arraylist *);                                                                                \
                                                                                                                            \
        /*반복자를 반환*/                                                                                             \
        arraylist##_iterator (*begin)(arraylist *);                                                                           \
        arraylist##_iterator (*end)(arraylist *);                                                                             \
                                                                                                                            \
        /*선형탐색 후 찾은 위치의 반복자를 반환*/                                                           \
        arraylist##_iterator (*find)(const arraylist *, const type);                                                          \
        arraylist##_iterator (*find_by)(const arraylist *, int (*)(const type *));                                            \
                                                                                                                            \
        /*선형탐색 후 해당하는 인덱스를 반환*/                                                               \
        size_t (*indexof)(const arraylist *, const type);                                                                    \
        size_t (*indexof_by)(const arraylist *, int (*)(const type *));                                                      \
                                                                                                                            \
        /*선형탐색으로 포함 여부를 확인*/                                                                      \
        bool (*contains)(const arraylist *, const type);                                                                     \
        bool (*contains_by)(const arraylist *, int (*)(const type *));                                                       \
                                                                                                                            \
        /*이진탐색 후 찾은 위치의 반복자를 반환*/                                                           \
        arraylist##_iterator (*bfind)(const arraylist *, const type);                                                         \
        arraylist##_iterator (*bfind_by)(const arraylist *, const type *, int (*)(const type *, const type *));               \
                                                                                                                            \
        /*이진탐색 후 해당하는 인덱스를 반환*/                                                               \
        size_t (*bindexof)(const arraylist *, const type);                                                                   \
        size_t (*bindexof_by)(const arraylist *, const type *, int (*)(const type *, const type *));                         \
                                                                                                                            \
        /*이진탐색으로 포함 여부를 확인*/                                                                      \
        bool (*bcontains)(const arraylist *, const type);                                                                    \
        bool (*bcontains_by)(const arraylist *, const type *, int (*)(const type *, const type *));                          \
                                                                                                                            \
        /*해당 값이나 값의 포인터로, 배열을 채움*/                                                          \
        void (*fill)(arraylist *, const type);                                                                               \
        void (*fill_ptr)(arraylist *, const type *);                                                                         \
                                                                                                                            \
        /*정렬용*/                                                                                                       \
        void (*sort)(arraylist *);                                                                                           \
        void (*sort_by)(arraylist *, int (*)(const type *, const type *));                                                   \
                                                                                                                            \
        /*콜백함수를 받아서 범위기반 루프를 돎*/                                                            \
        void (*for_each)(const arraylist *, void (*)(const type));                                                           \
        void (*for_each_ptr)(arraylist *, void (*)(type *));                                                                 \
        void (*for_each_cptr)(const arraylist *, void (*)(const type *));                                                    \
    };                                                                                                                      \
    /*유사 메서드 선언*/                                                                                             \
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
    static __attribute__((visibility("default"))) void arraylist##_for_each_cptr(const arraylist *, void (*)(const type *));                                                \
                                            \
    /*비멤버 함수*/                                                                                                    \
    arraylist new_##arraylist(void);                                                                                          \
                                                                                                                            \
    /*배열 메서드 정의.*/                                                                                            \
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
            else if (0 < comp_mid) /*key가 중간치보다 큼*/                                                           \
                --tail, head = middle;                                                                                      \
            else /*key가 중간치보다 작음*/                                                                          \
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
                .for_each_cptr = arraylist##_for_each_cptr};                                                                 \
        return temp;                                                                                                        \
    }                                                                                                                       \
                                                                                                                            \
    /*반복자 메서드 정의*/                                                                                          \
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
    bool arraylist##_iterator_equals(const arraylist##_iterator *self, const arraylist##_iterator *other)                      \
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