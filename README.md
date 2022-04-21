# ClangStructPointerExample  
  
## <u>example000_Notion_Clang</u>
노션에서 설명을 위한 리포지토리입니다. 간단한 소스코드들이 수록되어있습니다.  
   
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