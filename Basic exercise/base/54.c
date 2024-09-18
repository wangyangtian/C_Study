#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data {
    int year;
    int month;
    int day;
} Data;

bool IsLeapYear(Data d) {
    return ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0);
}

int WhichDay(Data d) {
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    if(IsLeapYear(d))   m[1]=29;
    for(int i=0;i<d.month-1;i++){
        sum+=m[i];
    }
    sum+=d.day;
    return sum;
}

int NumberOfDay(Data d) {
    if (IsLeapYear(d))
        return 366;
    else
        return 365;
}

int DaysApart(Data d1,Data d2){
    int daysapart;
    for(int i=d1.year;i<d2.year;i++){
        daysapart+=NumberOfDay(d1);
        d1.year++;
    }
    daysapart += abs(WhichDay(d1)-WhichDay(d2));
    return daysapart;
}

int main() {
    Data d1;
    Data d2;
    printf("输入日期1:");
    scanf("%d%d%d",&d1.year,&d1.month,&d1.day);
    printf("%d 年的第 %d 天\n",d1.year,WhichDay(d1));
    printf("输入日期2:");
    scanf("%d%d%d",&d2.year,&d2.month,&d2.day);
    printf("两日期相隔 %d 天。",DaysApart(d1,d2));
    return 0;
}