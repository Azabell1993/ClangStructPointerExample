//
// Created by azabell on 2022/05/18.
//
#include "print_message.h"
#include <glib.h>
void print_message(gchar *g_str) {
    g_print("%s\n", g_str);
    return ;
}