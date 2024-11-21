#include <stdio.h>

// 递归函数来找到最后留下的人的编号
int findLastPerson(int n, int k) {
    if (n == 1) {
        return 0;  // 只有一个人时，编号为0
    }
    return (findLastPerson(n - 1, k) + k) % n;
}

int josephus(int n, int k) {  // 非递归形式
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res + 1;
}

// https://blog.csdn.net/u011500062/article/details/72855826
int main() {
    int n;
    printf("请输入总人数N: ");
    scanf("%d", &n);
    int lastPerson = findLastPerson(n, 4) + 1;  // 加1调整编号从1开始
    printf("最后留下的人的编号是: %d\n", lastPerson);
    return 0;
}
