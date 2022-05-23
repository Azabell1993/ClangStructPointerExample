#include <glib.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _Hello {
	void (*helloPrintStr)();
} HELLOWORLD;

static inline void hello() {
	GString *hello_str = "Hello World! Struct Message!!!\n";
	g_print(g_hello_str -> str, g_hello_str-> len);
}

int main() {
	hello();

    GString *glib_string = g_string_new(NULL);
    glib_string = g_string_assign(glib_string, "Hello, world");
    printf("%s\n", glib_string->str);

    return 0;
}
