#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXN 10
#define MAXCOLOR 4

int adjMatrix[MAXN][MAXN];
int colors[MAXCOLOR];
int N;

bool isVaild(int region,int color){
    for (int i = 0; i < N;i++){
        if(adjMatrix[region][i]&&colors[i]==color)
            return false;
    }
    return true;
}

void colorGraph(int region){
    if(region==N){
        for (int i = 0; i < N;i++)
            printf("%d ", colors[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= MAXCOLOR;i++){
        if(isVaild(region,i)){
            colors[region] = i;
            colorGraph(region + 1);
            colors[region] = 0;
        }
    }
}

int main() {
    printf("输入区域数:\n");
    scanf("%d", &N);
    printf("输入邻接矩阵:\n");
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++)
            scanf("%d", adjMatrix[i][j]);
    }
    colorGraph(0);
    return 0;
}

/*
回溯算法核心思路

void backtrack(参数列表) {
    if (满足结束条件) {
        // 处理结果，例如保存解或输出解
        return;
    }

    for (选择 : 当前状态的所有选择) {
        // 做选择
        修改当前状态;

        // 递归调用
        backtrack(新的参数);

        // 撤销选择
        恢复当前状态;
    }
}
*/