#include <stdio.h>

int main() {
    FILE* fp;
    fp = fopen("Matrix.txt", "w");  // 打开文件以写入
    if (fp == NULL) {
        printf("文件打开失败！\n");
        return 1;
    }
    
    int k = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j)
                fputc('0'+k++,fp);
            else
                fputc('0',fp);
        }
        fprintf(fp, "\n");  // 换行
    }
    
    fclose(fp);  // 关闭文件
    return 0;
}
