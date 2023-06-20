#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// pode alterar o vetor com os valor que quiser
#define MAX 10000

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[])
{
    int i, j, min_idx;

    for (i = 0; i < MAX - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < MAX; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void mostrarVetor(int vetor[])
{
    for (int i = 0; i < MAX - 1; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int vectorSelect[MAX];
    clock_t start, finish;
    double tempo[3];

    printf("Valores desordenados:\n");
    for (int i = 0; i < MAX; i++)
    {
        int random = rand() % 5000;
        vectorSelect[i] = random;

        i == MAX - 1 ? printf("%d.\n\n\n", random) : printf("%d, ", random);
    }

    printf("\n\n-----------------------------------------------------------------------");
    printf("\n\t\t\t=== Metodo Select Sort ===\n");

    start = clock();
    selectionSort(vectorSelect);
    finish = clock();

    printf("Ordem Aleatoria\n");
    for (int r =0; r < MAX; r++)
        printf("%d ",  vectorSelect[r]);
    printf("\n\n");

    tempo[2] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    printf("\n");
    printf("\nTempo gasto para ordenar :\n");
    printf("Select Sort Aleatorio:    %.5lf ms\n", tempo[2]);
    printf("\n");
}