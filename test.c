#include <stdio.h>
#include <ctype.h>

void Total(char *FilePath) {
    FILE* fp;
    fp = fopen(FilePath, "r");
    if (fp == NULL) {
        printf("无法打开文件 %s\n", FilePath);
        return;
    }

    int lineCharNum = 0, lineWordNum = 0;
    int totalChar = 0, totalWord = 0, totalLine = 0;
    char buffer[1024];
    int inWord = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        lineCharNum = 0;
        lineWordNum = 0;
        inWord = 0;
        
        // 计算当前行的字符数和单词数
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isspace(buffer[i])) {
                lineCharNum++; // 统计字符数
            }
            
            if (isspace(buffer[i])) {
                if (inWord) {
                    lineWordNum++; // 单词结束
                    inWord = 0;
                }
            } else {
                inWord = 1; // 在单词中
            }
        }
        
        // 如果最后一个字符是单词的一部分，统计最后一个单词
        if (inWord) {
            lineWordNum++;
        }

        totalChar += lineCharNum;
        totalWord += lineWordNum;
        totalLine++;

        printf("Line %d: 字符数 = %d, 单词数 = %d\n", totalLine, lineCharNum, lineWordNum);
    }

    // 输出文件的总字符数，总单词数，总行数
    printf("总字符数 = %d\n", totalChar);
    printf("总单词数 = %d\n", totalWord);
    printf("总行数 = %d\n", totalLine);

    fclose(fp);
}
int main(){
    Total("test.txt");
}