#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef struct Person PERSON;
typedef struct Child CHILD;

/* 부모 클래스 전방 선언 */
PERSON* new_create();

/* 유사 클래스 상속 전방 선언 */
int new_destory(), new_hello(), new_rust(), new_programming();
char* new_name();

typedef struct Child {
    struct Person {
        PERSON* (*create)();
        int (*destory)();
        int (*hello)();
        int (*rust)();
        int (*programming)();
        char* (*name)();
    } PersonStruPtr;

    int math;
    int eng;
    int kor;
    char* name;
} CHILD;

/* static cosnt struct ArrayList ArrayList_ptr */
static const struct Person PersonPtr = {
    /* .push = new_push */
    /* .pop = new_pop */
    .create = new_create,
    .destory = new_destory,
    .hello = new_hello,
    .rust = new_rust,
    .programming = new_programming,
    .name = new_name
};

/* typedef struct ArrayList Type *ArrayList_ptr */
/* ArrayList new_insert(ArrayList_ptr list, element item) */
PERSON* new_create(int math, int eng, int kor, char* name)
{
    struct Child* ptr = memcpy(malloc(sizeof(CHILD)), &(CHILD) {
        .PersonStruPtr = PersonPtr
    }, sizeof(CHILD));

    ptr->math = math;
    ptr->eng = eng;
    ptr->kor = kor;
    ptr->name = name;

    return &ptr->PersonStruPtr;
}

int new_destory(CHILD* ptr)
{
    free(ptr);
}

int new_hello(CHILD* ptr)
{
    if ((ptr->math + ptr->eng + ptr->kor) < 250) {
        printf("3과목 점수 합이 250점 밑이야. C언어 기본을 다시 다지시오.");
    }
    else {
        new_rust(ptr);
    }
}

int new_rust(CHILD* ptr)
{
    if ((ptr->math + ptr->eng + ptr->kor) > 250) {
        printf("Rust 언어로 넘어가셔도 좋습니다.");
    }
    else {
        new_hello(ptr);
    }
}

int new_programming(CHILD* ptr)
{
    if ((ptr->math + ptr->eng + ptr->kor) > 290) {
        printf("프로그래밍의 신.");
    }
    else {
        new_rust(ptr);
    }
}

char* new_name(CHILD* ptr)
{
    return ptr->name;
}

int main()
{
    PERSON* this = PersonPtr.create(100, 100, 98, "박지우");

    puts("이 메세지가 뜨면 성공입니다.");
    printf("%s\n", this->hello(this));
    
    this->destory(this);
}