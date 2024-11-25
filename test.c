#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);
    printf("%s \n%s\n", str1, str2);
    char str3[100];
    strcpy(str3, "exterior ring");
    printf("%s", str3);
    return 0;
}