#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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
    int year1, year2, month1, month2, day1, day2;
    printf("输入开始时间(year/month/day)：\n");
    scanf("%d/%d/%d", &year1, &month1, &day1);
    printf("输入结束时间(year/month/day)：\n");
    scanf("%d/%d/%d", &year2, &month2, &day2);
    int gap = whichDay(year2, month2, day2) - whichDay(year1, month1, day1);
    printf("相差%d天\n", gap);

    return 0;
}