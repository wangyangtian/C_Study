#include <stdbool.h>
#include <stdio.h>

// 判断是否为素数
bool isPrime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    FILE* fp = fopen("out.dat", "w");  // 使用文本模式写入
    if (fp == NULL) {
        perror("文件打开失败");
        return 1;
    }

    int count = 0, sum = 0;

    // 查找符合条件的素数
    for (int i = 2; i <= 200; i++) {
        if (isPrime(i) && isPrime(i + 4) && isPrime(i + 10)) {
            fprintf(fp, "%d ", i);  // 写入文件
            count++;
            sum += i;
        }
    }

    // 写入总和和计数
    fprintf(fp, "\nsum: %d\ncount: %d\n", sum, count);

    fclose(fp);  // 关闭文件
    return 0;
}
