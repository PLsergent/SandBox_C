#include <stdio.h>

int main() {
    int values[6] = {5, 56, 8, 2, 6, 9};

    while(1) {
        int swaped = 0;
        for (int i=0; i < 5; i++) {
            if (values[i] > values[i+1]) {
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                swaped = 1;
            }
        }
        // sorted
        if (swaped == 0) {
            for (int j=0; j < 6; j++) {
                printf("%d\n", values[j]);
            }
            return 0;
        }
    }
}