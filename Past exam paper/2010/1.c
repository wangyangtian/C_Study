#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isLeap(int year) {
    return ((year % 4 == 0 && year % 100 != 100) || year % 400 == 0);
}

int whichDay(int year, int month, int day) {
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeap(year))
        d[1] = 29;

    int total = 0;
    for (int i = 0; i < month - 1; i++)
        total += d[i];

    return total + day;
}

int main() {
    printf("%d", whichDay(2024, 10, 23));
    return 0;
}