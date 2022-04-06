#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
    친구로남는다 remain friends
    친구도안된다 I don't mind friends
    1이안없어질때 When there is no one
    읽고넘어간다 read and pass
*/
const char NAME[] = "완장_견장_잇츠_컴퓨터잘못해요_문돌공돌_행인1_22학번";
#define RemainFriends       0
#define IDontMindFriends    1
#define WhenThereIsNoOne    2
#define ReadAndPass         3

#define FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE 7

struct Select {
    // 필드 값 선언
    int input_Method_Value;
    
    // 메서드 선언
    void (*SET)(struct Select *this, int input_Method_Value);
    int  (*GET)(const struct Select *this);
};

// 전방 선언
void set(struct Select *this, int input_Method_Value);
int  get(const struct Select *this);
// 생성자 전방 선언
void init(struct Select *this);
// 소멸자 전방 선언
void Select_Destory(struct Select *this);

struct PersonInfoStru {
    // 필드 값 선언
    int Select_Person_Info;

    // 메서드 선언
    void (*PERSON_SET)(struct PersonInfoStru *select_this, int Select_Person_Info);
    int  (*PERSON_GET)(const struct PersonInfoStru *select_this);
};

// 전방 선언
void Person_Set(struct PersonInfoStru *select_this, int Select_Person_Info);
int Person_Get(const struct PersonInfoStru *select_this);
// 생성자 전방 선언
void PersionInfo_Init(struct PersonInfoStru *select_this);
// 소멸자 전방 선언
void Person_Destory(struct PersonInfoStru *select_this);

// void const name print
void WanGang();
void GunJang();
void Its();
void IcandoComputer();
void MundolGongDol();
void HangInOne();
void TwoTwoHackBun();

void set(struct Select *this, int input_Method_Value)
{
    this -> input_Method_Value = input_Method_Value;
}

int  get(const struct Select* this)
{
    if ((*this).input_Method_Value == RemainFriends) {
        return puts("     우리 그냥 친구로 남자....");
    }
    else if ((*this).input_Method_Value == IDontMindFriends) {
        return puts("     우리 친구도 못될 거 같아....");
    }
    else if ((*this).input_Method_Value == WhenThereIsNoOne) {
        return puts("     1이 없어지지 않아...");
    }
    else if ((*this).input_Method_Value == ReadAndPass) {
        return puts("     읽고 그냥 넘어가는데 어쩌지...");
    }
}

void Person_Set(struct PersonInfoStru *select_this, int Select_Person_Info)
{
    select_this -> Select_Person_Info = Select_Person_Info;
}

int Person_Get(const struct PersonInfoStru *select_this)
{
    
    void (*Person[FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE])() = {&WanGang, &GunJang, &Its, &IcandoComputer, &MundolGongDol, &HangInOne, &TwoTwoHackBun};

    (Person[select_this->Select_Person_Info]());
}

// 생성자
void init(struct Select *this)
{
	this -> SET = set;
    this -> GET = get;
}

// 생성자
void PersionInfo_Init(struct PersonInfoStru *select_this)
{
	select_this -> PERSON_SET = Person_Set;
    select_this -> PERSON_GET = Person_Get;
}

// 소멸자 선언
void Person_Destory(struct PersonInfoStru *select_this)
{
    free(select_this);
}

void Select_Destory(struct Select *this)
{
    free(this);
}

//완장_견장_잇츠_컴퓨터잘못해요_문돌공돌_행인1_22학번
void WanGang()
{
    for(int i=0; i<4; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}
void GunJang()
{
    for(int i=5; i<9; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}
void Its()
{
    for(int i=10; i<14; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}
void IcandoComputer()
{
    for(int i=15; i<29; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}
void MundolGongDol()
{
    for(int i=30; i<38; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}
void HangInOne()
{
    for(int i=39; i<44; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}
void TwoTwoHackBun()
{
    for(int i=45; i<52; i+=1) {
        printf("%c", NAME[i]);
    }
    printf(" : ");
}


int main() 
{
    srand(time(NULL));
    struct PersonInfoStru   personOuterObj[4];
	struct Select           outerObj[7];
    
    int selectChoice_OutputValue;

    for(int i=0; i<4; i+=1)
    {
        for(int j=0; j<7; j+=1)
        {
            selectChoice_OutputValue = rand()%4;
            PersionInfo_Init(&personOuterObj[j]);
            personOuterObj[j].Select_Person_Info = rand()%7;
            PersionInfo_Init(&personOuterObj[j]);
            personOuterObj[j].PERSON_SET(&personOuterObj[j], personOuterObj[j].Select_Person_Info);
            personOuterObj[j].PERSON_GET(&personOuterObj[j]);
            Person_Destory(personOuterObj);
            outerObj[i].input_Method_Value = selectChoice_OutputValue;
            init(&outerObj[i]);
            outerObj[i].SET(&outerObj[i], outerObj[i].input_Method_Value);
            outerObj[i].GET(&outerObj[i]);
            Select_Destory(outerObj);
        }
        printf("---\n");
    }
}