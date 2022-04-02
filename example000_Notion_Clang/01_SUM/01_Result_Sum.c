#include <stdio.h>

// 구조체 구성
typedef struct _Result_Sum {
    // 필드 값
    int x;
    int y;
    int result;

    // 입,출력 메서드 
	int (*INPUT)(struct _Result_Sum *this, const int x,const int y,int result);
    int (*PUTS)(const struct _Result_Sum *this);
} SUM;

// 함수 전역 선언
int     SUM_INPUT       (struct _Result_Sum *this, const int x, const int y, int result);
int     SUM_RESULT      (const struct _Result_Sum *this);
void    SUM_INIT       (SUM *this);

// 입력 메서드
int /* 메서드 자료형 */  
SUM_INPUT /* 입력 메서드 함수명 */
(struct _Result_Sum *this, const int x, const int y, int result) /* 입력 메서드 피라메타에는 구조체 포인터와 필드 인자들을 넣어준다. */
{
    return this -> result = this -> x + this -> y;
}

// 출력 메서드
int /* 메서드 자료형 */
SUM_RESULT /* 출력 메서드 함수명 */
(const struct _Result_Sum *this) /* 출력 메서드 피라메타에는 구조체 포인터만 명시한다 .*/
{
    return
    (
        printf("%d + %d = %d\n",
        this -> x,
        this -> y,
        this -> result)
    );
}

// 생성자 선언 함수
void SUM_INIT(SUM *this) /* 이미 구조체안에 포인터로 선언이 되어있으므로 구조체 포인터만 명시한다. */
{
    this -> INPUT   = SUM_INPUT;
    this -> PUTS    = SUM_RESULT;
}

int main(int argc, char* argv)
{
    // 구조체 지역 선언
    SUM new_sum;

    // 생성자 지역 변수 선언
    new_sum.x = 10;
    new_sum.y = 20;
    new_sum.result = 0;

    // 생성자 함수 선언
    SUM_INIT(&new_sum);

    // 객체 메서드 출력
    new_sum.INPUT(&new_sum, new_sum.x, new_sum.y, new_sum.result);
    new_sum.PUTS(&new_sum);

    // 변수 변경
    new_sum.x = 20;
    new_sum.y = 30;
    // 객체 메서드 출력
    new_sum.INPUT(&new_sum, new_sum.x, new_sum.y, new_sum.result);
    new_sum.PUTS(&new_sum);
}
