#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *ch;
    int length;
} HString;

HString *SubCat(HString str1, HString str2, int i, int j) {
    if (i > str1.length || i > j) return NULL;
    
    HString *ret = (HString *)malloc(sizeof(HString));
    ret->length = str1.length + str2.length - (j - i + 1);
    ret->ch = (char *)malloc((ret->length + 1) * sizeof(char)); // +1 for null-terminator
    
    int n1 = 0, n2 = 0;
    
    // Copy str1 up to i
    for (int k = 0; k < i; ++k) {
        ret->ch[n1++] = str1.ch[k];
    }

    // Copy str2 entirely
    while (str2.ch[n2]) {
        ret->ch[n1++] = str2.ch[n2++];
    }

    // Copy str1 from j onwards
    for (int k = j + 1; k < str1.length; ++k) {
        ret->ch[n1++] = str1.ch[k];
    }
    
    ret->ch[n1] = '\0'; // null-terminate the string
    return ret;
}

int main() {
    HString str1, str2;
    
    str1.ch = "Hello, World!";
    str1.length = strlen(str1.ch);
    
    str2.ch = "INSERT";
    str2.length = strlen(str2.ch);
    
    int i = 7;  // Starting index to replace (0-based)
    int j = 11; // Ending index to replace (inclusive)
    
    HString *result = SubCat(str1, str2, i, j);
    
    if (result) {
        printf("Result: %s\n", result->ch);
        free(result->ch); // Free the allocated memory for string
        free(result);     // Free the allocated memory for HString
    } else {
        printf("Invalid input!\n");
    }
    
    return 0;
}
