#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>



int main() {
    int a[3][4];
    int max,max_i,max_j;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&a[i][j]);
        }
    }
    max=a[0][0];
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            if(a[i][j]>max){
                max=a[i][j];
                max_i=i;
                max_j=j;
            }
        }
    } 
       
    return 0;
}