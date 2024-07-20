#include <stdio.h>
int main()
{
    char a[5] = {0};
    char c;
    int count = 0;
    while ((c = getchar()) != '\n')
    {
        a[count++] = c;
    }
    printf("%d\n", count); // 输出字符个数
    for (int i = count; i > 0; i--)
    {
        printf("%c", a[i - 1]);
    }
}
// int main()
// {
//     int num, reversed_num = 0, remainder;
//     scanf("%d", &num);
//     while (num != 0)
//     {
//         remainder = num % 10;
//         reversed_num = reversed_num * 10 + remainder;
//         num /= 10;
//     }
//     printf("%d\n", reversed_num);
//     return 0;
// }