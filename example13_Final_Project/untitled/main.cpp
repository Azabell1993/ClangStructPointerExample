#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>

using namespace std;

char *printCut(char *str, int pos, bool directionHead = false) {
    uint8_t len = strlen(str);

    if (len > abs(pos)) {
        if(directionHead){
            if (pos > 0)
                str[pos-1] = 0;  // print front Nth -> front, +
            else
                str = str + pos;  // cut front Nth -> front, -
        } else if (!directionHead) {
            if (pos > 0)
                str = str + (len - pos);  // print back Nth -> back, +
            else
                str[len + pos] = 0;  // cut back Nth -> back,-
        }
    }
    print(str);
}

int main() {
    cout << printCut("hello", 5, true);
    return (0);
}