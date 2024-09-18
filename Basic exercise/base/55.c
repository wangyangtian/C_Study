#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintCount(char* str) {
    int charNum = 0;
    int spaceNum = 0;
    int digitNum = 0;
    int OtherNum = 0;
    while (*str != '\0') {
        if(isalpha(*str))
            charNum++;
        else if(isspace(*str))
            spaceNum++;
        else if(isdigit(*str))
            digitNum++;
        else
            OtherNum++;
        str++;
    }
    printf("英文字母%d个，空格%d个，数字%d个，其他字符%d个。",charNum,spaceNum,digitNum,OtherNum);
}

int main() {
    char str[] = "bad 114@@ ,good dog.";
    PrintCount(str);
    return 0;
}