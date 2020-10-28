#include "../headers/stack.h"

#ifdef __FILE__STACK__


void init_stack(stack_t *stack) {
    strcpy(stack->filename, "data.txt");
    fopen("data.txt", "w");
    stack->top_off = -1;
}

int push_stack(stack_t *stack, int val) {
    FILE *file = fopen(stack->filename, "a");

    char val_str[100];
    sprintf(val_str, "%d", val);
    
    fputs(val_str, file);
    fputs("\n", file);
    fclose(file);
    stack->top_off ++;
}

int pop_stack(stack_t *stack, int *val) {
    FILE *file = fopen(stack->filename, "r");
    FILE *tmp_file = fopen("tmp-data.txt", "w");

    int count = 0;

    char *line = NULL;

    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        /* If current line is not the line user wanted to remove */
        if (stack->top_off != count) {
            fputs(line, tmp_file);
        } else {
            *val = *line - '0';
        }
        count++;
    }
    fclose(file);
    fclose(tmp_file);
    remove(stack->filename);
    rename("tmp-data.txt", stack->filename);
    stack->top_off --;
    return *val;
}

int top_stack(stack_t *stack) {
    FILE *file = fopen(stack->filename, "r");

    int count = 0;

    char *line = NULL;
    char *top;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file)) != -1) {
        /* If current line is not the line user wanted to remove */
        if (stack->top_off == count) {
            top = line;
        }

        count++;
    }
    fclose(file);
    printf("Top : %s\n", top);
    return (long)top;
}

void display_stack(stack_t *stack) {
    FILE *file = fopen(stack->filename, "r");

    int count = 0;

    char *line = NULL;
    char *top;
    size_t len = 0;
    ssize_t read;
    printf("Stack : \n");
    while ((read = getline(&line, &len, file)) != -1) {
        printf("%s", line);
        count++;
    }
    fclose(file);
}


#endif