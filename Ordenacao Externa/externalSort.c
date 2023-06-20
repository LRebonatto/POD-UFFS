//
// Created by Rebonatto on 07/01/23.
// Trabalho 7 (ordenação externa)
// Implementar o método de ordenação externa via intercalação balanceada em linguagem C.
/*
* As regras da implementação para simular um cenário
* ● Considere o seguinte arquivo com 22 registros: I N T E R C A L A C A O B A L A N C E A D A
* ● Objetivo: ordenar os 22 registros e colocá-los num arquivo de saída;
* ● Os registros são lidos sequencialmente, um após o outro;
* ● A memória interna tem capacidade para apenas três registros;
* ● Podemos manter abertos 6 arquivos de saída (F)
* ● Metade dos arquivos (F/2) será usada para leitura (entrada) → será uma intercalação de 3 caminhos;
* ● A outra metade (F/2), para escrita (saída);
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int partition(int *v, int esq, int dir)
//{
//    int i, j;
//    int swap;
//
//    i = esq;
//
//    for(j = esq + 1; j <= dir; j++)
//        if (v[j] < v[esq]) {
//            i++;
//            swap = v[i];
//            v[i] = v[j];
//            v[j] = swap;
//        }
//    swap = v[i];
//    v[i] = v[esq];
//    v[esq] = swap;
//
//    return i;
//}

//void quicksort(int *v, int esq, int dir)
//{
//    int r;
//
//    if(esq < dir)
//    {
//        r = partition(v, esq, dir);
//        quicksort(v, esq, r - 1);
//        quicksort(v, r + 1, dir);
//    }
//}

void strSort(char *v) {
    int i, j;
    char temp[1];

    for (i = 0; i < 3; i++) {
        for (j = i; j < 3; j++) {
            if (strcmp(&v[i], &v[j]) > 0) {
                temp[0] = v[i];
                v[i] = v[j];
                v[j] = temp[0];
            }
        }
    }
}

void displayFile(File *auxp) {
    int i;
    char c;

    while (!feof(auxp)) {
        c = fgetc(auxp);
        printf("%c", c);
        i++; // length of file
    }
    printf("\n");
}

int main() {
    FILE *fp, *auxp, *temp1, *temp2, *temp3, *temp4, *temp5, *temp6;
    int cont = 0, pin = -1, i, j;
    char c;

    // Open/Create files
    fp = fopen("entrada.txt", "r+t");
    auxp = fopen("entrada.txt", "r");
    temp1 = fopen("temp1.txt", "w+t");
    temp2 = fopen("temp2.txt", "w+t");
    temp3 = fopen("temp3.txt", "w+t");
    if (fp == NULL || auxp == NULL || temp1 == NULL || temp2 == NULL || temp3 == NULL) {
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    while (!feof(auxp)) {
        fgetc(auxp);
         printf("%c", c);
        pin++; // length of file
    }

    // 1) Classificação das Partições
    while (!feof(fp)) {
        char vet[3];
        c = fgetc(auxp);
        if (c == -1) break;
        for (i = 0; i < 3; i++) {
            printf("%c \t", c);
            vet[i] = c;
        }

         fgets(vet, 4, fp);


        strSort(vet);

        if (cont < 1) {
            fputs(vet, temp1);
        } else if (cont < 2) {
            fputs(vet, temp2);
        } else if (cont < 3) {
            fputs(vet, temp3);
        } else {
            cont = 0;
            continue;
        }
        cont++;
    }

    //intercalar()

    fclose(fp);
    fclose(auxp);
    fclose(temp1);
    fclose(temp2);
    fclose(temp3);
    return 0;
}