#pragma once
#ifndef CALCULATORLIB_H_
#define CALCULATORLIB_H_

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
    #endif

    #ifdef BUILD_MY_DLL
    #define SHARED_LIB __declspec(dllexport)
    #else
    #define SHARED_LIB __declspec(dllexport)
    #endif
        void Dot_Putchar(char c);
        int  SUM(int x, int y);
        int  SUB(int x, int y);
        int  MUL(int x, int y);
        int  DIV(int x, int y);
        int(*CalFunc[4])(int, int) = {&SUM, &SUB, &MUL, &DIV};
        char  op_tb[4] = {'+', '-', '*', '/'};
        int  SelectFunc(int NumA, char Ch, int NumB);
        int  SelectSUM (int NumA, char Ch, int NumB);
        int  SelectSUB (int NumA, char Ch, int NumB);
        int  SelectMUL (int NumA, char Ch, int NumB);
        int  SelectDIV (int NumA, char Ch, int NumB);
        int  CallCalc(int NumA, char Ch, int NumB);
        /* Div Function    if(NumB > NumA) */
        int  DivWhereNumBGreter (int NumA, char Ch, int NumB);
    #ifdef __cplusplus
}
#endif

#endif