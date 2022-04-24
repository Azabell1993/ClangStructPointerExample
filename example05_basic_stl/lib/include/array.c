/*
    Copyright (c) 2022 AZABELL Developer
    Azabell source code
    C language-like object-oriented implementation code
    Developer Connect E-mail : jeewoo19930315@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#pragma warning(disable:4996)
// #ifndef _AZABELL_C_STL_ARRAY_H
// #define _AZABELL_C_STL_ARRAY_H
#define max 2048

typedef int element;
typedef int SIZE;
typedef struct arraylist ArrayList;
typedef struct Array ARRAY;

ARRAY* new_create();
ARRAY* new_ArrayList();

int new_empty(), new_full(), new_sort();
void new_push(), new_pop(), new_del(), new_list(), new_returnSort();

typedef struct arraylist {
    struct Array {
        ARRAY *(*create)();
        ARRAY (*new_arraylist)();
        int     (*empty)();
        int     (*full)();
        int     (*sort)();
        void    (*sortprint)();
        void    (*del)();
        void    (*returnsort)();
        void    (*push)();
        void    (*pop)();
        void    (*print)();

    } ArrayListPtr;

    element* arrayValue;
    SIZE    size;
} ArrayList_ptr;

typedef ArrayList_ptr * ArrayList;

static const struct Array array_ptr = {
    .create = new_create,
    .new_arraylist = new_ArrayList,
    .empty = new_empty,
    .full = new_full,
    .push = new_push,
    .pop = new_pop,
    .del = new_del,
    .print = new_printData,
    .sort = new_sort,
    .sortprint = new_returnSort
};

void init(ArrayList list) {
    list->size = 0;
}

ArrayList new_ArrayList() {
    return (ArrayList)calloc(1, sizeof(ArrayList_ptr));
}

ARRAY* new_create(element arrayValue[max], SIZE size)
{
    struct arraylist* ptr = memcpy(malloc(sizeof(ArrayList)), &(ArrayList) {
        .ArrayListPtr = array_ptr
    }, sizeof(ArrayList));

    ptr->arrayValue = arrayValue;
    ptr->size = size;

    return &ptr->ArrayListPtr;
}


int new_empty(ArrayList list) {
    if (list->size == 0)
        return 1;
    else
        return 0;
}

int new_full(ArrayList list) {
    if (list->size == max)
        return 1;
    else
        return 0;
}

int  new_sort(int arr[], int count)
{
    int temp;

    for (int i = 0; i < count; i += 1) {
        for (int j = 0; j < count - 1; j += 1) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return *arr;
}

void new_del(ArrayList list, int pos) {
    if (!new_empty(list)) {
        element tmp = list->arrayValue[pos];
        for (int i = pos + 1; i < list->size; i++)
            list->arrayValue[i - 1] = list->arrayValue[i];
        list->size--;
    }
    else
        printf("리스트가 비어 있습니다\n");
}

void   new_returnSort(int arr[], int size)
{
    for (int i = 0; i < size; i += 1) {
        printf("%d ", arr[i]);
    }
}

void new_push(ArrayList list, element item) {
    if (!new_full(list)) {
        int pos = list->size;
        list->arrayValue[pos] = item;
        list->size++;
    }
    else
        printf("리스트가 꽉 차있습니다\n");
}

void new_pop(ArrayList list) {
    if (!new_empty(list)) {
        list->size--;
    }
    else
        printf("리스트가 비어 있습니다\n");
}

void new_printData(ArrayList list) {
    if (!new_empty(list)) {
        for (int i = 0; i < list->size; i++)
            if (list->arrayValue[i] >= 65 && list->arrayValue[i] <= 90) {
                printf("[%c] ", list->arrayValue[i]);
            }
            else {
                printf("[%d] ", list->arrayValue[i]);
            }
    }
    else
        printf("리스트가 비어 있습니다\n");
}

int main()
{
    ArrayList this = new_ArrayList();
    
    new_push(this, 'A');
    new_push(this, 'B');
    new_push(this, 333);
    new_printData(this);

    ArrayList this = array_ptr.create('A', 'B', 3333, 333);
    new_printData(this);
    // new_push(list, 'B'); // [1 2]
    // new_push(list, 3333); // [1 2]
    // new_push(list, 333); // [1 2]
    
    puts("");
    
}
//#endif

