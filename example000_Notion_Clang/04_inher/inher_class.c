#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <malloc.h>

typedef struct Parent {
    struct Parent *this;

    int     age_;
    int     money_;
    
    // member function
    void (*PrintInformation)(struct Parent *this);

    // access function, access method
    void (*set_money)(struct Parent *this, int age, int money);
    int  (*get_money)(const struct Parent *this);
}   Parent;

// 생성자, 소멸자
Parent *New_Parent(int age_, int money);
void DeleteParent(struct Parent *parent_ptr);

// 함수 외부 선언
void PrintInformation_(const struct Parent *this);
void set_money_(struct Parent *this, int age, int money);
int get_money_(const struct Parent *this);

typedef struct Child_A {
	// 상속자 유사 부모 클래스 -> 상속
    Parent parent;

	// 자식 클래스 포인터
    struct Child_A *this;

	// 자식 클래스 필드 값
    int     age_a;
    int     money_a;
    
    // access function, access method
    void (*set_money_child_a)(struct Child_A *this, int age, int money);
    int  (*get_money_child_a)(const struct Child_A *this);

}   Child_A;

// 생성자, 소멸자
Child_A *New_Child_A(int age_a, int money_b);
void DeleteChild_A(struct Child_A *child_a_ptr);

// 함수 외부 선언
void set_money_a(struct Child_A *this, int age_a, int money_a);
int get_money_a(const struct Child_A *this);

typedef struct Child_B {
	// 상속자
    Parent parent;

	// 자식 클래스 포인터
    struct Child_B *this;

	// 자식 클래스 필드 값
    int     age_b;
    int     money_b;

    // access function, access method
    void (*set_money_child_b)(struct Child_B *this, int age, int money);
    int  (*get_money_child_b)(const struct Child_B *this);

}   Child_B;

// 생성자, 소멸자
Child_B *New_Child_B(int ate_b, int money_b);
void DeleteChild_B(struct Child_B *child_b_ptr);

// 함수 외부 선언
void set_money_b(struct Child_B *this, int age_b, int money_b);
int get_money_b(const struct Child_B *this);

Parent *New_Parent(int age, int money)
{
    Parent *temp = (Parent*)malloc(sizeof(Parent));
    
    temp -> age_ = age;
    temp -> money_ = money;

    temp -> this = temp;
    temp -> PrintInformation = PrintInformation_;
    temp -> set_money = set_money_;
    temp -> get_money = get_money_;
    
    return temp;
}

Child_A *New_Child_A(int age, int money)
{
	Child_A *temp;
	temp = (Child_A *)New_Parent(age, money);
    printf("부모 클래스의 크기 : %d\n", _msize(temp));
	temp = (Child_A *)realloc(temp, sizeof(Child_A));
    printf("자식 A 클래스의 크기 : %d\n", _msize(temp));

	temp -> age_a = age;
    temp -> money_a = money;

	// 함수 포인터 등록
	temp->this = temp;
	temp->set_money_child_a = set_money_a;
	temp->get_money_child_a = get_money_a;

	return temp;
}

Child_B *New_Child_B(int age, int money)
{
	Child_B *temp;
	temp = (Child_B *)New_Parent(age, money);
    printf("부모 클래스의 크기 : %d\n", _msize(temp));
	temp = (Child_B *)realloc(temp, sizeof(Child_B));
    printf("자식 B 클래스의 크기 : %d\n", _msize(temp));
	temp -> age_b = age;
    temp -> money_b = money;

	// 함수 포인터 등록
	temp->this = temp;
	temp->set_money_child_b = set_money_b;
	temp->get_money_child_b = get_money_b;

	return temp;
}

// 소멸자
void DeleteParent(struct Parent *parent_ptr)
{
	free(parent_ptr);
}
void DeleteChild_A(struct Child_A *child_a_ptr)
{
	free(child_a_ptr);
}
void DeleteChild_B(struct Child_B *child_b_ptr)
{
	free(child_b_ptr);
}

// 프린트
void PrintInformation_(const struct Parent *this)
{
	printf("현재 나이 : %d살, 남은 돈 : %d\n", this-> age_, this->money_);
}

void set_money_(struct Parent *this, int age, int money)
{
	this -> age_ = age;
    this -> money_ = money;
}
int get_money_(const struct Parent *this)
{
	return this -> age_, this -> money_;
}

void set_money_a(struct Child_A *this, int age, int money)
{
	this -> age_a = age;
    this -> money_a = money;
}
int get_money_a(const struct Child_A *this)
{
	return this-> age_a, this-> money_a;
}

void set_money_b(struct Child_B *this, int age, int money)
{
	this -> age_b = age;
    this -> money_b = money;
}
int get_money_b(const struct Child_B *this)
{
	return this-> age_b, this-> money_b;
}

int main()
{
	int child_money;
	int parent_money;

	Parent *parent_ptr = New_Parent(37, 10000);
	
    puts("처음에 가진 돈은 아래와 같습니다.");
    (*parent_ptr).this->PrintInformation(parent_ptr->this);
	
    parent_ptr->set_money(parent_ptr, 37, 50000);

    puts("현재 남은 잔액은 다음과 같습니다.");
	parent_ptr->PrintInformation(parent_ptr);

	parent_money = parent_ptr->get_money(parent_ptr);
	printf("\t 총 잔액은 %d원입니다.\n", parent_money);

    // 소멸자
	DeleteParent(parent_ptr);

	puts("//////////////////////////////////////");
	Child_A *child_a_ptr = New_Child_A(12, 1000);
	puts("첫 번째 자식이 가진 돈은 아래와 같습니다.");
	(*child_a_ptr).parent.PrintInformation((Parent *)child_a_ptr);
	child_money = child_a_ptr->get_money_child_a(child_a_ptr);
	printf("\n첫 번째 자식의 가진 돈은 %d원이고 부모가 가지고 있는 돈은 %d원 입니다.\n", child_money, parent_money);
	DeleteChild_A(child_a_ptr);

    puts("//////////////////////////////////////");
	Child_B *child_b_ptr = New_Child_B(8, 500);
	puts("자식이 가진 돈은 아래와 같습니다.");
	(*child_b_ptr).parent.PrintInformation((Parent *)child_b_ptr);
	child_money = child_b_ptr->get_money_child_b(child_b_ptr);
	printf("\n두 번째 자식의 가진 돈은 %d원이고 부모가 가지고 있는 돈은 %d원 입니다.\n", child_money, parent_money);
	DeleteChild_B(child_b_ptr);

	system("pause");
	return 0;
}

