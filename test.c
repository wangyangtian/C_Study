#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

void change(int* a)
{
    *a=*a*5;
}
int main(void)
{
    int x=5;
    change(&x);
    printf("%d",x);
    return 0;
}