#include <stdio.h>
#include <string.h>

// 交换两个字符
void swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// 生成所有排列，并输出每种排列作为列车的出站顺序
void Permute(char* a, int start, int end) {
    if (start == end) {
        // 打印当前排列（作为列车出站顺序）
        for (int i = 0; i <= end-2; i++) {
            int x1=a[i];
            for(int j=i+1;j<=end;j++){
                int x2=a[j];
                for(int k=j+1;k<=end;k++){
                    int x3=a[k];
                    if(x1>x2&&x1>x3&&x2<x3)
                        return;
                }
            }
        }
        printf("%s\n",a);
    } else {
        for (int i = start; i <= end; i++) {
            swap(&a[i], &a[start]);   // 交换元素，产生新的排列
            Permute(a, start + 1, end); // 递归生成后续的排列
            swap(&a[i], &a[start]);   // 回溯，恢复原来的数组
        }
    }
}

int main() {
    char trains[] = "ABCD"; // 列车编号
    int n = strlen(trains); // 获取列车数量
    Permute(trains, 0, n - 1); // 生成列车出站顺序的全排列
    return 0;
}
