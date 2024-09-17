#include <stdio.h>

void MyItoa(int n, char* s) {
    int digit = 0;
    int temp = n;
    int isNegative = 0;

    // 处理负数
    if (n < 0) {
        isNegative = 1;
        n = -n;  // 取绝对值
    }

    // 处理 n == 0 的情况
    if (n == 0) {
        s[digit++] = '0';
    } else {
        // 计算数字的位数
        while (temp != 0) {
            digit++;
            temp /= 10;
        }
    }

    // 若是负数，则需要多一位存储 '-'
    if (isNegative) {
        digit++;  // 为负号预留空间
    }

    s[digit] = '\0';  // 添加字符串终止符

    // 从最后一位开始填充数字字符
    for (int i = digit - 1; i >= (isNegative ? 1 : 0); i--) {
        s[i] = n % 10 + '0';
        n /= 10;
    }

    // 添加负号
    if (isNegative) {
        s[0] = '-';
    }
}

int main() {
    char s[20];  // 假设字符串足够长存储结果
    MyItoa(-1234, s);
    printf("%s\n", s);  // 输出 "-1234"
    
    MyItoa(0, s);
    printf("%s\n", s);  // 输出 "0"
    
    MyItoa(5678, s);
    printf("%s\n", s);  // 输出 "5678"

    return 0;
}
