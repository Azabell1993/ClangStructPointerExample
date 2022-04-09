#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *p_next;
} NODE;

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

int main()
{
    NODE *p_head = NULL, *p_tail = NULL, *p;
    int sum = 0;
    int temp;

    while(1)
    {
        printf(" input the number : ");
        scanf("%d", &temp);
        if(9999 == temp) break;
        AddNumber(&p_head, &p_tail, temp);
    }

    p = p_head;
    while(NULL != p)
    {
        if(p != p_head) printf(" + ");
        printf(" %d ", p->number);
        sum = sum + p -> number;
        p = p -> p_next;
    }
    printf(" = %d\n", sum);

    while(NULL != p_head)
    {
        p = p_head;
        p_head = p_head -> p_next;
        free(p);
    }
    p_tail = p_head;
}