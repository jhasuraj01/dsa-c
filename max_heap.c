#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STACK_SIZE 100000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* MaxHeap Properties (similar to vector in c++)
 * - push on top
 * - pop from top
 */

struct MaxHeap {
    // arr to store value of maxheap
    int arr[MAX_STACK_SIZE];
    // store size of maxheap
    int size;
};

struct MaxHeap* new_maxheap() {
    struct MaxHeap* maxheap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    maxheap->size = 0;
    return maxheap;
}

int maxheap_parent(int index) {
    return (index - 1)/2;
}

int maxheap_leftchild(int index) {
    return 2*index + 1;
}

int maxheap_rightchild(int index) {
    return 2*index + 2;
}

// Heap Shift Up
void maxheap_shiftup(struct MaxHeap *maxheap, int index) {

    // base
    if(index == 0) {
        return;
    }

    assert(index > 0);

    // logic
    int parent = maxheap_parent(index);

    if(maxheap->arr[parent] < maxheap->arr[index]) {
        swap(&maxheap->arr[parent], &maxheap->arr[index]);
        maxheap_shiftup(maxheap, parent);
    }
}

// Heap Shift Down
void maxheap_shiftdown(struct MaxHeap *maxheap, int index) {
    int left = maxheap_leftchild(index);
    int right = maxheap_rightchild(index);

    int N = maxheap->size;

    int maxindex = index;

    if(left < N && maxheap->arr[left] > maxheap->arr[maxindex]) {
        maxindex = left;
    }

    if(right < N && maxheap->arr[right] > maxheap->arr[maxindex]) {
        maxindex = right;
    }

    // base
    if(maxindex == index) {
        return;
    }

    swap(&maxheap->arr[index], &maxheap->arr[maxindex]);
    maxheap_shiftdown(maxheap, maxindex);
}

// Insert New Element
void maxheap_push(struct MaxHeap *maxheap, int value) {
    if (maxheap->size < MAX_STACK_SIZE) {
        maxheap->arr[maxheap->size] = value;
        maxheap_shiftup(maxheap, maxheap->size);
        maxheap->size += 1;
    }
    else {
        printf("Error: Heap is Full, Failed to Push!\n");
    }
}

// Remove Max
void maxheap_pop(struct MaxHeap *maxheap) {
    if(maxheap->size > 0) {
        // swap root with last element
        swap(&maxheap->arr[0], &maxheap->arr[maxheap->size - 1]);
        // dec size by 1
        maxheap->size -= 1;
        maxheap_shiftdown(maxheap, 0);
    }
    else {
        printf("Error: Heap is Empty, Failed to Pop!\n");
    }
}

// Return Maximum Element
int maxheap_top(struct MaxHeap *maxheap) {
    if(maxheap->size > 0) {
        return maxheap->arr[0];
    }
    else {
        printf("Error: Heap is Empty, Failed to Get Top Element!\n");
    }
}

void print(int value) {
    printf("%d\n", value);
}

int main() {
    struct MaxHeap* maxheap1 = new_maxheap();
    
    maxheap_push(maxheap1, 10);
    maxheap_push(maxheap1, 100);
    maxheap_push(maxheap1, 5);
    maxheap_push(maxheap1, 500);
    maxheap_pop(maxheap1);
    maxheap_pop(maxheap1);
    maxheap_pop(maxheap1);
    maxheap_pop(maxheap1);

    for(int i = 0; i < 4; ++i) {
        print(maxheap1->arr[i]);
    }

    // print(maxheap_top(maxheap1));


    return 0;
}