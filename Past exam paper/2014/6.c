#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getRange(char *s, int n) {
    char a, b, c;
    for (int i = 0; i < n; i++) {
        a = s[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                b = s[j];
                for (int k = 0; k < n; k++) {
                    if (k != j && k != i) {
                        c = s[k];
                        printf("%c %c %c\n", a, b, c);
                    }
                }
            }
        }
    }
}

int main() {
    char s[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
    getRange(s, 7);
    return 0;
}