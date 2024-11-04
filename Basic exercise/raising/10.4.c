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

void combine_permute(int n, int r, char* a, char* b, int R) {
    if (r == 0) {
        char c[100] = {'\0'};
        for (int i = 0; i < R; i++) {
            c[i] = a[b[i]];
        }
        permute(c, 0, R - 1);
    } else {
        for (int j = n; j >= r; j--) {
            b[r - 1] = j - 1;
            combine_permute(j - 1, r - 1, a, b, R);
        }
    }
}

int main() {
    char a[] = "12345";
    char b[5];
    combine_permute(5, 3, a, b, 3);
    return 0;
}