#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[] = "15+5.2+55";
    float num;
    int offset = 0;  // 用于记录当前的偏移量
    int charsRead;   // 用于存储每次读取的字符数

    while (sscanf(a + offset, "%f%n", &num, &charsRead) == 1) {
        printf("读取的数字: %f\n", num);
        printf("%d\n", charsRead);
        offset += charsRead;  // 更新偏移量，指向下一个未读字符
    }

    return 0;
}
