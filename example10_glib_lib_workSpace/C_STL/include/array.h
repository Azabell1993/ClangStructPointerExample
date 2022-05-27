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

    /* ArrayList */
    ArrayList*		createArrayList(int maxElementCount);	// arraylist 할당 및 생성
    static __attribute__((visibility("default"))) void			deleteArrayList(ArrayList** pList);		// arraylist free
    static __attribute__((visibility("default"))) int				isArrayListFull(ArrayList* pList);		// arraylist가 가득 찼는지 확인

    static __attribute__((visibility("default"))) int				addALElement(ArrayList* pList, int position, ArrayListNode element);	// arraylist node 추가
    static __attribute__((visibility("default"))) int				removeALElement(ArrayList* pList, int position);	// arraylist node 제거
    ArrayListNode*	getALElement(ArrayList* pList, int position);		// arraylist node 가져오기

    static __attribute__((visibility("default"))) void			displayArrayList(ArrayList* pList);		// arraylist 출력
    static __attribute__((visibility("default"))) void			clearArrayList(ArrayList* pList);		// arraylist 초기화
    static __attribute__((visibility("default"))) int				getArrayListLength(ArrayList* pList);	// arraylist에 들어가있는 element의 길이 확인

    /* Linked List */
    LinkedList	*createLinkedList();										 		// linkedlist 생성
    static __attribute__((visibility("default"))) int			addLLElement(LinkedList *pList, int position, ListNode element);	// 노드 추가
    static __attribute__((visibility("default"))) int			removeLLElement(LinkedList *pList, int position);					// 노드 제거
    ListNode	*getLLElement(LinkedList *pList, int position);						 // 노드 가져오기

    static __attribute__((visibility("default"))) void		displayLinkedList(LinkedList *lst);		// linkedlist 출력
    static __attribute__((visibility("default"))) void		clearLinkedList(LinkedList *pList);		// linkedlist 초기화
    static __attribute__((visibility("default"))) int			getLinkedListLength(LinkedList *pList);	// linkedlist 노드의 개수 확인
    static __attribute__((visibility("default"))) void		deleteLinkedList(LinkedList **pList);	// linkedlist free
#endif
/*
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
*/
typedef struct ArrayListNodeType
{
    int	data;
} ArrayListNode;

typedef struct ArrayListType
{
    int				maxElementCount;		// 최대 원소 개수
    int				currentElementCount;	// 현재 원소의 개수
    ArrayListNode*	pElement;				// 원소 저장을 위한 1차원 배열
} ArrayList;

typedef struct ListNodeType
{
    int					data;
    struct ListNodeType	*pLink;
}	ListNode;

typedef struct LinkedListType
{
    int			currentElementCount; // 현재 저장된 원소의 개수
    ListNode	headerNode;	 // 헤더 노드(Header Node)
}	LinkedList;






#endif //C_STL_ARRAY_H
