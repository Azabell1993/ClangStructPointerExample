#include <glib.h>
#include <stdio.h>
#include "message.h"

int main() {
    GString *my_string = g_string_new("StaticConstDemo");
    g_print(my_string->str, my_string->len);

    GString *main_fun_message_str = g_string_new("Main Function :");
    g_print(main_fun_message_str->str, main_fun_message_str->len);

    GString *cat_fun_message_str = g_string_new("Message : %s");
    g_print(cat_fun_message_str->str, cat_fun_message_str->len);

    GString *cat2_fun_message_str = g_string_new("Const Message Test : %s");
    g_string_printf(cat2_fun_message_str->str, g_constMessage);

    g_print_static_constMesage();

    return EXIT_SUCCESS;
}

