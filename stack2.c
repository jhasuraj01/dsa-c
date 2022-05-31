/* Implementation of stack using linked list */

#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode
{
    int data;
    struct LinkedListNode* next;
};

struct LinkedList
{
    struct LinkedListNode* head;
    struct LinkedListNode* tail;
    int size;
};

struct LinkedList* new_linkedlist() {
    struct LinkedList* linkedlist = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    linkedlist->head = NULL;
    linkedlist->tail = NULL;
    linkedlist->size = 0;
}

struct LinkedListNode* new_linkedlistnode(int data) {
    struct LinkedListNode* linkedlistnode = (struct LinkedListNode*) malloc(sizeof(struct LinkedListNode));
    linkedlistnode->data = data;
    linkedlistnode->next = NULL;
}

void linkedlist_push_front(struct LinkedList* linkedlist, int data) {
    struct LinkedListNode* node = new_linkedlistnode(data);
    if (linkedlist->size == 0)
    {
        linkedlist->head = node;
        linkedlist->tail = node;
    }
    else {
        node->next = linkedlist->head;
        linkedlist->head = node;
    }
    linkedlist->size += 1;
}

void linkedlist_push_back(struct LinkedList* linkedlist, int data) {
    struct LinkedListNode* node = new_linkedlistnode(data);
    if (linkedlist->size == 0)
    {
        linkedlist->head = node;
        linkedlist->tail = node;
    }
    else {
        linkedlist->tail->next = node;
        linkedlist->tail = node;
    }
    linkedlist->size += 1;
}

void linkedlist_pop_front(struct LinkedList* linkedlist) {
    if(linkedlist->size == 0) return;
    struct LinkedListNode* node = linkedlist->head;

    if(linkedlist->size == 1) {
        linkedlist->head = NULL;
        linkedlist->tail = NULL;
    }
    else {
        linkedlist->head = linkedlist->head->next;
    }
    free(node);
}

struct Stack {
    // LinkedList to store value of stack
    struct LinkedList* list;
    // store size of stack
    int size;
};

struct Stack* new_stack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->list = new_linkedlist();
    stack->size = 0;
    return stack;
}

void stack_push(struct Stack *stack, int value) {
    linkedlist_push_front(stack->list, value);
    stack->size += 1;
}

void stack_pop(struct Stack *stack) {
    if(stack->size > 0) {
        linkedlist_pop_front(stack->list);
        stack->size -= 1;
    }
    else {
        printf("Error: Stack is Empty, Failed to Pop!\n");
    }
}

int stack_top(struct Stack *stack) {
    if(stack->size > 0) {
        return stack->list->head->data;
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