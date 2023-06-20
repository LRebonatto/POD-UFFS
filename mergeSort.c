#include <stdio.h>
#include <stdlib.h>

void intercala(int A[], int inicio, int meio, int fim)
{
    int aux[fim - inicio + 1]; // alocar dinamicamente o vetor.
    int i, j, k;
    i = inicio;
    j = meio + 1;
    k = 0;

    while (meio >= i && fim >= j)
    {
        if (A[i] <= A[j])
        {
            aux[k] = A[i];
            i++;
        }
        else
        {
            aux[k] = A[j];
            j++;
        }
        k++;
    }

    while (i <= meio)
    {
        aux[k++] = A[i++];
    }

    while (j <= fim)
    {
        aux[k++] = A[j++];
    }

    for (int i = inicio; i < fim + 1; i++)
    {
        A[i] = aux[i - inicio];
    }
}

// Função que realiza o Merge Sort
void mergeSort(int A[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(A, inicio, meio);
        mergeSort(A, meio + 1, fim);
        intercala(A, inicio, meio, fim);
    }
}

/*Função para printar o vetor*/
void printVetor(int vet[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", vet[i]);
    }
    printf("\n");
}

int main()
{
    int vet[] = {8, 3, 7, 5, 15, 23, 8}, N = 7;
    printf("\nDisordered Vector\n");
    printVetor(vet, N);
    printf("Merge Sort \n");
    mergeSort(vet, 0, N - 1);
    // int *x = mergeSort(vet, 0,  N);
    printVetor(vet, N);

    return 0;
}