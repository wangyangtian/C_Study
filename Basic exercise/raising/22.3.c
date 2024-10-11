#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>



int main() {
    for (int i = 1; i < 20;i++){
        for (int j = 1; j < 34;j++){
            if(5*i+3*j+(100-i-j)/3==100)
                printf("公鸡：%d,母鸡：%d,小鸡：%d\n", i, j, 100 - i - j);
        }
    }
        return 0;
}