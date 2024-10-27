#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

int main() {
    int n, m;
    printf("请输入人数n:");
    scanf("%d", &n);
    printf("请输入总科数:");
    scanf("%d", &m);
    int student[n][m];

    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            scanf("%d", student[i][j]);
        }
    }

    printf("不及格学生成绩:\n");
    int flag = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(student[i][j]<60){
                flag = 1;
                break;
            }
        }
        if(flag){
            printf("No.%d", i);
            for (int j = 0; j < m;j++){
                printf("%d ", student[i][j]);
            }
        }
        printf("\n");
    }
        return 0;
}