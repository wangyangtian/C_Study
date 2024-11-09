#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
    char str[100];
    scanf("%s", str);
    int len = strlen(str);
    int res = 0;

    for (int i = 0; i < len; i++) {
        // 奇数长度回文串中心扩展
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < len && str[l] == str[r]) {
            l--;
            r++;
        }
        res = max(res, r - l - 1);

        // 偶数长度回文串中心扩展
        l = i, r = i + 1;
        while (l >= 0 && r < len && str[l] == str[r]) {
            l--;
            r++;
        }
        res = max(res, r - l - 1);
    }

    printf("%d\n", res);
    return 0;
}
