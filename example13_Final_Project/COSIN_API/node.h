#pragma once
#ifndef _NODE_H_
#define _NODE_H_

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
    


#ifdef __cplusplus
}
#endif
#endif