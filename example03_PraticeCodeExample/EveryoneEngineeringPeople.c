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
    void (*SET)(struct Select* this, int input_Method_Value);
    int  (*GET)(const struct Select* this);
};

// 전방 선언
void set(struct Select* this, int input_Method_Value);
int  get(const struct Select* this);
// 생성자 전방 선언
void init(struct Select* this);
// 소멸자 전방 선언
void Select_Destory(struct Select* this);

struct PersonInfoStru {
    // 필드 값 선언
    int Select_Person_Info;

    // 메서드 선언
    void (*PERSON_SET)(struct PersonInfoStru* select_this, int Select_Person_Info);
    int  (*PERSON_GET)(const struct PersonInfoStru* select_this);
};

// 전방 선언
void Person_Set(struct PersonInfoStru* select_this, int Select_Person_Info);
int Person_Get(const struct PersonInfoStru* select_this);
// 생성자 전방 선언
void PersionInfo_Init(struct PersonInfoStru* select_this);
// 소멸자 전방 선언
void Person_Destory(struct PersonInfoStru* select_this);

// void const name print
void WanGang();
void GunJang();
void Its();
void IcandoComputer();
void MundolGongDol();
void HangInOne();
void TwoTwoHackBun();

// 입, 출력 메서드
void set(struct Select* this, int input_Method_Value)
{
    this->input_Method_Value = input_Method_Value;
}

int  get(const struct Select* this)
{
    if ((*this).input_Method_Value == RemainFriends) {
        return printf("\t우리 그냥 친구로 남자....\n\n");
    }
    else if ((*this).input_Method_Value == IDontMindFriends) {
        return printf("\t우리 친구도 못될 거 같아....\n\n");
    }
    else if ((*this).input_Method_Value == WhenThereIsNoOne) {
        return printf("\t1이 없어지지 않아...\n\n");
    }
    else if ((*this).input_Method_Value == ReadAndPass) {
        return printf("\t읽고 그냥 넘어가는데 어쩌지...\n\n");
    }
}

void Person_Set(struct PersonInfoStru* select_this, int Select_Person_Info)
{
    select_this->Select_Person_Info = Select_Person_Info;
}

int Person_Get(const struct PersonInfoStru* select_this)
{

    void (*Person[FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE])() = { &WanGang, &GunJang, &Its, &IcandoComputer, &MundolGongDol, &HangInOne, &TwoTwoHackBun };

    (Person[select_this->Select_Person_Info]());
}

// 생성자
void init(struct Select* this)
{
    this->SET = set;
    this->GET = get;
}

// 생성자
void PersionInfo_Init(struct PersonInfoStru* select_this)
{
    select_this->PERSON_SET = Person_Set;
    select_this->PERSON_GET = Person_Get;
}

// 소멸자 선언
void Person_Destory(struct PersonInfoStru* select_this)
{
    free(select_this);
}

void Select_Destory(struct Select* this)
{
    free(this);
}

//완장_견장_잇츠_컴퓨터잘못해요_문돌공돌_행인1_22학번
void WanGang() { for (int i = 0; i < 4; i += 1) { printf("%c", NAME[i]); } printf(" : "); }
void GunJang() { for (int i = 5; i < 9; i += 1) { printf("%c", NAME[i]); } printf(" : "); }
void Its() { for (int i = 10; i < 14; i += 1) { printf("%c", NAME[i]); }  printf(" : "); }
void IcandoComputer() { for (int i = 15; i < 29; i += 1) { printf("%c", NAME[i]); } printf(" : "); }
void MundolGongDol() { for (int i = 30; i < 38; i += 1) { printf("%c", NAME[i]); } printf(" : "); }
void HangInOne() { for (int i = 39; i < 44; i += 1) { printf("%c", NAME[i]); } printf(" : "); }
void TwoTwoHackBun() { for (int i = 45; i < 52; i += 1) { printf("%c", NAME[i]); } printf(" : "); }

