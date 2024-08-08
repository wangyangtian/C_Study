#include <stdio.h>
#include <string.h>
static char* _strtok = NULL;  // 用全局变量缓存上一次的结果

char* MyStrtok(char* s, char const* ct) {
    char *sbegin, *send;

    sbegin = s ? s : _strtok;
    if (!sbegin) {
        return NULL;
    }
    sbegin += strspn(sbegin, ct);
    if (*sbegin == '\0') {
        _strtok = NULL;
        return (NULL);
    }
    send = strpbrk(sbegin, ct);
    if (send && *send != '\0')
        *send++ = '\0';
    _strtok = send;
    return (sbegin);
}

int main() {
    char str[] = "Hello, World! Welcome to C programming.";
    char* token;
    char* delim = " ,.!";

    token = MyStrtok(str, delim);
    while (token != NULL) {
        printf("%s\n", token);
        token = MyStrtok(NULL, delim);
    }

    return 0;
}
