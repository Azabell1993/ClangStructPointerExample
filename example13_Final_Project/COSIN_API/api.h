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
    extern public void ListHead##_set_Node(ListHead *A, ListHead *B, ListHead *C);
    extern public int ListHead##_get_Node(ListHead *L);

    /* 비멤버 생성자 전방 선언 */
    ListHead new_##ListHead(void);
#endif

#define vector_mul(ListHead, ListNode)

    struct ListNode;
    typedef struct ListNode;

    struct ListHead;
    typedef struct ListHead;

    class ListNode {
        class ListHead {
            ListNode* head;

            void    (*setNode)(ListHead *);
            int     (*getNode)(const ListHead *)
        };
        float coef;
        int expo;

        ListNode* link;  
        void    (*setNode)(ListHead *);
        int     (*getNode)(const ListHead *)
    };

    // class ListHead {
    //     ListNode* head;

    //     void    (*setNode)(ListHead *);
    //     int     (*getNode)(const ListHead *)
    // };

    ListHead* create_Linked_List(void) {
        Listhead* L;
        L = (ListHead*)malloc(sizeof(ListHead));
        L -> head = NULL;
        return (L);
    }

    void appendTerm(Listhead* L, float coef, int expo) {
        Listnode* newnode;
        Listnode* p;
        newnode -> coef = coef;
        newnode -> expo = expo;
        newnode -> link = NULL;

        if(L->head == NULL) {
            L->head = newnode;
            return 1;
        } else {
            P = L -> head;
            while( p-> link != NULL) {
                p = p->link;
            }
            p->link = newnode;
        }
    }

    public void ListHead##_set_Node(ListHead *A, ListHead *B, ListHead *C) {
        Listnode* pA = A -> head;
        Listnode* pB = B -> head;
        float sum; // 다항식 계수 곱
        int exposum;  // 다항식 합

        while(pA) {
            while (pB) {
                sum = pA -> coef * pB -> coef;
                exposum = pA -> expo + pB -> expo;
                appendTerm(C, sum, exposum);
                pB = pB -> link;
            }
            pA = pA -> link;
            pB = pB -> head;
        }
    } 

    public int ListHead##_get_Node(ListHead *L) {
        Listnode* p = L -> head;
        for (; p; p->link) {
            printf("%3.0fx^%d", p->coef, p->expo);
            if(p->link != NULL) 
                printf(" +");
        }
    }

    ListHead new_##ListHead(void) { static ListHead temp = 
        {
            ListNode * p = L -> NULL,
            .setNode = ListHead##_set_Node,
            .getNode = ListHead##_get_Node,

        };
        return (
            temp
        );
    }
#ifdef __cplusplus
}
#endif
#endif