/* Implementation of queue using linked list */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct Queue {
    // LinkedList to store value of queue
    struct LinkedList* list;
    // store size of queue
    int size;
};

struct Queue* new_queue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->list = new_linkedlist();
    queue->size = 0;
    return queue;
}

void queue_push(struct Queue *queue, int value) {
    linkedlist_push_back(queue->list, value);
    queue->size += 1;
}

void queue_pop(struct Queue *queue) {
    if(queue->size > 0) {
        linkedlist_pop_front(queue->list);
        queue->size -= 1;
    }
    else {
        printf("Error: Queue is Empty, Failed to Pop!\n");
    }
}

int queue_top(struct Queue *queue) {
    if(queue->size > 0) {
        return queue->list->head->data;
    }
    else {
        printf("Error: No Element on top of queue!\n");
        return 0;
    }
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

// void dfsR(int node, int N, int visited[N], int G[N][N]) {
//     printf("Visited: %d\n", node);
//     visited[node] = 1;
//     for (int i = 0; i < N; ++i)
//     {
//         if(G[node][i] && visited[i] == 0) {
//             dfs(i, N, visited, G);
//         }
//     }
// }

void dfs(int src, int N, int visited[N], int G[N][N]) {

    struct Stack* my_stack = new_stack();
    stack_push(my_stack, src);
    visited[src] = 1;

    printf("DFS: \n");

    while(my_stack->size > 0) {

        int node = stack_top(my_stack);
        printf("Visited: %d\n", node);
        stack_pop(my_stack);

        for (int i = 0; i < N; ++i)
        {
            if(G[node][i] == 1 && visited[i] == 0) {
                stack_push(my_stack, i);
                visited[i] = 1;
            }
        }
    }
}

void bfs(int src, int N, int visited[N], int G[N][N]) {

    struct Queue* my_queue = new_queue();
    queue_push(my_queue, src);
    visited[src] = 1;

    printf("BFS: \n");

    while(my_queue->size > 0) {

        int node = queue_top(my_queue);
        printf("Visited: %d\n", node);
        queue_pop(my_queue);

        for (int i = 0; i < N; ++i)
        {
            if(G[node][i] && !visited[i]) {
                queue_push(my_queue, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    
    int N = 8;
    int G[8][8] = {
        {0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };

    int visited1[8] = {0}, visited2[8] = {0};

    dfs(0, N, visited1, G);
    bfs(0, N, visited2, G);

    return 0;
}