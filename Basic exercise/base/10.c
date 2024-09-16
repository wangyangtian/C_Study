#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch;
    scanf("%c", &ch);
    if (ch >= 'A' && ch <= 'Z')
        ch = ch - ('A' - 'a');
    printf("%c", ch);
    return 0;
}