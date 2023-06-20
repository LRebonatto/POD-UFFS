#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Troca de posição dois valores
void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Função que cria o heap
void criaHeap(int A[], int i, int N)
{
    int maior, left, right;
    maior = i;
    left = 2 * i + 1;
    right = 2 * i + 2;

    if (left < N && A[left] > A[i])
    {
        maior = left;
    }

    if (right < N && A[right] > A[maior])
    {
        maior = right;
    }

    if (maior != i)
    {
        troca(&A[i], &A[maior]);
        criaHeap(A, maior, N);
    }
}

// Função principal do Quick Sort
void heapSort(int A[], int N)
{
    int k; // DECLARA contador
    for (k = (N / 2) - 1; k >= 0; k--)
    {
        criaHeap(A, k, N); // vetor[], 499, 
    }

    for (k = N - 1; k > 0; k--)//contador de penultimo até o primeiro, pq o último(maior) já foi encontrado(definido ao buscar max heap)
    {
        troca(&A[0], &A[k]); // troca o primeiro pelo 
        criaHeap(A, 0, k); //
    }
}


int main()
{
    int A[1000];
    int N = 1000;
    printf("HEAP SORT\n\n");
    heapSort(A, N); 
    return 0;
}