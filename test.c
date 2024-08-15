#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double ArrMax(double* arr, int n) {
    if (n == 1)
        return arr[0];
    else {
        float max = ArrMax(arr, n - 1);
        return arr[n - 1] > max ? arr[n - 1] : max;
    }
}

double ArrSum(double* arr, int n) {
    if (n == 1)
        return arr[0];
    else
        return ArrSum(arr, n - 1) + arr[n - 1];
}

double ArrAvg(double* arr, int n) {
    if (n == 1)
        return arr[0];
    else
        return ArrSum(arr, n) / n;
}

void OddHead(int* arr, int n) {
    int temp;
    for (int i = 0, j = n - 1; i < j;) {
        if (arr[i] % 2 == 1)
            i++;
        if (arr[j] % 2 == 0)
            j--;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void SplitByLast(int* arr, int n) {
    int i, j;
    int temp;
    for (i = 0, j = n - 2; i < j;) {
        while (arr[i] < arr[n - 1]) {
            i++;
        }
        while (arr[j] > arr[n - 1]) {
            j--;
        }
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    temp = arr[i];
    arr[i] = arr[n - 1];
    arr[n - 1] = temp;
}
void FindInMatrix(int arr[][100],int m,int n){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int current=arr[i][j];
            int rowMax=arr[i][0],rowMin=arr[i][0];
            for(int k=1;k<n;k++){
                if(arr[i][k]>rowMax)    rowMax=arr[i][k];
                if(arr[i][k]<rowMin)    rowMin=arr[i][k];
            }
            int colMin = arr[0][j], colMax = arr[0][j];
            for (int k = 1; k < m; k++) {
                if (arr[k][j] < colMin) colMin = arr[k][j];
                if (arr[k][j] > colMax) colMax = arr[k][j];
            }
            if(current==rowMax&&current==colMax){
                printf("元素(%d,%d)=%d,是行列最大值。\n",i+1,j+1,arr[i][j]);
            }
            if(current==rowMin&&current==colMin){
                printf("元素(%d,%d)=%d,是行列最小值。\n",i+1,j+1,arr[i][j]);
            }
        }
    }    
}
int main() {
    int arr[] = {2, 3, 8, 2, 1, 8, 1, 1};
    OddHead(arr,8);
    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int a1[] = {5, 2, 3, 3, 4, 6, 3, 2, 6, 4};
    SplitByLast(a1, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", a1[i]);
    }
    printf("\n");
    int A[100][100] = {
        {10, 2, 5},
        {3, 7, 9},
        {8, 6, 4}
    };
    int m = 3, n = 3;
    
    FindInMatrix(A, m, n);    
    return 0;
}