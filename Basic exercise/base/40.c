#include <stdio.h>
#include <math.h>

int main() {
    // 遍历所有可能的 a 和 b
    for (int a = 1; a <= 100; a++) {
        for (int b = a + 1; b <= 100; b++) {
            // 计算 c = sqrt(a^2 + b^2)
            int c = sqrt(a * a + b * b);
            
            // 检查 c 是否是整数且在 100 以内
            if (c <= 100 && a * a + b * b == c * c) {
                printf("(%d, %d, %d)\n", a, b, c);
            }
        }
    }
    return 0;
}
