#pragma once
#ifndef ASMTEST_H
#define ASMTEST_H

#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <memory.h>

#define SYSTEM_BIT  32

// ���α׷����� ����� ���ڿ��� ���� ������ ����
typedef const char* STRING;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned long long QWORD;

#if SYSTEM_BIT == 32
typedef DWORD INT;
#elif
typedef QWORD INT;
#endif

// ���α׷����� ����� ���� ���ν����� ������ ����
#define PROTO(proc)     static INT proc();
// ���α׷����� ����� �ܺ� ���ν����� ������ ����
#define EXTERN(proc)    INT proc();

// ���ν����� �ʱ�ȭ
INT proc_init();
// ȣ�� ���ν����� �����ϱ� ���� ���ν����� ����
INT proc_retn();
// ���α׷����� �ֿܼ� ������ ����ϴ� �Լ��� ����
INT print_int();
// ���α׷����� �ֿܼ� ���ڿ��� ����ϴ� �Լ��� ����
INT print_str();

#define MAX_MEMORY_LEN  100


BYTE m[MAX_MEMORY_LEN];
INT a, b, c, d;
INT sp = MAX_MEMORY_LEN, bp = MAX_MEMORY_LEN;
INT flag = 0;

INT ip = 0;
jmp_buf _ipArray[10];

jmp_buf _ip;

extern BYTE m[MAX_MEMORY_LEN];
extern INT a, b, c, d;
extern INT sp, bp;

extern INT flag;
enum FLAG {
    FLAG_SIGNED = 1,
    FLAG_ZERO = 1 << 2
};

// ���ν����� ���� ������ ����
#define PROC(proc_name)         INT proc_name() { proc_init();
// ���ν����� ���� ������ ����
#define ENDP                    _end_proc: proc_retn(); return 0; }

#define PUSH(param)             { \
    INT *p; \
    sp -= 4; \
    p = (INT *)(m + sp); \
    *p = (INT)(param); \
}
#define POP(param)              { \
    INT *p; \
    p = (INT *)(m + sp); \
    sp += 4; \
    (param) = *p; \
};

#define MOVL(dst, src)          { (dst) = (INT)(src); };
#define ADD(dst, src)           { (dst) += (INT)(src); }
#define SUB(dst, src)           { (dst) -= (INT)(src); }
#define MUL(dst, src)           { (dst) *= (INT)(src); }
#define DIV(dst, src)           { (dst) /= (INT)(src); }

#define JMP(lbl)                { goto lbl; }

#define CMP(p1, p2)             { \
    flag |= ((p1 == p2) ? FLAG_ZERO : ~FLAG_ZERO); \
};
#define JZ(lbl)                 if (flag & FLAG_ZERO) { goto lbl; }
#define JNZ(lbl)                if (~flag & FLAG_ZERO) { goto lbl; }

#define INC(param)              { ++(param); }
#define DEC(param)              { --(param); }

#define LEA(dst, src)           { (dst) = (INT)(src); }
#define SETL(dst, src)          { *(INT *)(dst) = (src); }
#define GETL(dst, src)          { (dst) = *(INT *)(src); }

#define CALL(proc)              { \
    extern INT ip; \
    extern jmp_buf _ip; \
    extern jmp_buf _ipArray[]; \
    if (setjmp(_ip) == 0) { \
        memcpy(_ipArray[ip++], &_ip, sizeof(jmp_buf)); \
        PUSH(ip); \
        proc(); \
    } \
};
#define INVOKE(proc)            { \
    extern INT n; \
    CALL(proc); \
    POP(n); \
};
#define RETURN() { \
    goto _end_proc; \
}
#define RET() { \
    extern INT ip; \
    extern jmp_buf _ip; \
    extern jmp_buf _ipArray[]; \
    POP(ip); \
    memcpy(&_ip, _ipArray[ip-1], sizeof(jmp_buf)); \
    longjmp(_ip, a); \
}
#define EXIT()                  { exit(a); }

#define PROC_NAKED(proc_name)   INT proc_name() {
#define ENDP_NAKED              _end_proc: return 0; }


INT n;

// ���ν����� �ʱ�ȭ
INT proc_init() {
    PUSH(bp);
    MOVL(bp, sp);
    return 0;
}
// ȣ�� ���ν����� �����ϱ� ���� ���ν����� ����
INT proc_retn() {
    MOVL(sp, bp);
    POP(bp);
    return 0;
}

// ���α׷����� �ֿܼ� ������ ����ϴ� �Լ��� ����
INT print_int() {
    INT num = *(INT*)(m + sizeof(INT) + sp);
    return printf("%d", (int)num);
}
// ���α׷����� �ֿܼ� ���ڿ��� ����ϴ� �Լ��� ����
INT print_str() {
    INT val = *(INT*)(m + sizeof(INT) + sp);
    return printf("%s", (const char*)val);
}


#endif