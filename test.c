#include <stdio.h>
#include <string.h>

void findLongestCommonSubstring(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    int maxLength = 0;  // 最长公共子串长度
    int startPos1 = 0;  // 最长公共子串在 s1 中的起始位置
    int startPos2 = 0;  // 最长公共子串在 s2 中的起始位置

    // 遍历 s1 的所有子串
    for (int i = 0; i < len1; i++) {
        for (int j = i; j < len1; j++) {
            int currentLength = j - i + 1;  // 当前子串长度

            // 如果当前子串长度小于或等于已知最长长度，跳过
            if (currentLength <= maxLength) {
                continue;
            }

            // 提取 s1 的子串
            char subStr[currentLength + 1];
            strncpy(subStr, &s1[i], currentLength);
            subStr[currentLength] = '\0';  // 添加字符串终止符

            // 在 s2 中查找该子串
            if (strstr(s2, subStr) != NULL) {
                maxLength = currentLength;
                startPos1 = i;
                startPos2 = strstr(s2, subStr) - s2;
            }
        }
    }

    // 输出结果
    printf("Longest Common Substring Length: %d\n", maxLength);
    if (maxLength > 0) {
        printf("Substring in s1 starts at: %d\n", startPos1);
        printf("Substring in s2 starts at: %d\n", startPos2);
        printf("Longest Common Substring: ");
        for (int i = 0; i < maxLength; i++) {
            printf("%c", s1[startPos1 + i]);
        }
        printf("\n");
    }
}

int main() {
    const char *s1 = "abcdefg";
    const char *s2 = "xyzabcm";

    findLongestCommonSubstring(s1, s2);

    return 0;
}
