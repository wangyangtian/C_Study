#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InsertSort(int* A, int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        if (A[i - 1] > A[i]) {
            temp = A[i];

            for (j = i - 1; j > +0 && A[j] > temp;j--)// 检查所有前面已排好序的元素
                A[j + 1] = A[j];                      // 所有大于temp的元素都向后挪位

            A[j + 1] = temp;                          // 复制到插入位置
        }
    }
}


// 折半插入排序函数
void BInsertSort(int *A, int n) {
    int temp; // 用于暂存当前需要插入的元素

    // 从第1个元素开始（假设第0个元素已经有序），逐个插入元素
    for (int i = 1; i < n; i++) {
        int low = 0;          // 搜索的左边界
        int high = i - 1;     // 搜索的右边界
        temp = A[i];          // 暂存当前待排序的元素

        // 使用折半查找找到当前元素的插入位置
        while (low <= high) {
            int mid = (low + high) / 2; // 计算中间位置
            if (A[mid] > temp)          // 如果中间元素大于待插入元素
                high = mid - 1;         // 缩小搜索范围到左半部分
            else
                low = mid + 1;          // 否则缩小搜索范围到右半部分
        }

        // 将有序部分元素右移，为待插入元素腾出空间
        for (int j = i - 1; j > high; j--) {
            A[j + 1] = A[j];
        }

        // 插入待排序元素到正确的位置
        A[high + 1] = temp;
    }
}


void main(){
	int i;
	int a[8] = { 8, 5, 4, 3, 8, 1, 6, 7 };
 
	printf("before:{");
	for(i = 0; i < 8; i++){
		printf("%d ",a[i]);
	}
	printf("}\n");
 
	BInsertSort(a,8);
	
	printf("after:{");
	for(i = 0; i < 8; i++){
		printf("%d ",a[i]);
	}
	printf("}\n");
}