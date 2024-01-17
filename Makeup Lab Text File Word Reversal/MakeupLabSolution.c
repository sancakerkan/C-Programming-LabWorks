#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 5001
#define MAX_WORD_LENGTH 51

void reverseWords(char* line) {
    char* word;
    char* words[100];
    int wordCount = 0;

    word = strtok(line, " ");
    while (word != NULL && wordCount < 100) {
        words[wordCount++] = word;
        word = strtok(NULL, " ");
    }

    for (int i = wordCount - 1; i >= 0; i--) {
        char* currentWord = words[i];
        int len = strlen(currentWord);

        for (int j = 0; j < len; j++) {
            currentWord[j] = toupper(currentWord[j]);
        }

        if (i < wordCount - 1) {
            putchar(',');
        }
        printf("%s", currentWord);
    }
    putchar('\n');
}

int main() {
    char filename[100];
    FILE* file;
    char line[MAX_LINE_LENGTH];

    printf("Enter the input filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL) {
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        reverseWords(line);
    }

    fclose(file);

    return 0;
}
