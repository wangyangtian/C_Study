#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;

        // 将大于key的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 将key插入到正确的位置
        arr[j + 1] = key;
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