#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二分查找
int BSearch_R(int a[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (left + right);
        if (a[mid] == target)
            return mid;
        if (a[mid] > target)
            return BSearch_R(a, left, mid - 1, target);
        if (a[mid] < target)
            return BSearch_R(a, mid + 1, right, target);
    }
    return -1;
}

int BSearch(int a[],int len,int target){
    int left=0,right=len-1;
    
    while (left<=right)
    {
        int mid =left+(left+right)/2;
        if(a[mid]==target)
            return mid;
        if(a[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
}

int main() {
    return 0;
}