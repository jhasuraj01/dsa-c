#include<stdio.h>
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

void printLinkedList(struct LinkedList* linkedlist) {
    struct LinkedListNode* node = linkedlist->head;
    while(node) {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}

// need doubly linkedlist to pop from back
// void linkedlist_pop_back(struct LinkedList* linkedlist, int data) {
//     linkedlist->size -= 1;
// };


int main() {
    struct LinkedList* linkedlist = new_linkedlist();
    linkedlist_push_back(linkedlist, 5);
    linkedlist_push_front(linkedlist, 6);
    linkedlist_push_back(linkedlist, 8);
    linkedlist_push_front(linkedlist, 4);
    printLinkedList(linkedlist);
    return 0;
}