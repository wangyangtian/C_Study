#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Grade(int score) {
    if(score<0||score >100) return ;
    switch (score / 10) {
        case 10:
        case 9:
            return 'A';
            break;
        case 8:
            return 'B';
            break;
        case 7:
            return 'C';
            break;
        case 6:
            return 'D';
            break;
        default:
            return 'E';
            break;
    }
}

int main() {
    printf("%c",Grade(85));
    return 0;
}