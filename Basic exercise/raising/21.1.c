#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int BinarySearch(int arr[],int left,int right,int target){
    if(left>right)
        return -1;

    int mid = (left + right) / 2;
    if(target==arr[mid])
        return mid;
    if(target>arr[mid])
        BinarySearch(arr, mid+1, right, target);
    else
        BinarySearch(arr, left, mid-1, target);
}

int BinarySearch2(int arr[],int size,int target){
    int left = 0;
    int right = size - 1;
    while(left<=right){
        int mid = (left + right) / 2;
        if(target==arr[mid])
            return mid;
        else if(target>arr[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int index = BinarySearch(arr, 0, 5, 5);
    printf("%d", index);
    return 0;
}