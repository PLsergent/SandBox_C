#include <stdio.h>

int dycho(int first, int last) {
    int values[8] = {2, 5, 6, 8, 10, 15, 19, 35};
    int value_to_find = 15;
    int index;

    int middle = (first + last) / 2;
    if (value_to_find == values[middle]) {
        index = middle;
        return index;
    } else if (first == middle) {
        return -1;
    } else if (value_to_find < values[middle]) {
        last = middle;
        dycho(first, last);
    } else if (value_to_find > values[middle]) {
        first = middle;
        dycho(first, last);
    }
}

int dycho_while() {
    int values[8] = {2, 5, 6, 8, 10, 15, 19, 35};
    int value_to_find = 15;
    int first = 0;
    int last = 7;
    int index;
    int not_found = 1;

    while(not_found) {
        int middle = (first + last) / 2;
        if (value_to_find == values[middle]) {
            index = middle;
            not_found = 0;
            return index;
        } else if (first == middle) {
            return -1;
        } else if (value_to_find < values[middle]) {
            last = middle;
        } else if (value_to_find > values[middle]) {
            first = middle;
        }
    }
    
}

int main() {
    int index = dycho(0, 7);
    printf("%d\n", index);

    int index_while = dycho_while();
    printf("%d\n", index_while);
    return 0;
}