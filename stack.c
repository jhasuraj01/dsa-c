#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100000

/* Stack Properties (similar to vector in c++)
 * - push on top
 * - pop from top
 */

struct Stack {
    // arr to store value of stack
    int arr[MAX_STACK_SIZE];
    // store size of stack
    int size;
};

struct Stack* new_stack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = 0;
    return stack;
}

void stack_push(struct Stack *stack, int value) {
    if(stack->size < MAX_STACK_SIZE) {
        stack->arr[stack->size] = value;
        stack->size += 1;
    }
    else {
        printf("Error: Stack is Full, Failed to Push!\n");
    }
}

void stack_pop(struct Stack *stack) {
    if(stack->size > 0) {
        stack->size -= 1;
    }
    else {
        printf("Error: Stack is Empty, Failed to Pop!\n");
    }
}

int stack_top(struct Stack *stack) {
    if(stack->size > 0) {
        return stack->arr[stack->size - 1];
    }
    else {
        printf("Error: No Element on top of stack!\n");
        return 0;
    }
}


void print(int value) {
    printf("%d\n", value);
}

int main() {
    struct Stack* stack1 = new_stack();

    stack_push(stack1, 5);
    stack_push(stack1, 6);
    stack_push(stack1, 10);
    print(stack_top(stack1));
    stack_pop(stack1);
    print(stack_top(stack1));

    return 0;
}