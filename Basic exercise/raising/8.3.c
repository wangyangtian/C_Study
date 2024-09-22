#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LEN 100
#define MAX_WORD 100

typedef struct wordFreq
{
    char word[MAX_WORD_LEN];
    int count;
}wordFreq;

void toLowerCase(char *str){
    for(int i=0;str[i]!='\0';i++){
        str[i]=tolower(str[i]);
    }
}

int FindWord(wordFreq words[],int WordCount,char *word){
    for(int i=0;i<WordCount;i++){
        if(strcmp(words[i].word,word)==0)
            return i;
    }
    return -1;
}

char *DeletePunct(char *word){
    int i,j=0;

    for(i=0;i<strlen(word);i++){
        if(!ispunct(word[j])){
            word[j]=word[i];
            j++;
        }
    }
    word[j]='\0';
    return word;
}



int main() {
    char str[]="Good good study, day day up.";
    wordFreq words[MAX_WORD]= {0};  // 初始化词频数组
    int wordCount =0;
    int index;   

    // 使用 strtok 分割字符串
    char *token = strtok(str, " ");

    while (token != NULL) {
        toLowerCase(token);       // 转换为小写
        DeletePunct(token);       // 删除标点符号

        index = FindWord(words, wordCount, token);  // 查找单词是否已经存在

        if (index != -1) {
            words[index].count++;  // 如果找到单词，增加词频
        } else {
            strcpy(words[wordCount].word, token);  // 否则，添加新的单词
            words[wordCount].count = 1;            // 词频初始为1
            wordCount++;
        }

        token = strtok(NULL, " ");  // 获取下一个单词
    }

    printf("单词词频如下:\n");
    for(int i=0;i<wordCount;i++){
        printf("%s : %d\n",words[i].word,words[i].count);
    }
    return 0;
}