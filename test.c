#include <stdio.h>
#include <string.h>

typedef struct {
    char ch[100];  // 假设最大长度为100
    int length;    // 实际字符串长度
} SString;

int Index_2(SString s, SString t) {
    int i = 1;  // 从1开始
    int j = 1;  // 从1开始
    while (i <= s.length) {  // 修改循环条件，确保能够匹配到最后一个可能的位置
        if (s.ch[i] == t.ch[j]) {
            i++;
            j++;
            if (j > t.length)  // j超过模式串长度时匹配成功
                return i - t.length;
        } else {
            i = i - j + 2;  // i回退到下一起始位置
            j = 1;          // j重置为1
        }
    }
    return 0;
}

int main() {
    // 初始化字符串，并手动设置第一个元素为空格
    SString s1 = {" llo", 3};
    SString s2 = {" hedddddddllo", 12};


    int result = Index_2(s2, s1);
    printf("Result: %d\n", result);  // 应该输出3
    return 0;
}
