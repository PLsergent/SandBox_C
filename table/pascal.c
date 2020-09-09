#include <stdio.h>

int main() {
    int number_of_line = 6;
    int triangle[number_of_line][number_of_line];

    for (int i=0; i < number_of_line; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        for (int j=1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    for (int i=0; i < number_of_line; i++) {
        for (int j=0; j <= i; j++) {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    return 0;
}