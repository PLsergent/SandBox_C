#include "../headers/stack.h"

#ifdef __DYN__STACK__


void init_stack(stack_t* stack) {
    stack->top = NULL;
}

int push_stack(stack_t *stack, int val) {
    node_t* new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = stack->top;
    stack->top = new_node;

    return new_node->val;
}

int pop_stack(stack_t *stack, int *val) {
    node_t* tmp = stack->top;
    *val = stack->top->val;
    stack->top = stack->top->next;
    free(tmp);
    
    return stack->top->val;
}

int top_stack(stack_t *stack, int *val) {
    return stack->top->val;
}

void display_stack(stack_t *stack) {
    node_t* current;
    current = stack->top;
    if (current != NULL) {
        printf("Stack: ");
        do {
            printf("%d ", current->val);
            current = current->next;
        } while (current != NULL);
        printf("\n");
    } else {
        printf("The Stack is empty\n");
    }
}

#endif