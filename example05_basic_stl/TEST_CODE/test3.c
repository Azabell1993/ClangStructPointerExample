#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma warning(disable:4996)
#define max 30
typedef int element;
typedef struct {
    element array[max];
    int size;
}ArrayListType;
typedef ArrayListType * ArrayList_ptr;

static int		az_pow(int nb, int pow);
char			*az_itoa(int value, int base);
int		        az_atoi(const char *s);
char	        *az_itoa(int value, int base);
static int		az_pow(int nb, int pow);
int    sort(int arr[], int count);
void    returnSort(int arr[], int size);

// 리스트 초기화
void init(ArrayList_ptr list) {
    list->size = 0;
}

// 리스트 생성
ArrayList_ptr create() {
    return (ArrayList_ptr)calloc(1, sizeof(ArrayListType));
}

// 빈 리스트 확인
int is_empty(ArrayList_ptr list) {
    if (list->size == 0)
        return 1;
    else
        return 0;
}

// 풀 리스트 확인
int is_full(ArrayList_ptr list) {
    if (list->size == max)
        return 1;
    else
        return 0;
}

// 아이템 삽입
void insert_last(ArrayList_ptr list, element item) {
    if (!is_full(list)) {
        int pos = list->size;
        list->array[pos] = item;
        list->size++;
    }
    else
        printf("리스트가 꽉 차있습니다\n");
}

// 아이템 삭제
void delete_last(ArrayList_ptr list) {
    if (!is_empty(list)) {
        list->size--;
    }
    else
        printf("리스트가 비어 있습니다\n");
}

// 인덱스로 아이템 삭제 
void delete_idx(ArrayList_ptr list, int pos) {
    if (!is_empty(list)) {
        element tmp = list->array[pos];
        for (int i = pos + 1; i < list->size; i++)
            list->array[i - 1] = list->array[i];
        list->size--;
    }
    else
        printf("리스트가 비어 있습니다\n");
}

// 리스트 출력 
void print_list(ArrayList_ptr list) {
    if (!is_empty(list)) {
        for (int i = 0; i < list->size; i++)
            if(list->array[i] >= 65 && list->array[i] <= 90) {
                printf("[%c] ", list->array[i]);    
            } else {
                printf("[%d] ", list->array[i]);
            }
    }
    else
        printf("리스트가 비어 있습니다\n");
}

static int	az_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * az_pow(nb, pow - 1));
}

// 정수형을 문자형으로 변환
char	*az_itoa(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	//10진수
	//base = 10..

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}

	while (az_pow(base, i) - 1 < value)
		i++;

	nbr = (char*)malloc(sizeof(nbr) * i);

	nbr[i + neg] = '\0';

	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
		
	return (nbr);
}

// 문자열을 정수형으로 변환
int		az_atoi(const char *s)
{
	int		i;
	int		conv;
	int		res;
	int		neg_chk;

	i = 0;
	conv = 0;
	
	neg_chk = 1;

	if (s == NULL)
		return (0);

	if (s[i] == '-')
	{
		neg_chk = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;

	while (s[i] >= 48 && s[i] <= 57)
	{
		conv = conv * 10 + s[i++] - 48;
	}
	res = conv * neg_chk;
	return (res);
}

int    sort(int arr[], int count)
{
    int temp;

    for(int i=0; i<count; i+=1) {
        for(int j=0; j<count-1; j+=1) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j]  = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return *arr;
}

void    returnSort(int arr[], int size) 
{
    for(int i=0; i<size; i+=1) {
        printf("%d ", arr[i]);
    }
}

int main() {
    ArrayList_ptr list = create();

    // int test1Value;
    // char *test1 = "jiwoo1";
    // //strcpy(test1Value, test1);
    // test1Value = az_atoi(test1);

    insert_last(list, 'A'); // [1]
    insert_last(list, 'B'); // [1 2]
    insert_last(list, 3333); // [1 2]
    insert_last(list, 333); // [1 2]
    print_list(list); // 리스트 요소 출력 
    puts("");
    
    ArrayList_ptr completion = create();
    insert_last(completion, 'A');
    insert_last(completion, 'B');
    insert_last(completion, 'D');
    insert_last(completion, 'E');
    print_list(completion);
    puts("");

    int sortTest[] = {1,7,5,4,2,3,6,9,8,5,4,7,20};
    sort(sortTest, sizeof(sortTest)/sizeof(int));
    returnSort(sortTest, sizeof(sortTest)/sizeof(int));

    puts("");
    int sortTest2[9] = {8,1,4,7,5,3,2,6,9};
    sort(sortTest2, sizeof(sortTest2)/sizeof(int));
    returnSort(sortTest2, sizeof(sortTest2)/sizeof(int));
    ArrayList_ptr sortTest2_ptr = create(sortTest2);
    //print_list(sortTest1);

    puts("");
    int sortTest3[5] = {8,1,4,7,9};
    sort(sortTest3, sizeof(sortTest3)/sizeof(int));
    returnSort(sortTest3, sizeof(sortTest3)/sizeof(int));
    ArrayList_ptr sortTest3_ptr = create(sortTest3);
    //print_list(sortTest1);

    puts("");
    char Save[1024];
    for (int i = 0; i < sizeof(sortTest2); i += 1) {
        if (sortTest2 != sortTest3) {
            continue;
        } else {
            Save[i] == sortTest2;
        }
    }

    for(int i=0; i<sizeof(sortTest2); i+=1) {
        printf("%d ", Save[i]);
    }

    // insert_last(list, 1); // [1]
    // insert_last(list, 2); // [1 2]
    // insert_last(list, 3); // [1 2 3]
    // insert_last(list, 4); // [1 2 3 4]
    // insert_last(list, 5); // [1 2 3 4 5]
    // delete_last(list); // [1 2 3 4]
    // delete_last(list); // [1 2 3]
    // delete_idx(list, 0); // [2 3]
    // insert_last(list, 4); // [2 3 4]
    // delete_idx(list, 1); // [2 4]
    // print_list(list); // 리스트 요소 출력 
}