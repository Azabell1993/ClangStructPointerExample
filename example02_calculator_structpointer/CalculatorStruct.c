#include "CalculatorStruct.h"

int main()
{
    // ù��° ��ü ����
    struct _CALC_DATA test;
    // �ʵ� -> ��ü�� �����Ͱ� ����Ǵ� ��
    test.operand1 = 10;
    test.operand2 = 30;
    test.operator = '+'; 
    test.result=0; 
    // ������ ȣ�� -> ��ü ���� �� �ʱ�ȭ ���� ���
    Init(&test);
    // ��� / �޼��� -> ��ü�� ���ۿ� �ش��� ���� ���
    test.SETCUL(&test, test.operand1, test.operand2, test.operator, test.result);
    test.GETCUL(&test);
    //�Ҹ���
    Destory(&test);

    // �ι�° ��ü ����
    struct _CALC_DATA test2;
    test2.operand1 = 110;
    test2.operand2 = 100;
    test2.operator = '-';
    test2.result = 0; 
    // ������ ȣ��
    Init(&test2);
    // ���
    test2.SETCUL(&test2, test2.operand1, test2.operand2, test2.operator, test2.result);
    test2.GETCUL(&test2);
    //�Ҹ���
    Destory(&test2);

    // ����° ��ü ����
    struct _CALC_DATA test3;
    test3.operand1 = 30;
    test3.operand2 = 100;
    test3.operator = '*';
    test3.result = 0; 
    // ������ ȣ��
    Init(&test3);
    // ���
    test3.SETCUL(&test3, test3.operand1, test3.operand2, test3.operator, test3.result);
    test3.GETCUL(&test3);
    //�Ҹ���
    Destory(&test3);
    
    // �׹�° ��ü ����
    struct _CALC_DATA test4;
    test4.operand1 = 20;
    test4.operand2 = 100;
    test4.operator = '/';
    test4.result=0; 
    // ������ ȣ��
    Init(&test4);
    // ���
    test4.SETCUL(&test4, test4.operand1, test4.operand2, test4.operator, test4.result);
    test4.GETCUL(&test4);
    //�Ҹ���
    Destory(&test4);
}