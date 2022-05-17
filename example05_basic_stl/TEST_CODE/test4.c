#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

#define cal_lib(calStruct, type, length)

typedef calStruct;
typedef struct calStruct calStruct;

struct calStruct##_iterator;
typedef struct calStruct##_iterator calStruct##_iterator;

struct calStruct##_iterator {
	type *ptr;

	void (*sum)(calStruct##_iterator*);
	void (*sub)(calStruct##_iterator*);

	type (*get)(const calStruct##_iterator*);
	type *(*get_ptr)(calStruct##_iterator*);
};

void	calStruct##_iterator_sum(calStruct##_iterator*);
void	calStruct##_iterator_sub(calStruct##_iterator*);

type	calStruct##_iterator_get(const calStruct##_iterator*);
type	*calStruct##_iterator_get_ptr(calStruct##_iterator*);

calStruct##_iterator new_##calStruct##_iterator(type*);

struct calStruct {
	struct node {
		int number;
		struct node *p_next;
	} NODE;
	
	// AddNumber
	void (*AddNumber)(const NODE **pp_head, NODE **pp_tail, int data);
	int *(*get_sum)(const calStruct *, NODE *p_head, NODE *p_tail, NODE *p);
	int *(*get_sub)(const calStruct *, NODE *p_head, NODE *p_tail, NODE *p);
	
};

void calStruct##_AddNumber(const calStruct *, struct *, int);
int *calStruct##_get_sum(const calStruct *, struct *, struct *, struct *);
int *calStruct##_get_sub(const calStruct *, struct *, struct *, struct *);

void AddNumber(NODE **pp_head, NODE **pp_tail, int data)
{
    if(NULL != *pp_head)
    {
        (*pp_tail) -> p_next = (NODE*)malloc(sizeof(NODE));
        *pp_tail = (*pp_tail) -> p_next;
    } else {
        *pp_head = (NODE*)malloc(sizeof(NODE));
        *pp_tail = *pp_head;
    }
    (*pp_tail)  -> number = data;
    (*pp_tail) -> p_next = NULL;
}

int calStruct##_sum(const calStruct *this, NODE *p_head, NODE *p_tail, NODE *p)
{
    int sum = 0;

    p = p_head;
    while(NULL != p)
    {
        if(p != p_head) printf(" + ");
        printf(" %d ", p->number);
        sum = sum + p -> number;
        p = p -> p_next;
    }
    return ((printf(" = %d\n", sum));
}

int calStruct##_sub(const calStruct *this, NODE *p_head, NODE *p_tail, NODE *p)
{
    int sub = 0;

    p = p_head;
    while(NULL != p)
    {
        if(p != p_head) printf(" + ");
        printf(" %d ", p->number);
        sub = sub - p -> number;
        p = p -> p_next;
    }
    return ((printf(" = %d\n", sub));
}


