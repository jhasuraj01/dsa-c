/* Implementation of queue using linked list */

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

void print(int value) {
    printf("%d\n", value);
}

int main() {
    struct Queue* queue1 = new_queue();

    queue_push(queue1, 5);
    queue_push(queue1, 6);
    queue_push(queue1, 10);
    print(queue_top(queue1));
    queue_pop(queue1);
    print(queue_top(queue1));
    queue_pop(queue1);
    print(queue_top(queue1));

    return 0;
}