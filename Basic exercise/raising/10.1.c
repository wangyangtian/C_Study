#include <stdio.h>

// 生成从 n 个元素中抽取 r 个元素的所有组合
// a[] 是字符数组，b[] 用于存储当前组合的下标，R 是固定的总的组合长度
void Combine(int n, int r, char a[], int b[], int R) {
    if (r == 0) {  // 当所有元素被选中时
        for (int i = 0; i < R; i++) {
            printf("%c ", a[b[i]]);  // 打印组合结果
        }
        printf("\n");
    } else {
        for (int j = n; j >= r; j--) {       // 从n中选r个元素
            b[r - 1] = j - 1;                // 选择第j-1个元素
            Combine(j - 1, r - 1, a, b, R);  // 递归处理剩余的组合
        }
    }
}

int main() {
    char a[] = {'A', 'B', 'C', 'D'};   // 要进行组合的字符数组
    int n = sizeof(a) / sizeof(a[0]);  // 计算数组长度
    int r = 3;                         // 组合中取r个元素
    int b[3];                          // 存储组合下标的临时数组

    printf("从 %d 个字符中取 %d 个字符的所有组合：\n", n, r);
    Combine(n, r, a, b, r);  // 调用函数进行组合
    return 0;
}
