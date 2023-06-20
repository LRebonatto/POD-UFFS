#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quickSort(int A[], int begin, int end) {
    if (begin < end) {
        int pivot = partition(A, begin, end);
        quickSort(A, begin, pivot - 1);
        quickSort(A, pivot + 1, end);
    }
}

int partition(int A[], int begin, int end) {
    int k = begin, i;

    for (i = begin; i < end; i++) {
        if (A[i] <= A[end]) {
            swap(&A[i], &A[k]);
            k++;
        }
    }
    if (A[k] > A[end]) {
        swap(&A[k], &A[end]);
    }

    return k;
}

void displayVector(int vet[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

//algorithm is unstable (does redundant swap) | in place
int main() {
    int vet[] = {8, 3, 7, 5, 15, 23, 8}, N = 7;
    printf("\nDisordered Vector\n");
    displayVector(vet, N);
    printf("\nDoing Quick Sort...\n");
    quickSort(vet, 0, N);
    printf("\nOrdered Vector\n");
    displayVector(vet, N);
}