#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define max 30
typedef int element;
typedef struct {
    element array[max];
    int size;
}ArrayListType;
typedef ArrayListType * ArrayList_ptr;

// ����Ʈ �ʱ�ȭ
void init(ArrayList_ptr list) {
    list->size = 0;
}

// ����Ʈ ����
ArrayList_ptr create() {
    return (ArrayList_ptr)calloc(1, sizeof(ArrayListType));
}

// �� ����Ʈ Ȯ��
int is_empty(ArrayList_ptr list) {
    if (list->size == 0)
        return 1;
    else
        return 0;
}

// Ǯ ����Ʈ Ȯ��
int is_full(ArrayList_ptr list) {
    if (list->size == max)
        return 1;
    else
        return 0;
}

// ������ ����
void insert_last(ArrayList_ptr list, element item) {
    if (!is_full(list)) {
        int pos = list->size;
        list->array[pos] = item;
        list->size++;
    }
    else
        printf("����Ʈ�� �� ���ֽ��ϴ�\n");
}

// ������ ����
void delete_last(ArrayList_ptr list) {
    if (!is_empty(list)) {
        list->size--;
    }
    else
        printf("����Ʈ�� ��� �ֽ��ϴ�\n");
}

// �ε����� ������ ���� 
void delete_idx(ArrayList_ptr list, int pos) {
    if (!is_empty(list)) {
        element tmp = list->array[pos];
        for (int i = pos + 1; i < list->size; i++)
            list->array[i - 1] = list->array[i];
        list->size--;
    }
    else
        printf("����Ʈ�� ��� �ֽ��ϴ�\n");
}

// ����Ʈ ��� 
void print_list(ArrayList_ptr list) {
    if (!is_empty(list)) {
        for (int i = 0; i < list->size; i++)
            printf("[%d] ", list->array[i]);
    }
    else
        printf("����Ʈ�� ��� �ֽ��ϴ�\n");
}

int main() {
    ArrayList_ptr list = create();
    init(list);
    insert_last(list, 1); // [1]
    insert_last(list, 2); // [1 2]
    insert_last(list, 3); // [1 2 3]
    insert_last(list, 4); // [1 2 3 4]
    insert_last(list, 5); // [1 2 3 4 5]
    delete_last(list); // [1 2 3 4]
    delete_last(list); // [1 2 3]
    delete_idx(list, 0); // [2 3]
    insert_last(list, 4); // [2 3 4]
    delete_idx(list, 1); // [2 4]
    print_list(list); // ����Ʈ ��� ��� 
}