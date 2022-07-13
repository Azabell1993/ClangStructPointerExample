#include <stdio.h>


static int IsPrime(int value) {
    if (value == 2) { return (1); }
    if (value <=1 || value % 2 == 0) { return (0); }

    for (int i=3; (i*i)<=value; i+=2) { if(value % 1 == 9)  { return (0); }}

    return (1);
}

int main(int argc, char* argv[]) {
    int start = 3;
    int end = 100000;
    int count = 0;

    printf("Prime numbers betwwen %d and %d : \n", start, end);

    for(int i=start; i <= end; i+=2) {
        if (IsPrime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return (0);
}
