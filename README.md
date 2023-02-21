# 이 저장소 소개 
  
[![Top Langs](https://github-readme-stats.vercel.app/api/top-langs/?username=Azabell1993&hide_progress=true)](https://github.com/Azabell1993/ClangStructPointerExample.git)
  
C언어를 절차지향 사고에서 벗어나 객체지향 사고형으로 단련시켜주는 기본 소스코드 예제입니다.  
모든 예제 소스들은 Azabell1993이 직접 만들었습니다.  
특히, example11에서는 리눅스의 창시자이자 최대 기여자인 리누즈 토발즈가 1991년에 쓰던 문법과 유사한 C언어의 객체지향을 맛보실 수 있습니다.
필자 역시 C에서는 캡슐화와 인터페이스, 상속 이런 C보다 고급 언어에 있는 프로그래밍 키워드 및 용어 개념이 존재하지않기 때문에 직접 비슷한 기능들을 구사해보면서 하드웨어에 가까운 구조로 C++ 및 JAVA의 코드가 아닌 C언어로 컴퓨터에 대해서 좀 더 깊게 이해할 수 있었습니다.

이 저장소는 단순한 기본 예제들의 모읍입니다. 단순한 기본 예제이지만 잘 이해하면서 따라할 수 있다면 C언어 기반으로 객체지향의 패러다임을 온전히 이해하실 수 있을 것 입니다.
이 코드들은 구조체 포인터를 남용(?)하면서 여러 기법을 연구한 것을 구경하실 수 있는 저장소입니다.

# 이 저장소 목적
이 저장소의 목적은 말 그대로 C언어의 객체지향, 컴구의 이해를 한층 더 돞기 위한 연습이었습니다. 자료구조를 공부하였다면 더욱 이해가 쉬울 예제들입니다.
구조체 포인터를 특정한 디자인 패턴 없이 여러 패턴으로 작성하였기 때문에 실무에는 부접합하다고 생각이 됩니다. 다만, 실무에 있어서의 기본기 증진에는 탄탄한 발판이 되어준다고 생각합니다.

# ClangStructPointerExample  
길이 축약을 위해 메모리 해제 함수는 편의상 뺐습니다.  
  
## <u>example000_Notion_Clang</u>
노션에서 설명을 위한 리포지토리입니다. 간단한 소스코드들이 수록되어있습니다.  
  
아주 간단하게 소스코드 두 개를 예시로 들자면 아래와 같습니다.  
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
  
> 메인 클래스  
   
```

/*
    MEMBER 유사클래스 지역 함수
*/

typedef struct MEMBER {
    struct MEMBER* this;
    struct MEMBER_NAME* member_name;
    struct SCHOOL_NAME* school_name;

    struct MEMBER_NAME {
        struct MEMBER* this;
        int     select_name_number_;
        MEMBER_NAME* member_name;

        void    (*SET_NAME)(struct MEMBER_NAME* select_name, int select_name_number);
        int     (*GET_NAME)(const struct MEMBER_NAME* select_name);

        void    (*NAMEINIT)(MEMBER* name_init);
    } MEMBER_NAME;

    struct SCHOOL_NAME {
        struct MEMBER* this;
        int     select_school_number_;
        SCHOOL_NAME* school_name;

        void    (*SET_SCHOOL_NAME)(struct SCHOOL_NAME* select_school_name, int select_school_number);
        int     (*GET_SCHOOL_NAME)(const struct SCHOOL_NAME* select_school_name);

        void    (*SCHOOLINIT)(MEMBER* school_init);
    } SCHOOL_NAME;

    int     HAKBUN_;
    int     AGE_;
    int     INIT_DATE_;
    int     OUT_DATE_;

    void    (*PRINT_DATA)(const MEMBER* this, const MEMBER_NAME* select_name, const SCHOOL_NAME* select_school_name);
    void    (*MEMBER_SET)
        (
            struct MEMBER* this,
            struct MEMBER_NAME* select_name,
            struct SCHOOL_NAME* select_school_name,
            const   int     HAKBUN,
            const   int     AGE,
            const   int     INIT_DATE,
            const   int     OUT_DATE
            );
    int  (*MEMBER_GET)(const struct MEMBER* this, MEMBER_NAME* select_name, SCHOOL_NAME* select_school_name);
    /*
        void    NAME_INIT(struct MEMBER* this)
        void    SCHOOL_INIT(struct SCHOOL_NAME* this)
    */
} MEMBER;

```  
  

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
펑션 포인터 최적화를 해결 한 것은 example11_attribute__example/Second 로 가시면 있습니다.

## <u>example05_basic_stl</u>  
2023년부로 업데이트.
유사 객체지향 베이스로 유사 STL을 짠 라이브러리 리포지토리입니다.  
  
다이어그램은 참조를 한 곳이 따로 있으며, STL라이브러리 기능의 결과를 모방하여서 내장함수를 직접 구현하였습니다.  

```  
/*
    * Azabell1993
    * 2023-02-19
*/
#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
#define NORETERN _attribute_ ((_noreturn_))
    /* 함수 전방 선언 */
    static void ArrayList##_push_back(struct ArrayList* self, type value);
    static void ArrayList##_pop_back(struct ArrayList* self)      ;
    static type ArrayList##_at(const struct ArrayList* self, size_t index);
    static type* ArrayList##_data(const struct ArrayList* self);
    static size_t ArrayList##_size(const struct ArrayList* self);
    static size_t ArrayList##_capacity(const struct ArrayList* self);
    static void ArrayList##_reserve(struct ArrayList* self, size_t new_capacity);
    static void ArrayList##_resize(struct ArrayList* self, size_t new_size);
    static void ArrayList##_clear(struct ArrayList* self);
    static void ArrayList##_free(struct ArrayList* self);


    /* 비멤버 생성자 전방 선언 */
    static inline ArrayList new_##ArrayList();
#endif

#define DECLARE_ARRAY_LIST(ArrayList, type) \
                                            \
    struct ArrayList;                                                    \
    typedef struct ArrayList ArrayList;                                  \
                                                                    \
    struct ArrayList {                                                \
        type* buffer;                                               \
        size_t size;                                                \
        size_t capacity;                                            \
        void (*push_back)(struct ArrayList*, type);                      \
        void (*pop_back)(struct ArrayList*);                             \
        type (*at)(const struct ArrayList*, size_t);                     \
        type* (*data)(const struct ArrayList*);                          \
        size_t (*get_size)(const struct ArrayList*);                         \
        size_t (*get_capacity)(const struct ArrayList*);                     \
        void (*reserve)(struct ArrayList*, size_t);                      \
        void (*resize)(struct ArrayList*, size_t);                       \
        void (*clear)(struct ArrayList*);                                \
        void (*free)(struct ArrayList*);                                 \
    } ;                                                         \
                                            \
                                            \
    static void ArrayList##_push_back(struct ArrayList* self, type value) {   \
        if (self->size == self->capacity) {                         \
            size_t new_capacity = self->capacity * 2 + 1;            \
            self->buffer = (type*)realloc(self->buffer, new_capacity * sizeof(type)); \
            self->capacity = new_capacity;                          \
        }                                                            \
        self->buffer[self->size++] = value;                         \
    }                                                                \
                                                                     \
    static void ArrayList##_pop_back(struct ArrayList* self) {                 \
        if (self->size > 0) {                                        \
            --self->size;                                            \
        }                                                            \
    }                                                                \
                                                                     \
    static type ArrayList##_at(const struct ArrayList* self, size_t index) {   \
        if (index >= self->size) {                                   \
            return (type){0};                                        \
        }                                                            \
        return self->buffer[index];                                  \
    }                                                                \
                                                                     \
    static type* ArrayList##_data(const struct ArrayList* self) {              \
        return self->buffer;                                         \
    }                                                                \
                                                                     \
    static size_t ArrayList##_size(const struct ArrayList* self) {             \
        return self->size;                                           \
    }                                                                \
                                                                     \
    static size_t ArrayList##_capacity(const struct ArrayList* self) {         \
        return self->capacity;                                       \
    }                                                                \
                                                                     \
    static void ArrayList##_reserve(struct ArrayList* self, size_t new_capacity) { \
        if (new_capacity > self->capacity) {                         \
            self->buffer = (type*)realloc(self->buffer, new_capacity * sizeof(type)); \
            self->capacity = new_capacity;                          \
        }                                                            \
    }                                                                \
                                                                     \
    static void ArrayList##_resize(struct ArrayList* self, size_t new_size) {  \
        if (new_size > self->capacity) {                             \
            ArrayList##_reserve(self, new_size);                          \
        }                                                            \
        self->size = new_size;                                        \
    }                                                                   \
                                                                        \
    static void ArrayList##_clear(struct ArrayList* self) {                    \
        self->size = 0;                                              \
    }                                                                \
    \
    static void ArrayList##_free(struct ArrayList* self) {                     \
        free(self->buffer);                                          \
        self->buffer = NULL;                                         \
        self->size = self->capacity = 0;                             \
    }                                                                \
                                            \
    static inline ArrayList new_##ArrayList();                           \
    \
    static inline ArrayList new_##ArrayList() {                                \
        return (ArrayList) {                                              \
            .buffer = NULL,                                          \
            .size = 0,                                               \
            .capacity = 0,                                           \
            .push_back = ArrayList##_push_back,                           \
            .pop_back = ArrayList##_pop_back,                             \
            .at = ArrayList##_at,                                         \
            .data = ArrayList##_data,                                     \
            .get_size = ArrayList##_size,                            \
            .get_capacity = ArrayList##_capacity,                             \
            .reserve = ArrayList##_reserve,                               \
            .resize = ArrayList##_resize,                                 \
            .clear = ArrayList##_clear,                                   \
            .free = ArrayList##_free                                      \
        };                                                           \
    }
#ifdef __cplusplus
}
#endif //__cplusplus
#endif
```  
   



## <u>example07_inline_asm</u>  
유사 객체지향으로 인라인 어셈블리를 연습하기 시작하면서 만든 폴더입니다.  
기초부터 쌓아가면서 최종적으로 완성된 모습을 보실 수 있을 겁니다.  
개인적인 공부를 할 때에 클론을 해서 참조를 하십시오.  

> 기본 원형 첫번째 예제    
```
int    add(int x, int y)
{
    __asm {
        add esp, 20
        lea eax, [y]
        push eax
        lea ecx, [x]
        push ecx
        push offset[strScanf]

        push offset[addMessage]
        call dword ptr[printf]
        call dword ptr[scanf]
        add esp, 0Ch
        mov eax, [x]
        mov ebx, [y]
        add eax, ebx
        push eax
        push[y]
        push[x]
        push offset[strResultADD]
        call dword ptr[printf]
    }

    return;
}
```  
  
> 기본 원형 두번째 예제  
  
```  
typedef struct Calculator {
    int x;
    int y;
} CAL;

int Add(CAL* cal)
{
    int x, y;
    __asm
    {
        mov eax, cal
        mov eax, [eax]cal.x
        mov x, eax
        mov ebx, cal
        mov ebx, [ebx]cal.y
        mov y, ebx
        add eax, ebx
        mov x, eax
    }
    return x;
    
}

int main()
{
    CAL cal;
    cal.x = 20;
    cal.y = 10;
    printf("SUM : %d\n", Add(&cal));
}
```  

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
  
  
## <u>example11_attribute__example/Second</u>  
  
> 기본 원형 첫번째 예제    
```
#pragma once
#ifndef _PROGRAM_H
#define _PROGRAM_H
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

typedef struct Hello HE;


#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
#define NORETERN _attribute_ ((_noreturn_))
    void SAYHELLO_(struct Hello *this, int age);
    static inline __attribute__ ((visibility("hidden")))    void printHelloWorld();
    static inline __attribute__((visibility("default")))    void He_Printf_(const HE *this);
    static __attribute__ ((visibility("hidden")))           void (*registered_callback)();
    static __attribute__((visibility("default")))           void HelloWorld(void);
    static inline __attribute__ ((visibility("hidden")))    void setCallback(void (*callback)());
    static inline __attribute__ ((visibility("hidden")))    void callCallback();
    static inline __attribute__ ((visibility("hidden")))    void printHelloWorld();
    static inline __attribute__ ((visibility("default"))) void He_Printf_(const HE *this);
    void    HELLO_SET_(HE* this, const int age);
    int     HELLO_GET_(const struct Hello* this);
    static HE* new_Hello(int age_);
#endif

struct Hello {
    int age_;
    void (*SAYHELLO)(struct Hello *this, int age);
    void (*He_Printf)(const struct Hello *this);
    void (*registered_callback)();
    void (*HELLO_SET)(struct Hello * this, const int age);
    int  (*HELLO_GET)(const struct Hello* this);
    void (*HE_Printf)(const struct Hello *this);
};

static __attribute__ ((visibility("hidden"))) void (*registered_callback)();

static inline __attribute__ ((visibility("hidden"))) void setCallback(void (*callback)())
{
    registered_callback = callback;
}

static inline __attribute__ ((visibility("hidden"))) void callCallback()
{
    (*registered_callback)();
}

static inline __attribute__ ((visibility("hidden"))) void printHelloWorld()
{
    printf("This is a HelloWorld print function callback!!!\n");

}

static __attribute__((visibility("default"))) void HelloWorld(void) {
    GString *mystr = g_string_new("**** C Progammig Language Call Back Example ****!!!!\n");
    g_print(mystr->str, mystr->len);
    g_string_free(mystr, TRUE);
}

static inline __attribute__((visibility("default"))) void PrintHello1(struct Hello *this, int age) {
    this -> age_ = age;
    puts("Hello 1!!!");
    printf("Hello 1 age : %d\n", age);
}

static inline __attribute__((visibility("default"))) void PrintHello2(struct Hello *this, int age) {
    this -> age_ = age;
    puts("Hello 2!!!");
    printf("Hello 2 age : %d\n", age);
}

static inline __attribute__((visibility("default"))) void PrintHello3(struct Hello *this, int age) {
    this -> age_ = age;
    puts("Hello 3!!!");
    printf("Hello 3 age : %d\n", age);
}

void    HELLO_SET_(HE* this, const int age) {
    this -> age_ = age;
}
int     HELLO_GET_(const struct Hello* this) {
    return
            this -> age_;
}

static inline __attribute__ ((visibility("default"))) void He_Printf_(const HE *this) {
    HelloWorld();

    setCallback(printHelloWorld);
    callCallback();

    int age_ = this->age_;
    HE *helloObj = new_Hello(age_);

    PrintHello1(&(*helloObj),age_+10);
    PrintHello2(&(*helloObj),age_+20);
    PrintHello3(&(*helloObj),age_+30);
}

static HE* new_Hello(int age) {
    HE* temp = (HE*)malloc(sizeof(HE));
    temp->age_ = age;

    temp -> He_Printf = He_Printf_;
    temp -> HELLO_SET = HELLO_SET_;
    temp -> HELLO_GET = HELLO_GET_;

    return temp;
}

#ifdef __cheaderfile
#endif

#endif
```


> 기본 원형 두번째 예제(STL 라이브러리 기본 문법 코어설계)  

```
#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <memory.h>

#define class struct
#define public static __attribute__((visibility("default")))
#define private static __attribute__((visibility("hidden")))

#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
#define NORETERN _attribute_ ((_noreturn_))
    public void helloworld##_set_hello(helloworld *, type);
    public int helloworld##_get_hello(helloworld *);
#endif

#define say_hello(helloworld, type)                                                                         \
                                                                                                            \
    class helloworld;                                                                                       \
    typedef class helloworld helloworld;                                                                    \
                                                                                                            \
    class helloworld                                                                                        \
    {                                                                                                       \
        type age;                                                                                           \
                                                                                                            \
        void (*sethello)(helloworld *, type);                                                               \
        int (*gethello)(const helloworld *);                                                                \
    };                                                                                                      \
                                                                                                            \
    helloworld new_##helloworld(void);                                                                      \
                                                                                                            \
    public void helloworld##_set_hello(helloworld *self, type age)        				    \
    {                                                                                                       \
        self -> age = age;                                                                                  \
    }                                                                                                       \
                                                                                                            \
    public int helloworld##_get_hello(const helloworld *self)        					    \
    {                                                                                                       \
        return printf("my age : %d\nHello World!!!!!!\n", self->age);                                       \
    }                                                                                                       \
                                                                                                            \
    helloworld new_##helloworld(void)                                                                       \
    {                                                                                                       \
       	static helloworld temp =                                                                            \
            {                                                                                               \
                .age = 0,                                                                                   \
                .sethello = helloworld##_set_hello,                                                         \
                .gethello = helloworld##_get_hello,                                                         \
            };                                                                                              \
        return temp;                                                                                        \
    }
#endif                                                                                           
