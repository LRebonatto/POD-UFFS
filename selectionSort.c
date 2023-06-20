#include <stdio.h>
#include <stdlib.h>

/// pode alterar o vetor com os valor que quiser

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int N)
{
    int min_idx;
    //procurar indice do menor valor
    //ordenar no menor para o maior
    //parte ordenada na direita

    for (int i = 0; i < N - 1; i++)
    {

        min_idx = i;
        for (int j = i + 1; j < N; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void mostrarVetor(int vet[], int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

//algoritimo não é estável, troca mesmo se for igual
int main()
{
    int vet[] = {8, 3, 7, 5, 15, 23, 8}, N = 7;
    selectionSort(vet, N);
    printf("\nSelection Sort\n");
    mostrarVetor(vet, N);
}