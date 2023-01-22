/*
 * PRINT.h
 *
 *  Created on: 2022. 11. 9.
 *      Author: jeewo
 */
#pragma ONCE
#ifndef PRINT_H_
#define PRINT_H_
#include <stdio.h>
#include <stdlib.h>
#ifdef __cheaderfile
extern "C" {
#endif
#ifndef BUILD_MY_DLL
#define SHARED_LIB __declspec(dllexport)
#else
#define SHARED_LIB __declspec(dllexport)
#endif
#ifdef _GNUC_
typedef int (*_cloud)(const int *dream, char *return_contents);
	int return_dream(const int *dream, const char *return_contents);
	int main(int argc, char *argv[]);
#endif
typedef int (*_cloud)(const int *dream, char *return_contents);

#define PARK_HEADER                     \
    int *mydream;                       \
    char *return_contents;              \
    _cloud  update;                     \

#define DECL_PARK(DREAM, RETURN_FUNCTION) struct {  \
    PARK_HEADER;                                    \
} DEFINE_NAME(NAME, RETURN_FUNCTION)

#define RETURN_FUNCTION(DREAM, RETURN_CONTENTS) \
DECL_PARK(NAME, RETURN_FUNCTION) = {            \
}

// C로 짠 Lib를 C++로 Porting하기 위해서는 typedef struct를 제외한다.
struct CLOUD {
    int *mydream;
    char *return_contents;
    int (*_cloud)(const int *,  char *);
} ;


__cdecl int return_dream(const int *dream, const char *return_contents) {
    struct CLOUD *cloud;
    // const 없이는 char로 C style 문자열 불가
    // const로 자료형을 지정해주면 빌드 후에 출력됨
    return_contents = "Hello World\n";
    if(sizeof(*cloud->mydream) == 4)
        return (printf("%s\n",return_contents));
}
#endif

#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
PARK_HEADER

typedef int (*_main)(int argc, char *argv[]);

#define PRINTF              \
    _main PRINTF            \

#define PRINF_FUNCTION(ARGC, ARGV) struct {   \
    PRINTF;                                   \
} DEFINE_PRINTF(ARGC, ARGV)

#define RETURN_PRINTF(ARGC, ARGV) \
PRINF_FUNCTION(ARGC, ARGV) = {    \
}

/*
	@parm
*/
int __cdecl main(int argc, char *argv[]) {
    return_dream(mydream, return_contents);
    return 0;
}

#ifdef __headerfile
}
#endif
#endif /* PRINT_H_ */
