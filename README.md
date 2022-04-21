# ClangStructPointerExample  
  
## <u>example000_Notion_Clang</u>
노션에서 설명을 위한 리포지토리입니다. 간단한 소스코드들이 수록되어있습니다.  
  
아주 간단하게 소스코드 두개를 예시로 들자면 아래와 같습니다.  
> helloworld 기본 출력 소스코드  
  
```
#include <stdio.h>

// 구조체 구성
typedef struct _Hello {
    // 필드 값

    // 입,출력 메서드 
		// 입력할 인자가 없으므로 출력할 메서드만 선언
    void (*HELLO)();
} HELLOWORLD;

// 함수 전역 선언
void HELLO_PRINT(); /* 피라메타 비어두기 */
void HELLO_INIT(HELLOWORLD *this); /* 구조체 포인터 */

// 출력 메서드
void/* 메서드 자료형 */  
HELLO_PRINT /* 메서드 이름 */ ( /* 넣을 인자 값이 없음 */  )
{
    // printf 대체 출력 함수
    puts("Hello World");
}

// 생성자 선언 함수
void HELLO_INIT(HELLOWORLD *this)
{
		// 아래 두가지 표현식이 동일하게 작동
    // this -> HELLO = HELLO_PRINT;
    (*this).HELLO = HELLO_PRINT;
}

void main(int argc, char* argv)
{
    // 구조체 지역 선언
    HELLOWORLD HELLO;
    // 생성자 선언
    HELLO_INIT(&HELLO);

    // 아래 동일한 출력 함수
    // HELLO_PRINT(&HELLO);
    HELLO.HELLO();
}
```  
  
> sum 내장함수 객체지향 소스코드  
  
```
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
    SUM_INIT(&this);
    this.INPUT(&this, this.x, this.y, this.result);
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
```  
  
## <u>example04_Inher</u>  
유사 객체지향 구현 파일 : inher_class_B.c  
  
### 부모 클래스내 상속 호출 ###  
```
    // 빌드 테스트시 적용 확인 메세지 띄우기
    puts("이 메세지가 보이면 적용 성공임..");

    // 부모 유사 클래스 MEMBER에 상속된 클래스 지역 선언
    MEMBER_NAME nameOuterObj;
    SCHOOL_NAME schoolOuterObj;

    // 유사 자식 클래스 함수 포인터 인수 반환 값 선언
    //nameOuterObj.select_name_number_ = 2;
    printf("반환할 함수포인터의 인수값을 입력하시오 : ");
    scanf("%d", &nameOuterObj.select_name_number_);

    // 부모 유사 클래스 MEMBER에 상속된 자식 클래스 new 생성자 호출
    MEMBER_NAME* nameObj = new_name(&nameOuterObj.select_name_number_);
    SCHOOL_NAME* schoolObj = new_school(&schoolOuterObj.select_school_number_);

    // MEMBER 부모 클래스 생성자 호출 , 자식 클래스 nameObj, schoolObj를 반드시 선언해야 부모 클래스 메서드가 호출이 됨.
    MEMBER* memOuterObj = new_member(3081, nameObj, schoolObj, 30, 20140201, 20190301);

    // 자식 클래스의 생성자 호출, 이름과 학교 이름이 동시에 출력이 되도록 생성자를 전방에서 선언해둠.
    NAME_INIT(nameObj);
    NAME_SET_(nameObj, nameOuterObj.select_name_number_);
    NAME_GET_(nameObj);

    // 값이 유동적으로 변함(변수임) -- 원하는 변수 값을 넣어주면 된다. 또는, 반대로 scanf함수로 입력받게 하고 구조체를 하나 더 만든다던지 하면
    // 효과적으로 객체들을 자료구조로 다룰 수 있음.
    (*memOuterObj).HAKBUN_ = 2187;

    /*
        MEMBER 출력 메서드 출력, 위에서 전역으로 선언해둔 자식 클래스를 끌어서 가져와야한다.
    */
    (*memOuterObj).PRINT_DATA(memOuterObj, nameObj, schoolObj);

    // 변경 적용 예 -- new생성자에 삽입을 해서 출력을 할 수 있지만, 아래의 변수 선언처럼 언제든지 변경 또한 가능하도록 설계.
    /*
        (*memOuterObj).AGE_ = 30;
        (*memOuterObj).INIT_DATE_ = 20140201;
        (*memOuterObj).OUT_DATE_ = 20190301;
    */
```  
   
https://github.com/Azabell1993/ClangStructPointerExample/blob/6890848d7faefc3ab5c72a7caf20c7da0c2ed701/example04_Inher/inher_class_B.c#L902  
  
### 생성자 호출 ##  
```  
PROGRAMMING* programOuterObj = new_programming(20200221, 20, 20, 20, 20, 20, 20, 20, 20);
    (*programOuterObj).PROGRAMMING_PRINT_DATA(programOuterObj);
```  
    
https://github.com/Azabell1993/ClangStructPointerExample/blob/6890848d7faefc3ab5c72a7caf20c7da0c2ed701/example04_Inher/inher_class_B.c#L945

본 코드는 펑션 포인터 최적화가 잘 되어있지 않기 때문에  
> gcc -W -Wall -Wextra -Werror -Wformat  
  
위와 같은 컴파일러 옵션을 넣으면 펑션 포인터 오류가 많이 나옵니다.  
  
> gcc main.c -o main  
  
따위로 돌리거나 비주얼스튜디오에서 그냥 빌드하시면 됩니다.  

## <u>example05_basic_stl</u>  
유사 객체지향 베이스로 유사 STL을 짠 라이브러리 리포지토리입니다.  
![AzabellClangSTL_LIB](https://user-images.githubusercontent.com/75885992/163935905-badd1118-25e7-450f-8995-7db114dfbf6e.png)  
  
다이어그램은 참조를 한 곳이 따로 있으며, STL라이브러리 기능의 결과를 모방하여서 내장함수를 직접 구현하였습니다.  
  
### 접근 제한자 ###  
  
```  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 해당 함수가 라이브러리 외부에 노출이 되며, 해당 함수를 라이브러리 외부에서 호출 할 수 있다.
// 라이브러리를 링크하는 애클리케이션에서 해당 함수를 호출 할 수 있다.
void __attribute__((visibility("default"))) testFunc1()
{

}

// 해당 함수가 라이브러리 외부에 노출이 않으며, 해당 함수를 라이브러리 외부에서 호출 할 수 없다.
// 라이브러리를 링크하는 애클리케이션에서 해당 함수를 호출 할 수 없다.
void __attribute__((visibility("hidden"))) testFunc2()
{

}
  
```  