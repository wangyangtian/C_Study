#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int stack[100];
int top = -1;

void find(int a[], int low, int high, int e) {
    if (low > high) {
        stack[++top] = -1;
        return;
    }
    int mid = (low + high) / 2;
    stack[++top] = mid;
    if (a[mid] == e)
        return;
    else if (a[mid] < e)
        find(a, mid + 1, high, e);
    else
        find(a, low, high - 1, e);
}

int main() {
    int arr[] = {8, 7, 3, 9, 1, 5, 2, 4};
    bubbleSort(arr, 8);
    find(arr, 0, 8, 9);
    for (int i = 0; i <= top; i++) {
        printf("%d:%d \n", i, stack[i]);
    }
    return 0;
}