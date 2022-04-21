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

