#include <stdio.h>

void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permute(char* a, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%c ", a[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&a[start], &a[i]);      // 交换元素
            permute(a, start + 1, end);  // 递归调用
            swap(&a[start], &a[i]);      // 回溯
        }
    }
}

int main() {
    char a[] = "123";
    permute(a, 0, 2);
    return 0;
}