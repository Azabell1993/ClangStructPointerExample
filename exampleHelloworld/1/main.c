#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[20];
    int age;
    char address[100];
};

int main(int argc, char* argv[])
{
    struct Person *p1 = malloc(sizeof(struct Person));

    strcpy(p1->name, "홍길동");
    p1->age = 30;



}