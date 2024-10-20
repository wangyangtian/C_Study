#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

void merge(int *a,int left,int mid,int right){
    int* b = (int*) malloc(sizeof(int) * (right - left+1));
    for (int i = left; i <= right;i++)
        b[i] = a[i];
    int i = left, j = mid + 1, k = left;
    while(i<=mid&&j<=right){
        if(b[i]<b[j])
            a[k++] = b[i++];
        else
            a[k++] = b[j++];
    }
    while(i<=mid)
        a[k++] = b[i++];
    while(j<=right)
        a[k++] = b[j++];
}

void mergesort(int *a,int left,int right){
    if(left<right){
        int mid = (left + right) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int a[] = {6, 5, 1, 8, 2, 7, 9, 3, 4};
    mergesort(a, 0, 8);
    for (int i = 0; i < 9;i++){
        printf("%d ", a[i]);
    }
        return 0;
}