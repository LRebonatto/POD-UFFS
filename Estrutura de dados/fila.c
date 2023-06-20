#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

typedef struct elemFila
{
    Item item;
    struct elemFila *proximo;
} ElemFila;//tpoint

typedef struct
{
    ElemFila *primeiro;
    ElemFila *ultimo;
} Fila;//sentinela

Fila *fila, *first, *last;

int emptyQueue(Fila *fila){
    if (fila->primeiro ==NULL ){
        return 1;
    }
    return 0;
}

int getItem(Fila *fila){
    Item item = {'$'};
    ElemFila *aux = fila-> primeiro;
    if (emptyQueue(fila) == 1) return item;
    
    aux->item = item;
    aux->proximo = NULL;
    
}

void insereFila(Fila *fila, Item item)
{
    ElemFila *aux;
    // Cria um novo elemento da lista encadeada que representa a fila e
    // armazena neste novo elemento o item a ser inserido na fila
    aux = malloc(sizeof(ElemFila));
    aux->item = item;
    aux->proximo = NULL;
    // Insere o novo elemento no fim da lista encadeada que representa a
    // fila
    if (fila->primeiro == NULL)
    { // Se a fila esta vazia
        fila->primeiro = aux;
        fila->ultimo = aux;
    }
    else
    { // Se a fila nao esta vazia
        fila->ultimo->proximo = aux;
        fila->ultimo = aux;
    }
}
void removeFila(Fila *fila, Item *item)
{
    ElemFila *aux;
    // Verificar se a fila esta vazia!
    // Armazena o item a ser removido da fila
    *item = fila->primeiro->item; // ATENCAO: Depende da definicao do tipo do
    // item
    // Continua no proximo slide
    // Continuacao do slide anterior
    // Armazena o primeiro elemento da lista encadeada que representa a fila e
    // remove este primeiro elemento da lista
    aux = fila->primeiro;
    if (fila->primeiro == fila->ultimo)
    {
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    }
    else
    {
        fila->primeiro = fila->primeiro->proximo;
    }
    // Libera a memoria alocada para o elemento removido
    free(aux);
}
void inicializaFila(Fila *fila)
{
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}
int filaVazia(Fila *fila)
{
    return (fila->primeiro == NULL);
}
void liberaFila(Fila *fila)
{
    ElemFila *aux;
    while (fila->primeiro != NULL)
    {
        // Armazena o primeiro elemento da lista encadeada que representa a
        // fila e remove este primeiro elemento da lista
        aux = fila->primeiro;
        fila->primeiro = fila->primeiro->proximo;
        // Libera a memoria alocada para o elemento removido
        free(aux);
    }
    fila->ultimo = NULL;
}

int main()
{
    Fila fila;
    Item item;
    inicializaFila(&fila);
    char *st={"teste"};
    for (int i = 0; i < strlen(st); i++)
    {
        //item = i;
        printf("Inserindo na fila o item %c.\n", st[i]);
        insereFila(&fila, st[i]);
    }
    while (filaVazia(&fila) == 0)
    { // Enquanto a fila nao esta vazia
        removeFila(&fila, &item);
        printf("Item %c removido da fila.\n", item);
    }
    liberaFila(&fila); // Sem efeito se a fila ja esta vazia
    return 0;
}