int main()
{
    srand(time(NULL));

    // 첫 번째 객체
    int selectChoice_OutputValue = rand() % 4;
    struct PersonInfoStru personOuterObj;
    PersionInfo_Init(&personOuterObj);
    personOuterObj.Select_Person_Info = 0;
    personOuterObj.PERSON_SET(&personOuterObj, personOuterObj.Select_Person_Info);
    personOuterObj.PERSON_GET(&personOuterObj);
    struct Select outerObj;
    outerObj.input_Method_Value = selectChoice_OutputValue;
    init(&outerObj);
    outerObj.SET(&outerObj, outerObj.input_Method_Value);
    outerObj.GET(&outerObj);

    // 두 번째 객체
    int selectChoice_OutputValue1 = rand() % 4;
    struct PersonInfoStru personOuterObj1;
    PersionInfo_Init(&personOuterObj1);
    personOuterObj1.Select_Person_Info = 1;
    personOuterObj1.PERSON_SET(&personOuterObj1, personOuterObj1.Select_Person_Info);
    personOuterObj1.PERSON_GET(&personOuterObj1);
    struct Select outerObj1;
    outerObj1.input_Method_Value = selectChoice_OutputValue1;
    init(&outerObj1);
    outerObj1.SET(&outerObj1, outerObj1.input_Method_Value);
    outerObj1.GET(&outerObj1);

    // 세 번째 객체
    int selectChoice_OutputValue2 = rand() % 4;
    struct PersonInfoStru personOuterObj2;
    PersionInfo_Init(&personOuterObj2);
    personOuterObj2.Select_Person_Info = 2;
    personOuterObj2.PERSON_SET(&personOuterObj2, personOuterObj2.Select_Person_Info);
    personOuterObj2.PERSON_GET(&personOuterObj2);
    struct Select outerObj2;
    outerObj2.input_Method_Value = selectChoice_OutputValue2;
    init(&outerObj2);
    outerObj2.SET(&outerObj2, outerObj2.input_Method_Value);
    outerObj2.GET(&outerObj2);

    // 네 번째 객체
    int selectChoice_OutputValue3 = rand() % 4;
    struct PersonInfoStru personOuterObj3;
    PersionInfo_Init(&personOuterObj3);
    personOuterObj3.Select_Person_Info = 3;
    personOuterObj3.PERSON_SET(&personOuterObj3, personOuterObj3.Select_Person_Info);
    personOuterObj3.PERSON_GET(&personOuterObj3);
    struct Select outerObj3;
    outerObj3.input_Method_Value = selectChoice_OutputValue3;
    init(&outerObj3);
    outerObj3.SET(&outerObj3, outerObj3.input_Method_Value);
    outerObj3.GET(&outerObj3);


    // 다섯 번째 객체
    int selectChoice_OutputValue4 = rand() % 4;
    struct PersonInfoStru personOuterObj4;
    PersionInfo_Init(&personOuterObj4);
    personOuterObj4.Select_Person_Info = 4;
    personOuterObj4.PERSON_SET(&personOuterObj4, personOuterObj4.Select_Person_Info);
    personOuterObj4.PERSON_GET(&personOuterObj4);
    struct Select outerObj4;
    outerObj4.input_Method_Value = selectChoice_OutputValue4;
    init(&outerObj4);
    outerObj4.SET(&outerObj4, outerObj4.input_Method_Value);
    outerObj4.GET(&outerObj4);

    // 여섯 번째 객체
    int selectChoice_OutputValue5 = rand() % 4;
    struct PersonInfoStru personOuterObj5;
    PersionInfo_Init(&personOuterObj5);
    personOuterObj5.Select_Person_Info = 5;
    personOuterObj5.PERSON_SET(&personOuterObj5, personOuterObj5.Select_Person_Info);
    personOuterObj5.PERSON_GET(&personOuterObj5);
    struct Select outerObj5;
    outerObj5.input_Method_Value = selectChoice_OutputValue5;
    init(&outerObj5);
    outerObj5.SET(&outerObj5, outerObj5.input_Method_Value);
    outerObj5.GET(&outerObj5);

    // 일곱 번째 객체
    int selectChoice_OutputValue6 = rand() % 4;
    struct PersonInfoStru personOuterObj6;
    PersionInfo_Init(&personOuterObj6);
    personOuterObj6.Select_Person_Info = 6;
    personOuterObj6.PERSON_SET(&personOuterObj6, personOuterObj6.Select_Person_Info);
    personOuterObj6.PERSON_GET(&personOuterObj6);
    struct Select outerObj6;
    outerObj6.input_Method_Value = selectChoice_OutputValue6;
    init(&outerObj6);
    outerObj6.SET(&outerObj6, outerObj6.input_Method_Value);
    outerObj6.GET(&outerObj6);
    
    /* 소멸자 */
    Person_Destory(&personOuterObj);
    Select_Destory(&outerObj);
    Person_Destory(&personOuterObj1);
    Select_Destory(&outerObj1);
    Person_Destory(&personOuterObj2);
    Select_Destory(&outerObj2);
    Person_Destory(&personOuterObj3);
    Select_Destory(&outerObj3);
    Person_Destory(&personOuterObj4);
    Select_Destory(&outerObj4);
    Person_Destory(&personOuterObj5);
    Select_Destory(&outerObj5);
    Person_Destory(&personOuterObj6);
    Select_Destory(&outerObj6);
}