#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
char  op_tb[4] = {'+', '-', '*', '/'};

typedef struct _CALC_DATA {
    // this pointer
    struct _CALC_DATA *this;
    // 필드 선언
    double operand1;
    double operand2;
    char operator;
    double result;

    // 멤버 함수, 메서드
    void (*PrintInfo)(struct _CALC_DATA *this);

    // 접근 함수, 엑세스 메서드
    double    (*SETCUL)(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result);
    double    (*GETCUL)(const struct _CALC_DATA *this);
} _CD;

// 생성자, 소멸자
_CD *new_Parent(double operand1, double operand2, char operator, double result);
void Delete_CD(struct _CALC_DATA *make_cd_ptr);

// 함수 전방 선언
void PrintInfo_(const struct _CALC_DATA *this);
double SETCUL_(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result);
double GETCUL_(const struct _CALC_DATA *this);

// 상속 선언
typedef struct _CALC_DATA_Child {
    _CD _CALC_DATA_Child;
    struct _CD_CHILD *this;

    // // 필드 선언
    // double operand1;
    // double operand2;
    // char operator;
    // double result;

    double money;

    double    (*SETCUL_Child)(struct _CALC_DATA_Child *this, double operand1, double operand2, char operator, double result, double money);
    double    (*GETCUL_Child)(const struct _CALC_DATA_Child *this);
} _CD_CHILD;

// 생성자, 소멸자
_CD_CHILD *new_Child(double operand1, double operand2, char operator, double result);
void Delete_CH_CHILD(struct _CALC_DATA *make_cd_child_ptr);

//함수 전방 선언
double SETCUL_Child(struct _CALC_DATA_Child *this, double operand1, double operand2, char operator, double result, double money);
double GETCUL_Child(const struct _CALC_DATA_Child *this);

double add(_CD *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 + this -> operand2;
}

double sub(_CD *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 - this -> operand2;
}

double mul(_CD *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = this -> operand1 * this -> operand2;
}

double divf(_CD *this, double operand1, double operand2, char operator, double result)
{
    return this -> result = (double)this -> operand1 / (double)this -> operand2;
}

_CD *new_Parent(double operand1, double operand2, char operator, double result) {
    _CD *temp = (_CD *)malloc(sizeof(_CD) );
    
    // 함수 포인터 선언
    temp -> this = temp;
    temp -> PrintInfo = PrintInfo_;
    temp -> SETCUL = SETCUL_;
    temp -> GETCUL = GETCUL_;
    return temp;
}

_CD_CHILD *new_Child(double operand1, double operand2, char operator, double result, double money) {
    _CD_CHILD *temp;
    temp = (_CD_CHILD *)new_Parent(operand1, operand2, operator, result, money);
    printf("부모 클래스의 크기 : %d\n", _msize(temp));
    
    temp = (_CD_CHILD *)realloc(temp, sizeof(_CD_CHILD));
    printf("자식 클래스의 크기 : %d\n", _msize(temp));

    // 함수 포인터 등록
    temp -> this = temp;
    temp -> SETCUL_Child = SETCUL_;
    temp -> GETCUL_Child = GETCUL_;
    return temp;
}

/* 
    소멸자
*/
void Delete_CD(struct Parent *make_cd_ptr)
{
	free(make_cd_ptr);
}

void Delete_CH_CHILD(struct Parent *make_cd_child_ptr)
{
	free(make_cd_child_ptr);
}


/* 
    자식 구조체 상속
    setter, getter
    
    // 함수 포인터 선언 내역
    temp -> this = temp;
    temp -> CdInfo = PrintInfo_;
    temp -> SETCUL = SETCUL_;
    temp -> GETCUL = GETCUL_;
*/

void PrintInfo_(struct _CALC_DATA *this)
{
    Printf("이곳은 출력 테스트 장소입니다. 인자 값 : %d \n", this -> operand1);
    Printf("이곳은 출력 테스트 장소입니다. 인자 값 : %d \n", this -> operand2);
    Printf("이곳은 출력 테스트 장소입니다. 인자 값 : %d \n", this -> result);
}

void SETCUL(struct _CALC_DATA *this, double operand1, double operand2, char operator, double result)
{
    this -> operand1 = operand1;
    this -> operand2 = operand2;
    this -> operator = operator;
    this -> result = result;
}

void GETCUL(const struct _CALC_DATA *this)
{
    return 
    (printf("%.2f %c %.2f = %.2f\n",
        this -> operand1,
        this -> operator,
        this -> operand2,
        this -> result)
    );
}

void SETCUL_CHILD(struct _CALC_DATA_Child *this, double money)
{
    this -> money = money;
}

void GETCUL_CHILD(const struct _CALC_DATA_Child *this)
{
    return 
    (printf("자식 구조체 출력 테스트 장소입니다. : %d\f\t\n ",
        this -> money)
    );
}

int main()
{
    // 첫번째 객체 생성
    struct _CALC_DATA test;
    // 필드 -> 객체의 데이터가 저장되는 곳
    test.operand1 = 10;
    test.operand2 = 30;
    test.operator = '+';
    test.result=0; 
    
    // 생성자 호출 -> 객체 생성 시 초기화 역할 담당
    _CD *make_cd_ptr = new_Parent(test.operand1, test.operator, test.operand2, test.result);
    printf("테스트 출력\n");
    make_cd_ptr->this->PrintInfo(make_cd_ptr->this);

    make_cd_ptr->SETCUL(make_cd_ptr, test.operand1, test.operator, test.operand2, test.result);
    make_cd_ptr->PrintInfo(make_cd_ptr);

    Delete_CD(make_cd_ptr);

    printf("---");
    // 두번째 객체 생성
    struct _CALC_DATA_Child test2;
    // 필드 -> 객체의 데이터가 저장되는 곳
    test2.money=1000000;
    _CD_CHILD *make_cd_child_ptr = new_Child(test.operand1, test.operator, test.operand2, txest.result, test2.money);
    printf("\nmoney\n");
    make_cd_child_ptr->_CALC_DATA_Child.PrintInfo((_CD*)make_cd_child_ptr);
    test2.money = make_cd_child_ptr -> GETCUL_Child(make_cd_child_ptr);
    printf("test print : %d", test2.money);
    Delete_CH_CHILD(make_cd_child_ptr);

    system("pause");
    return (0);
}
