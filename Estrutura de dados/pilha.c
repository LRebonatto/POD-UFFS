#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//B ---- Structs ----
struct url{
    char link[61];
    struct url *next;
};
typedef struct url Site;

struct pilha {
    Site *topo;
}; 
typedef struct pilha Pilha;
//E ---- Structs ----

//B ---- Functions ----
void push(Pilha *pilha, char *link) {
    Site *newElement = malloc(sizeof(Site));
    newElement->next = NULL;
    strcpy(newElement->link, link);
    newElement->next = pilha->topo;
    pilha->topo = newElement;
}

int isEmpty(Pilha *pilha) {
    if (pilha->topo == NULL){
        printf("Vazio!\n");
        return 1;
    }
    return 0;
}

int pop(Pilha *pilha, char *link) {
    Site *aux;
    char *aux2;
    aux = pilha->topo;
    pilha->topo = pilha->topo->next;
    aux2 = aux->link;
    printf("%s\n", aux2);
    free(aux);
    return *aux2;
}

void freeStack(Pilha *pilha, char *link) {
    Site *aux = pilha->topo, *prev;

    while (aux != NULL){
        prev = aux;
        aux = aux->next;
        free(prev);
    }

    if (pilha->topo != NULL){
        for (aux = pilha->topo; aux != NULL; aux = aux->next){
            printf("@\n");
        }
        free(pilha);
    }else{
        printf("!\n");
    }
}
//E ---- Functions ----

// ---- MAIN ----
int main() {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->topo = NULL;

    while ("presente" != "fim"){
        char link[61];
        scanf("%s", link);

        if (strcmp(link, "E") == 0) { //finalizar
            freeStack(pilha, link);
            break;
        }
        else if (strcmp(link, "B") == 0) { //voltar
            if (!isEmpty(pilha)){
                pop(pilha, link);
            }
        }
        else { //adicionar
            push(pilha, link);
        }
    }
    return 0;
}