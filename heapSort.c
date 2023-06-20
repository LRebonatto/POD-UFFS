//
// Created by Rebonatto on 26/12/22.
//
#include <stdio.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void buildHeap(int A[], int i, int n) {
    int high = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && A[left] > A[i]) {
        high = left;
    }
    if (right < n && A[right] > A[high]) {
        high = right;
    }
    if (high != i) {
        swap(&A[i], &A[high]);
        buildHeap(A, high, n);
    }
}

void heapSort(int A[], int nos) {
    int k;
    for (k = (nos / 2) - 1; k >= 0; k--)
        buildHeap(A, k, nos);

    for (k = nos - 1; k > 0; k--) {
        swap(&A[0], &A[k]);
        buildHeap(A, 0, k);
    }
}

void displayVector(int vet[], int N) {
    for (int i = 0; i < N; i++)
        printf("%d ", vet[i]);

    printf("\n");
}

//algorithm is unstable (does redundant swap) | in place
int main() {
    int vet[] = {8, 15, 2, 5, 1, 23, 8}, N = 7;
    printf("\nDisordered Vector\n");
    displayVector(vet, N);
    printf("\nDoing Heap Sort...\n");
    heapSort(vet, N);
    printf("\nOrdered Vector\n");
    displayVector(vet, N);
    return 0;
}