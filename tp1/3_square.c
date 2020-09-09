#include <stdio.h>
#include <string.h>


int check_col(int col, int n) {
    if (col >= n) {
        col = 0;
    } else if (col < 0) {
        col = n-1;
    }
    return col;
}

int check_line(int line, int n) {
    if (line >= n) {
        line = 0;
    } else if (line < 0) {
        line = n-1;
    }
    return line;
}

void print_table(int n, int table[n][n]) {
    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    do {
        printf("Order of the square N (odd) = ");
        fflush(stdin);
        scanf("%d", &n);
    } while(n % 2 == 0);

    int magic[n][n];
    memset( magic, 0, n*n*sizeof(int) );

    int start = n / 2;
    int max_value = n*n;
    int col = start-1, line = start;
    magic[start-1][start] = 1;

    for (int i=2; i <= max_value; i++) {
        col --;
        line ++;
        col = check_col(col, n);
        line = check_line(line, n);

        if (magic[col][line] != 0) {
            col --;
            line --;
            col = check_col(col, n);
            line = check_line(line, n);
        }
        magic[col][line] = i;
    }

    print_table(n, magic);
   return 0;
}