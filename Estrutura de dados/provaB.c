#include <stdio.h>

int main()
{
    int M = 4;
    int A[4][4] = {
        2, 4, 6, 8,
        5, 6, 7, 8,
        8, 6, 4, 2,
        8, 7, 6, 5};

    for (int i = 0; i < M; i++) {
        A[i][i] = 1;
        A[i][M - i - 1] = 1;
    }
    for (int i = 0; i < M; i++) {
        printf("\n");
        for (int j = 0; j < M; j++) {
            printf("%d ", A[i][j]);
        }
    }
    printf("\n");
    return 0;
}
