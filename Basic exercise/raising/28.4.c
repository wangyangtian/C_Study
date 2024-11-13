#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Huff {
    char data;
    int parent;
    int lchild;
    int rchild;
    int weight;
} Huff;

typedef struct HuffCode {
    char data;
    char code[10];
} HuffCode;

void initHuff(Huff *h, char *data, int *weight, int n) {
    for (int i = 0; i < n; i++) {
        h[i].data = data[i];
        h[i].weight = weight[i];
        h[i].parent = h[i].lchild = h[i].rchild = -1;
    }
    for (int i = n; i < 2 * n - 1; i++) {
        h[i].weight = 0;
        h[i].parent = h[i].lchild = h[i].rchild = -1;
    }
}

int findMin(Huff *h, int n) {
    int minIndex = -1;  // 初始值设置为 -1
    for (int i = 0; i < n; i++) {
        // 如果 h[i] 没有父节点，且它是当前找到的最小权重
        if (h[i].parent == -1 && (minIndex == -1 || h[i].weight < h[minIndex].weight)) {
            minIndex = i;
        }
    }
    h[minIndex].parent = n;  // 标记该节点已被使用
    return minIndex;
}

void createHuff(Huff *h, int n) {
    for (int i = n; i < 2 * n - 1; i++) {
        int n1 = findMin(h, i);
        int n2 = findMin(h, i);
        h[i].lchild = n1;
        h[i].rchild = n2;
        h[i].weight = h[n1].weight + h[n2].weight;
    }
}

void encoding(Huff *h, char *code, int cIndex, int hIndex, HuffCode *hcode, int *i) {
    if (h[hIndex].lchild == -1 && h[hIndex].rchild == -1) {
        code[cIndex] = '\0';
        hcode[*i].data = h[hIndex].data;
        strcpy(hcode[*i].code, code);
        (*i)++;
        return;
    }
    if (h[hIndex].lchild != -1) {
        code[cIndex] = '0';
        encoding(h, code, cIndex + 1, h[hIndex].lchild, hcode, i);
    }
    if (h[hIndex].rchild != -1) {
        code[cIndex] = '1';
        encoding(h, code, cIndex + 1, h[hIndex].rchild, hcode, i);
    }
}

void decoding(Huff *h, int n, const char *codeFileName, const char *textFileName) {
    FILE *codeFile = fopen(codeFileName, "r");
    FILE *textFile = fopen(textFileName, "w");

    int rootIndex = 2 * n - 2;
    int current = rootIndex;
    char c;
    while ((c = fgetc(codeFile)) != EOF) {
        if (c == '0')
            current = h[current].lchild;
        else
            current = h[current].rchild;

        if (h[current].lchild == -1 && h[current].rchild == -1) {
            fputc(h[current].data, textFile);
            current = rootIndex;
        }
    }
    fclose(codeFile);
    fclose(textFile);
}

int main() {
    int n = 5;
    char data[5] = {'a', 'b', 'c', 'd', 'e'};
    int weight[5] = {1, 2, 3, 4, 5};

    Huff h[2 * n - 1];
    initHuff(h, data, weight, n);
    createHuff(h, n);

    FILE *fp = fopen("hfmTree.dat", "ab");
    fwrite(h, sizeof(Huff), 2 * n - 1, fp);
    fclose(fp);

    char code[10];
    HuffCode hcode[n];
    int index = 0;
    encoding(h, code, 0, 2 * n - 2, hcode, &index);

    FILE *fp1 = fopen("ToBeTran.txt", "r");
    FILE *fp2 = fopen("CodeFile.txt", "w");

    char c;
    while ((c = fgetc(fp1)) != EOF) {
        for (int i = 0; i < n; i++) {
            if (c == hcode[i].data) {
                fwrite(hcode[i].code, sizeof(char), strlen(hcode[i].code), fp2);
                break;
            }
        }
    }

    fclose(fp1);
    fclose(fp2);

    decoding(h, n, "CodeFile.txt", "TextFile.txt");
    return 0;
}