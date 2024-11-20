#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int total = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        total += i;
    }
    printf("非平凡字串数目为%d\n", total);
    return 0;
}