#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char *argv[])
{
    printf("MySQL version : %s\n", mysql_get_client_info());
    exit(0);
}