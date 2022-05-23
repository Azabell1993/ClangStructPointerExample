#pragma once
#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

typedef struct Hello HE;


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
    void SAYHELLO_(struct Hello *this, int age);
    static inline __attribute__ ((visibility("hidden")))    void printHelloWorld();
    static inline __attribute__((visibility("default")))    void He_Printf_(const HE *this);
    static __attribute__ ((visibility("hidden")))           void (*registered_callback)();
    static __attribute__((visibility("default")))           void HelloWorld(void);
    static inline __attribute__ ((visibility("hidden")))    void setCallback(void (*callback)());
    static inline __attribute__ ((visibility("hidden")))    void callCallback();
    static inline __attribute__ ((visibility("hidden")))    void printHelloWorld();
    void    HELLO_SET_(HE* this, const int age);
    int     HELLO_GET_(const struct Hello* this);
#endif


static HE* new_Hello(int age_);

struct Hello {
    int age_;
    void (*SAYHELLO)(struct Hello *this, int age);
    void (*He_Printf)(const struct Hello *this);
    void (*registered_callback)();
    void (*HELLO_SET)(struct Hello * this, const int age);
    int  (*HELLO_GET)(const struct Hello* this);
    void (*HE_Printf)(const struct Hello *this);
};

static __attribute__ ((visibility("hidden"))) void (*registered_callback)();

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

static inline __attribute__((visibility("default"))) void PrintHello1(struct Hello *this, int age) {
    this -> age_ = age;
    puts("Hello 1!!!");
    printf("Hello 1 age : %d\n", age);
}

static inline __attribute__((visibility("default"))) void PrintHello2(struct Hello *this, int age) {
    this -> age_ = age;
    puts("Hello 2!!!");
    printf("Hello 2 age : %d\n", age);
}

static inline __attribute__((visibility("default"))) void PrintHello3(struct Hello *this, int age) {
    this -> age_ = age;
    puts("Hello 3!!!");
    printf("Hello 3 age : %d\n", age);
}

void    HELLO_SET_(HE* this, const int age) {
    this -> age_ = age;
}
int     HELLO_GET_(const struct Hello* this) {
    return
            this -> age_;
}

static inline __attribute__ ((visibility("default"))) void He_Printf_(const HE *this) {
    HelloWorld();

    setCallback(printHelloWorld);
    callCallback();

    int age_ = this->age_;
    HE *helloObj = new_Hello(age_);

    PrintHello1(&(*helloObj),age_+10);
    PrintHello2(&(*helloObj),age_+20);
    PrintHello3(&(*helloObj),age_+30);
}

static HE* new_Hello(int age) {
    HE* temp = (HE*)malloc(sizeof(HE));
    temp->age_ = age;

    temp -> He_Printf = He_Printf_;
    temp -> HELLO_SET = HELLO_SET_;
    temp -> HELLO_GET = HELLO_GET_;

    return temp;
}

#ifdef __cheaderfile
#endif

#endif
