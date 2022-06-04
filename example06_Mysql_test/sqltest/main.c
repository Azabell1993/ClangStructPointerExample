#include <mysql.h>
#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <gtk/gtk.h>

#define DB_HOST "localhost"
#define DB_USER "root"
#define DB_PASS "dkwkqpf.12"
#define DB_NAME "azabell_mysqlDB"
#define CHOP(x) x[strlen(x) - 1] = ' '

static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
    g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;

    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    button = gtk_button_new_with_label ("Hello World");

    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);

    gtk_window_set_child (GTK_WINDOW (window), button);

    gtk_window_present (GTK_WINDOW (window));
}

int
main (int    argc,
      char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}