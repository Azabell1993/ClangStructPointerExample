//EMSCRIPTEN_KEEPALIVE
#include "addFunction.h"
#include <stdio.h>
#include <emscripten.h>

int AddResult(int numA, int numB);

#ifdef __cplusplus
extern "C" {
#endif

say_add(addFunction , int)

EMSCRIPTEN_KEEPALIVE 
int AddResult(int numA, int numB)
{
    addFunction add = new_addFunction();
    add.setAdd(&add, numA, numB);
    int result = add.getAdd(&add); 
    return (result);  
}

#ifdef __cplusplus
}
#endif

//emcc addFunction.c -o add.wasm --no-entry