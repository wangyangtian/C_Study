#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int FindKMax(int *a,int len,int k){
    int visited[len];
    for (int i = 0; i < len;i++)
        visited[i] = 0;

    int i;
    while(k>0){
        int max = INT_MIN;
        i = 0;
        while(i<=len){
            if(a[i]>max&&visited[i]!=1){
                max = a[i];
                visited[i] = 1;
            }
            i++;
        }
        k--;
    }
    return i;
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 6, 7, 8, 9, 10};
    printf("%d", FindKMax(a, 10, 3));
    return 0;
}