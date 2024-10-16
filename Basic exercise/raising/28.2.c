#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX_LINE_LENGTH 1024  // 假设每行最多1024个字符
#define MAX_WORD_LENGTH 100   // 假设单词长度不超过100

// 建立文本文件
void createFile(const char * filename){
    FILE* fp = fopen(filename, "w");
    if(fp=NULL){
        printf("无法创建文件！");
        exit(1);
    }

    printf("请输入文本内容（输入 'EOF' 表示结束）：\n");
    char line[MAX_LINE_LENGTH];
    while(1){
        fgets(line, MAX_LINE_LENGTH, stdin);
        if(strncmp(line,"EOF",3)==0)
            break;
        fputs(line, fp);
    }
    fclose(fp);
}

int countWord(const char* filename,const char *word){
    FILE* fp = fopen(filename, "r");
    if(fp=NULL){
        printf("无法打开文件！");
        exit(1);
    }
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL){
        char* pos = line;
        while(pos=strstr(pos,word)!=NULL){
            count++;
            pos += strlen(word);
        }
    }
    fclose(fp);
    return count;
}

void searchWord(const char* filename,const char *word){
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("无法打开文件。\n");
        exit(1);
    }
    char line[MAX_LINE_LENGTH];
    int row = 1;
    
    while(fgets(line,MAX_LINE_LENGTH,fp)!=NULL){
        char* pos=line;
        int wordCount = 0;

        while(pos=strstr(pos,word)!=NULL){
            printf("第%d行，第%d次出现，位置为%d", row, ++wordCount,
                   pos - word + 1);
            pos += strlen(word);
        }
        row++;
    }
    fclose(fp);
}

int main() {
    FILE* fp;
    char path[100];
    printf("请输入文件名：");
    scanf("%s", path);
    fp = fopen("path", "w");
    return 0;
}