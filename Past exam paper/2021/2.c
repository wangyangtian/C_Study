#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int IsLeapLear(int year)
{
    if((year%4==0 &&year%100!=0)||year%400==0)
        return 1;
    else
        return 0;
}
void totalDays(int year,int month,int day)
{
    int days =day;
    int i;
    for(i=1;i<month;i++)//累加月份的天数
    {
        switch(i)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:days+=31;break;
            case 4:case 6:case 9:case 11:days+=30;break;
            case 2:days+=(IsLeapLear(year)+28);break;
        }
    }
    printf("此日期是%d年的第%d天",year,days);
}
int main(void)
{
    char str[10]={0};

    scanf("%s",str);
    int year=atoi(strtok(str,"/"));
    int month=atoi(strtok(NULL,"/"));
    int day=atoi(strtok(NULL,"/"));
    totalDays(year,month,day);
    return 0;
}