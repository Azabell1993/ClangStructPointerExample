#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
/*
    ģ���γ��´� remain friends
    ģ�����ȵȴ� I don't mind friends
    1�̾Ⱦ������� When there is no one
    �а�Ѿ�� read and pass
*/
const char NAME[] = "����_����_����_��ǻ���߸��ؿ�_��������_����1_22�й�";
#define RemainFriends       0
#define IDontMindFriends    1
#define WhenThereIsNoOne    2
#define ReadAndPass         3

#define FUNCTIONPOINTER_PERSONINFORMATION_MAX_VALULE 7

struct Select {
    // �ʵ� �� ����
    int input_Method_Value;

    // �޼��� ����
    void (*SET)(struct Select* this, int input_Method_Value);
    int  (*GET)(const struct Select* this);
};

// ���� ����
void set(struct Select* this, int input_Method_Value);
int  get(const struct Select* this);
void init(struct Select* this);

struct PersonInfoStru {
    // �ʵ� �� ����
    int Select_Person_Info;

    // �޼��� ����
    void (*PERSON_SET)(struct PersonInfoStru* select_this, int Select_Person_Info);
    int  (*PERSON_GET)(const struct PersonInfoStru* select_this);
};

// ���� ����
void Person_Set(struct PersonInfoStru* select_this, int Select_Person_Info);
int Person_Get(const struct PersonInfoStru* select_this);
void PersionInfo_Init(struct PersonInfoStru* select_this);

// void const name print
void WanGang();
void GunJang();
void Its();
void IcandoComputer();
void MundolGongDol();
void HangInOne();
void TwoTwoHackBun();

void set(struct Select* this, int input_Method_Value)
{
    this->input_Method_Value = input_Method_Value;
}

int  get(const struct Select* this)
{
    if ((*this).input_Method_Value == RemainFriends) {
        return puts("     �츮 �׳� ģ���� ����....");
    }
    else if ((*this).input_Method_Value == IDontMindFriends) {
        return puts("     �츮 ģ���� ���� �� ����....");
    }
    else if ((*this).input_Method_Value == WhenThereIsNoOne) {
        return puts("     1�� �������� �ʾ�...");
    }
    else if ((*this).input_Method_Value == ReadAndPass) {
        return puts("     �а� �׳� �Ѿ�µ� ��¼��...");
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

// ������
void init(struct Select* this)
{
    this->SET = set;
    this->GET = get;
}

// ������
void PersionInfo_Init(struct PersonInfoStru* select_this)
{
    select_this->PERSON_SET = Person_Set;
    select_this->PERSON_GET = Person_Get;
}

//����_����_����_��ǻ���߸��ؿ�_��������_����1_22�й�
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

    struct PersonInfoStru   personOuterObj[7];
    struct Select           outerObj[4];

    int selectChoice_OutputValue;

    for (int i = 0; i < 4; i += 1)
    {
        for (int j = 0; j < 7; j += 1)
        {
            selectChoice_OutputValue = rand() % 4;
            PersionInfo_Init(&personOuterObj[j]);
            personOuterObj[j].Select_Person_Info = rand() % 7;
            personOuterObj[j].PERSON_SET(&personOuterObj[j], personOuterObj[j].Select_Person_Info);
            personOuterObj[j].PERSON_GET(&personOuterObj[j]);
            outerObj[i].input_Method_Value = selectChoice_OutputValue;
            init(&outerObj[i]);
            outerObj[i].SET(&outerObj[i], outerObj[i].input_Method_Value);
            outerObj[i].GET(&outerObj[i]);
        }
        printf("---\n");
    }
}
