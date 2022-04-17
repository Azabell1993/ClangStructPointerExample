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

// ������, �Ҹ���
Parent *New_Parent(int age_, int money);
void DeleteParent(struct Parent *parent_ptr);

// �Լ� �ܺ� ����
void PrintInformation_(const struct Parent *this);
void set_money_(struct Parent *this, int age, int money);
int get_money_(const struct Parent *this);

typedef struct Child_A {
	// ����� ���� �θ� Ŭ���� -> ���
    Parent parent;

	// �ڽ� Ŭ���� ������
    struct Child_A *this;

	// �ڽ� Ŭ���� �ʵ� ��
    int     age_a;
    int     money_a;
    
    // access function, access method
    void (*set_money_child_a)(struct Child_A *this, int age, int money);
    int  (*get_money_child_a)(const struct Child_A *this);

}   Child_A;

// ������, �Ҹ���
Child_A *New_Child_A(int age_a, int money_b);
void DeleteChild_A(struct Child_A *child_a_ptr);

// �Լ� �ܺ� ����
void set_money_a(struct Child_A *this, int age_a, int money_a);
int get_money_a(const struct Child_A *this);

typedef struct Child_B {
	// �����
    Parent parent;

	// �ڽ� Ŭ���� ������
    struct Child_B *this;

	// �ڽ� Ŭ���� �ʵ� ��
    int     age_b;
    int     money_b;

    // access function, access method
    void (*set_money_child_b)(struct Child_B *this, int age, int money);
    int  (*get_money_child_b)(const struct Child_B *this);

}   Child_B;

// ������, �Ҹ���
Child_B *New_Child_B(int ate_b, int money_b);
void DeleteChild_B(struct Child_B *child_b_ptr);

// �Լ� �ܺ� ����
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
    printf("�θ� Ŭ������ ũ�� : %d\n", _msize(temp));
	temp = (Child_A *)realloc(temp, sizeof(Child_A));
    printf("�ڽ� A Ŭ������ ũ�� : %d\n", _msize(temp));

	temp -> age_a = age;
    temp -> money_a = money;

	// �Լ� ������ ���
	temp->this = temp;
	temp->set_money_child_a = set_money_a;
	temp->get_money_child_a = get_money_a;

	return temp;
}

Child_B *New_Child_B(int age, int money)
{
	Child_B *temp;
	temp = (Child_B *)New_Parent(age, money);
    printf("�θ� Ŭ������ ũ�� : %d\n", _msize(temp));
	temp = (Child_B *)realloc(temp, sizeof(Child_B));
    printf("�ڽ� B Ŭ������ ũ�� : %d\n", _msize(temp));
	temp -> age_b = age;
    temp -> money_b = money;

	// �Լ� ������ ���
	temp->this = temp;
	temp->set_money_child_b = set_money_b;
	temp->get_money_child_b = get_money_b;

	return temp;
}

// �Ҹ���
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

// ����Ʈ
void PrintInformation_(const struct Parent *this)
{
	printf("���� ���� : %d��, ���� �� : %d\n", this-> age_, this->money_);
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
	
    puts("ó���� ���� ���� �Ʒ��� �����ϴ�.");
    (*parent_ptr).this->PrintInformation(parent_ptr->this);
	
    parent_ptr->set_money(parent_ptr, 37, 50000);

    puts("���� ���� �ܾ��� ������ �����ϴ�.");
	parent_ptr->PrintInformation(parent_ptr);

	parent_money = parent_ptr->get_money(parent_ptr);
	printf("\t �� �ܾ��� %d���Դϴ�.\n", parent_money);

    // �Ҹ���
	DeleteParent(parent_ptr);

	puts("//////////////////////////////////////");
	Child_A *child_a_ptr = New_Child_A(12, 1000);
	puts("ù ��° �ڽ��� ���� ���� �Ʒ��� �����ϴ�.");
	(*child_a_ptr).parent.PrintInformation((Parent *)child_a_ptr);
	child_money = child_a_ptr->get_money_child_a(child_a_ptr);
	printf("\nù ��° �ڽ��� ���� ���� %d���̰� �θ� ������ �ִ� ���� %d�� �Դϴ�.\n", child_money, parent_money);
	DeleteChild_A(child_a_ptr);

    puts("//////////////////////////////////////");
	Child_B *child_b_ptr = New_Child_B(8, 500);
	puts("�ڽ��� ���� ���� �Ʒ��� �����ϴ�.");
	(*child_b_ptr).parent.PrintInformation((Parent *)child_b_ptr);
	child_money = child_b_ptr->get_money_child_b(child_b_ptr);
	printf("\n�� ��° �ڽ��� ���� ���� %d���̰� �θ� ������ �ִ� ���� %d�� �Դϴ�.\n", child_money, parent_money);
	DeleteChild_B(child_b_ptr);

	system("pause");
	return 0;
}

