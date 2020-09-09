#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int main() {
    char str[MAX];
    int words = 1;

    printf("Please enter a message : ");
    fgets(str, sizeof(str), stdin);
    char delim[] = " ";

    char *word = strtok(str, delim);

    while(word != NULL) {
        for (int i=0; i < strlen(word); i++) {
            if (!isalnum(word[i])) {
                word[i] = '\0';
            }
        }
        printf("Word %d : %s\n", words, word);
        word = strtok(NULL, delim);
        words ++;
    }
    return 0;
}