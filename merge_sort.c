#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void merge(int A[], int B[], int result[], int An, int Bn) {
    int p1 = 0;
    int p2 = 0;
    int counter = 0;

    while(p1 < An && p2 < Bn) {
        if(A[p1] < B[p2]) {
            result[counter++] = A[p1];
            p1++;
        }
        else {
            result[counter++] = B[p2];
            p2++;
        }
    }
    while(p1 < An) {
        result[counter++] = A[p1];
        p1++;
    }
    while(p2 < Bn) {
        result[counter++] = B[p2];
        p2++;
    }
}

// return sorted array
void merge_sort(int A[], int sorted[], int l, int r) {

    if(l == r) {
        sorted[0] = A[l];
        return;
    };

    int mid = (l + r) / 2;
    int left_size = mid - l + 1;
    int right_size = r - mid;

    int sorted_left[left_size];
    int sorted_right[right_size];

    merge_sort(A, sorted_left, l, mid);
    merge_sort(A, sorted_right, mid+1, r);
    merge(sorted_left, sorted_right, sorted, left_size, right_size);
}

int main() {
    int A[8] = {5, 6, 3, 8, 4, 3, 2, 1};
    int sorted_A[8];
    merge_sort(A, sorted_A, 0, 7);

    for (int i = 0; i < 8; ++i)
    {
        printf("%d\n", sorted_A[i]);
    }
    
    return 0;
}