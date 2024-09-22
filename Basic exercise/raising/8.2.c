#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_LEN 100    // 单词最大长度
#define MAX_WORDS    1000   // 单词最大数量

//存储单词和词频的数组结构，每个元素包含一个单词和其出现的次数
typedef struct wordFreq
{
    char word[MAX_WORD_LEN];
    int frequency;
}wordFreq;

// 将字符串转为小写,确保大小写不影响词频统计
void toLowerCase(char *str){
    for(int i=0;str[i]!='\0';i++){
        str[i]=tolower(str[i]);
    }
}

// 检查单词是否已经在单词数组中
int findWord(wordFreq words[],int numWords,char *word){
    for(int i=0;i<numWords;i++){
        if(strcmp(words[i].word,word)==0)
            return i;
    }
    return -1;
}


char* DeletePunct(char* word, int wordLen) {
    int i, j = 0;

    // 遍历每个字符，如果不是标点符号，就保留它
    for (i = 0; i < wordLen; i++) {
        if (!ispunct(word[i])) { // 判断是否是标点符号
            word[j++] = word[i]; // 如果不是标点符号，将其放到新的位置
        }
    }
    word[j] = '\0'; // 确保字符串以 '\0' 结尾
    return word;
}

int main() {
    FILE *fp;
    wordFreq words[MAX_WORDS];
    char word[MAX_WORD_LEN];
    int wordNum=0;

    fp=fopen("Input.txt","r");
    if (fp == NULL) {
        printf("无法打开文件!\n");
        return 1;
    }

    // 初始化词频数组
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].frequency = 0;
    }

    // 逐个读取文件中的单词
    while(fscanf(fp,"%s",word)!=EOF){
        int len=strlen(word);
        DeletePunct(word,len);
        toLowerCase(word);

        // 如果单词数组中已存在该单词，更新词频
        int index =findWord(words,wordNum,word);
        if(index!=-1)
            words[index].frequency++;
        else{   // 如果是新单词，添加到单词数组
            strcpy(words[wordNum].word,word);
            words[wordNum].frequency++;
            wordNum++;
        }
    }

    fclose(fp);

    // 输出结果
    printf("单词词频统计:\n");
    for (int i = 0; i < wordNum; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }
    return 0;
}