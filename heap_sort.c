#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_STACK_SIZE 100000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

// Heap Shift Down
void maxheap_shiftdown(int N, int arr[], int index) {
    int left = maxheap_leftchild(index);
    int right = maxheap_rightchild(index);

    int maxindex = index;

    if(left < N && arr[left] > arr[maxindex]) {
        maxindex = left;
    }

    if(right < N && arr[right] > arr[maxindex]) {
        maxindex = right;
    }

    // base
    if(maxindex == index) {
        return;
    }

    swap(&arr[index], &arr[maxindex]);
    maxheap_shiftdown(N, arr, maxindex);
}

// Remove Max
void maxheap_pop(int *N, int arr[]) {
    if(*N > 0) {
        swap(&arr[0], &arr[*N - 1]);
        *N -= 1;
        maxheap_shiftdown(*N, arr, 0);
    }
    else {
        printf("Error: Heap is Empty, Failed to Pop!\n");
    }
}

void print(int value) {
    printf("%d\n", value);
}

void buildheap(int N, int arr[]) {
    for (int i = N-1; i >= 0; --i)
    {
        maxheap_shiftdown(N, arr, i);
    }
}

void heapsort(int N, int arr[]) {
    
    // build heap - convert the given array into heap
    buildheap(N, arr);

    // Pop N times
    while(N > 0) {
        // pop function will decrement the value of N by 1
        maxheap_pop(&N, arr);
    }

}

int main() {

    int arr[] = {100, 20, 50, 1, 15, 69};
    heapsort(6, arr);

    for (int i = 0; i < 6; ++i)
    {
        print(arr[i]);
    }
    
    return 0;
}