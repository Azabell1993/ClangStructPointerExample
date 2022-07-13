#include <stdio.h>
#include <emscripten/emscripten.h>

int main(int argc, char ** argv) {
}

#ifdef __cplusplus
extern "C" {
#endif

static int EMSCRIPTEN_KEEPALIVE fnc(int num) {
    return num * num;
}

static int EMSCRIPTEN_KEEPALIVE add(int a, int b) {
	return a + b;
} 

#ifdef __cplusplus
}
#endif
