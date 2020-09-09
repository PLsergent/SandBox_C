#include <stdio.h>

int main() {
    int number;

    do {
        printf("Pick a number between 1 to 10: ");
        scanf("%d", &number);
    }while(number < 1 || number > 10);

    return 0;
}