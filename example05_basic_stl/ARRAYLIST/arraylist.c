/*
    * Azabell1993
    * 2023-02-19
*/
#include "arraylist.h"
#include <stdio.h>
DECLARE_ARRAY_LIST(ArrayList, int);

int main() {
    ArrayList list = new_ArrayList();

    // Add some elements to the list
    list.push_back(&list,1);
    list.push_back(&list,2);
    list.push_back(&list,3);

    // Print the list contents
    printf("List contents:\n");
    list.size;
    for (size_t i = 0; i < list.get_size(&list); i++) {
        printf("%d\n", list.at(&list, i));
    }

    // Clear the list
    list.clear(&list);

    // Add some more elements to the list
    list.push_back(&list, 4);
    list.push_back(&list, 5);

    // Print the list contents again
    printf("List contents:\n");
    for (size_t i = 0; i < list.get_size(&list); i++) {
        printf("%d\n", list.at(&list, i));
    }

    // Free the list
    list.free(&list);

    return 0;
}