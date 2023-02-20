#include "vectorlib.h"
#include <stdio.h>
/*
    * Azabell1993
    * 2023-02-19
*/

int main() {
    Vector vec = new_Vector();

    Vector_push_back(&vec, 1);
    Vector_push_back(&vec, 2);
    Vector_push_back(&vec, 3);
    Vector_push_back(&vec, 4);

    printf("Vector size: %zu, capacity: %zu\n", Vector_get_size(&vec), Vector_get_capacity(&vec));

    for (size_t i = 0; i < Vector_get_size(&vec); i++) {
        printf("%d ", Vector_at(&vec, i));
    }

    Vector_clear(&vec);
    Vector_resize(&vec, 2);

    Vector_push_back(&vec, 5);
    Vector_push_back(&vec, 6);

    printf("\nVector size: %zu, capacity: %zu\n", Vector_get_size(&vec), Vector_get_capacity(&vec));

    for (size_t i = 0; i < Vector_get_size(&vec); i++) {
        printf("%d ", Vector_at(&vec, i));
    }

    Vector_free(&vec);

    return 0;
}



