#pragma once
#ifndef IF_H
#define IF_H

#include <stdio.h>

// ����ü ����
typedef struct _Calculator {
    // �ʵ� ��
    const char operator; 
    double x;
    double y;
    double result;
    /* ������ ĳ���ʹ� �������̹Ƿ� �Ʒ��� ����/���� �Լ����� �޼��忡�� const�� ������� �ʴ´�.*/

    // ��,��� �޼��� 
	double (*INPUT)(struct _Calculator *this, const double x,const double y,double result,char operator);
    double (*PUTS)(const struct _Calculator *this);
} CAL;

// �Լ� ���� ����
double     CAL_INPUT       (struct _Calculator *this, const double x, const double y, double result,char operator);
double     CAL_RESULT      (const struct _Calculator *this);
void       CAL_INIT       (CAL *this);

// �Է� �޼���
double /* �޼��� �ڷ��� */  
CAL_INPUT /* �Է� �޼��� �Լ��� */
(struct _Calculator *this, const double x, const double y, double result,char operator) /* �Է� �޼��� �Ƕ��Ÿ���� ����ü �����Ϳ� �ʵ� ���ڵ��� �־��ش�. */
{
    if (this->operator == '+')
        return this -> result = this -> x + this -> y;
    else if(this->operator == '-')
        return this -> result = this -> x - this -> y;
    else if(this->operator == '/')
        return this -> result = this -> x / this -> y;
    else if(this->operator == '*')
        return this -> result = this -> x * this -> y;
    else
        return puts("����ó��");
}

// ��� �޼���
double /* �޼��� �ڷ��� */
CAL_RESULT /* ��� �޼��� �Լ��� */
(const struct _Calculator *this) /* ��� �޼��� �Ƕ��Ÿ���� ����ü �����͸� ����Ѵ� .*/
{
    return
    (
        printf("%.2f %c %.2f = %.2f\n",
        this -> x,
        this -> operator,
        this -> y,
        this -> result)
    );
}

// ������ ���� �Լ�
void CAL_INIT(CAL *this) /* �̹� ����ü�ȿ� �����ͷ� ������ �Ǿ������Ƿ� ����ü �����͸� ����Ѵ�. */
{
    this -> INPUT   = CAL_INPUT;
    this -> PUTS    = CAL_RESULT;
}

#endif