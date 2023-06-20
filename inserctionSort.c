#include <stdio.h>
#include <stdlib.h>

/*Recebe o vetor desordenado e o seu tamanho*/
int *inserctionSort(int vet[], int N)
{

    for (int i = 1; i < N; i++)
    {
        int value = vet[i], j = i - 1;
        while (j >= 0 && value < vet[j])
        { // vai jogando o valor para esquerda
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = value; // coloca na nova posição ou troca por ele mesmo
    }
    return vet;
}

/*Função para printar o vetor*/
void printVetor(int vet[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d \n", vet[i]);
    }
}

int main()
{
    int vet[] = {8, 3, 7, 5}, N = 4;
    printf("Inserction Sort \n");
    int *x = inserctionSort(vet, N);
    printVetor(x, N);
}