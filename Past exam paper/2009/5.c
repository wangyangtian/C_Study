#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MyItoa(int n, char a[], int *index) {
    if (n < 0) {
        a[(*index)++] = '-';
        n = -n;
    }
    if (n / 10 != 0) {
        MyItoa(n / 10, a, index);
    }
    a[(*index)++] = '0' + (n % 10);
    a[*index] = '\0';
}

int main() {
    char buffer[20];
    int index = 0;
    MyItoa(-12345, buffer, &index);
    printf("-12345 -> %s\n", buffer);
    return 0;
}