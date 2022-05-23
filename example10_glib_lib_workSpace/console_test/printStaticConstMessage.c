//
// Created by azabell on 2022/05/20.
//

#ifndef INC_01_HELLO_PRINTSTATICCONSTMESSAGE_C
#define INC_01_HELLO_PRINTSTATICCONSTMESSAGE_C
#include <glib.h>
#include <stdio.h>
#include "mesage.h"
void g_print_static_constMesage(void) {
    GString *cat3_fun_message_str = g_string_new("Called Function : %s ");
    g_string_printf(cat3_fun_message_str->str, g_constMessage);

}
#endif //INC_01_HELLO_PRINTSTATICCONSTMESSAGE_C

