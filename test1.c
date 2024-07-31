#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool judge(char* ch) {
    int i = 0;
    int sign = 0;
    int count_I = 0, count_O = 0;
    while (ch[i] != '\0') {
        if (ch[i] == 'I') {
            sign++;
            count_I++;
        }
        if (ch[i] == 'O') {
            sign--;
            count_O++;
        }
        if (sign < 0)
            return false;
        i++;
    }
    if (count_I != count_O)
        return false;
    return true;
}

int main() {
    char ch[]="IIOOOI";
    if(judge(ch))
        printf("vaild\n");
    else
        printf("invalid\n");
    return 0;
}