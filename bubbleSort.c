#include <stdio.h>
#include <stdlib.h>

void bubbleVec(int vet[], int N)
{
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                int aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
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
//algoritimo estável, não troca se for igual

int main()
{
    int vet[] = {8, 3, 7, 5, 15, 23, 8}, N = 7;
    printf("Bubble Sort:\n");
    bubbleVec(vet, N);
    mostrarVetor(vet, N);

    return 0;
}
