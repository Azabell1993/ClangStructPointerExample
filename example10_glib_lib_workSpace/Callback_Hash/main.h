#pragma ONCE
#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

static __attribute__ ((visibility("hidden")))           void (*registered_callback)();
static __attribute__((visibility("default")))           void HelloWorld(void);
static __attribute__((visibility("default")))           void HelloWorldDefault(void);
static __attribute__((visibility("default")))           int LoopTest(int num1);
static inline __attribute__ ((visibility("hidden")))    void setCallback(void (*callback)());
static inline __attribute__ ((visibility("hidden")))    void callCallback();
static inline __attribute__ ((visibility("hidden")))    void printHelloWorld();

static __attribute__((visibility("default"))) int LoopTest(int num1) {
    for(int i=1; i<=num1; i+=1) {
        printf("<%2d> This Function is looptest functioon.\n", i);
    }
    return 1;
}

static inline __attribute__ ((visibility("hidden"))) void setCallback(void (*callback)())
{
    registered_callback = callback;
}

static inline __attribute__ ((visibility("hidden"))) void callCallback()
{
    (*registered_callback)();
}
static inline __attribute__ ((visibility("hidden"))) void printHelloWorld()
{
    printf("This is a HelloWorld print function callback!!!\n");

}

static __attribute__((visibility("default"))) void HelloWorld(void) {
    GString *mystr = g_string_new("**** C Progammig Language Call Back Example ****!!!!\n");
    g_print(mystr->str, mystr->len);
    g_string_free(mystr, TRUE);
}

static __attribute__((visibility("default"))) void HelloWorldDefault(void) {
    GString *mystr2 = g_string_new("This function is Default Value!!\n");
    g_print(mystr2 -> str, mystr2 -> len);
    g_string_free(mystr2, TRUE);
}

#endif