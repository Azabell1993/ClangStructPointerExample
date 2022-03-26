#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _PERSON_INFORMATION PI;

struct _PERSON_INFORMATION {
    //char *NAME;
    int AGE;

    void (*SETAGE)(struct _PERSON_INFORMATION *this, const int AGE);
    int (*GETAGE)(const struct _PERSON_INFORMATION * this);

    void (*INFO)();
};

void 
PERSON_SETAGE(struct _PERSON_INFORMATION *this, const int AGE)
{
    this -> AGE = AGE;
}

int 
PERSON_GETAGE(const struct _PERSON_INFORMATION *this)
{
    return 
    (this -> AGE);
}

void 
PERSON_INIT(struct _PERSON_INFORMATION *this)
{
    this -> SETAGE = PERSON_SETAGE;
    this -> GETAGE = PERSON_GETAGE;
}

void 
PERSON_DESTORY() { }

void    
PERSON1(const char *NAME) {
    NAME = (const char*)malloc(sizeof(const char)*6);
    NAME = "jiwoo";
    printf("%s ", NAME);

    struct _PERSON_INFORMATION jiwoo;
    PERSON_INIT(&jiwoo);

    jiwoo.SETAGE(&jiwoo, 30);
    printf("AGE : %d\n", jiwoo.GETAGE(&jiwoo));

    PERSON_DESTORY(&jiwoo);
}

void
PERSON2(const char *NAME) {
    NAME = (const char*)malloc(sizeof(const char)*6);
    NAME = "dabin";
    printf("%s ", NAME);

    struct _PERSON_INFORMATION dabin;
    PERSON_INIT(&dabin);
    dabin.SETAGE(&dabin, 26);
    printf("AGE : %d\n", dabin.GETAGE(&dabin));

    PERSON_DESTORY(&dabin);
}

PI *GET_INFOR(const char *NAME, const int AGE)
{
    PI *GET_INFOR = NULL;
    if(strcmp(NAME, "jiwoo") == 0)
    {
        GET_INFOR = (PI*)malloc(sizeof(PI));
        GET_INFOR -> INFO = PERSON1;
    } 
    else if(strcmp(NAME, "dabin") == 0) 
    {
        GET_INFOR = (PI*)malloc(sizeof(PI));
        GET_INFOR -> INFO = PERSON2;
    }
    return
    (GET_INFOR);
}

void
main()
{
    PI *PE1, *PE2;
    
    PE1 = GET_INFOR("jiwoo", 30);
    if(!PE1) {
        printf("FAILD TO GET PE1\n");
        return;
    }
    PE1 -> INFO();

    PE2 = GET_INFOR("dabin", 20);
    if(!PE2) {
        printf("FAILD TO GET PE2\n");
        return;
    }
    PE2 -> INFO();

    free(PE1);
    free(PE2);
}