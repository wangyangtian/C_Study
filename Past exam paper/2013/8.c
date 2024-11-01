#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Word {
    char str[100];
    int freq;
} Word;

Word word[100];

bool check(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-')
        return true;
    else
        return false;
}

void countWord(char text[]) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = tolower(text[i]);
    }

    for (int i = 0; text[i] != '\0'; i++) {
        char temp[100] = {'\0'};
        int t = 0;

        while (text[i] != '\0' && check(text[i])) {
            temp[t++] = text[i++];
        }
        if (t > 0) {
            bool exist = false;
            for (int j = 0; j < count; j++) {
                if (strcmp(temp, word[j].str) == 0) {
                    exist = true;
                    word[j].freq++;
                    break;
                }
            }
            if (exist == false) {
                strcpy(word[count].str, temp);
                word[count].freq = 1;
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("\"%s\"freq: %d\n", word[i].str, word[i].freq);
    }
}

int main() {
    char text[] = "Geovisualization is about working with maps and other views of the geographicinformation includinginteractive maps, 3D scenes, summary charts and tables, time-based views, and schematic views of network relations. A GIS includes interactive maps and other views that operate on the geographicdata set. Maps provide a powerful metaphor to define and standardize how people use and interact with geographic information.";
    countWord(text);
    return 0;
}