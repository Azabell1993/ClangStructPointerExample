#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <glib.h>
#include <gtk/gtk.h>
#include <mysql.h>


#ifdef __cheaderfile
extern "C" {
    static __attribute__((visibility("default"))) int compareFunc(const void * a, const void *b);
    static __attribute__((visibility("default"))) int bubble_sort(int arr[], int count);
};
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
    #define NORETERN _attribute_ ((_noreturn_))
    static __attribute__((visibility("default"))) int compareFunc(const void * a, const void *b);
    static __attribute__((visibility("default"))) void bubble_sort(int arr[], int count);
#endif
    static __attribute__((visibility("default"))) int compareFunc(const void *a, const void *b) {
        int num1 = *(int *) a;
        int num2 = *(int *) b;

        if (num1 < num2) {
            return -1;
        }

        if (num1 > num2) {
            return 1;
        }
        return 0;
    }

    static __attribute__((visibility("default"))) void bubble_sort(int arr[], int count) {

        int temp;

        for(int i=0; i<count; i+=1) {
            for(int j=0; j<count-1; j+=1) {
                if(arr[j]>arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

#endif



