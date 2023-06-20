#include <stdio.h>
#include <stdlib.h>

//Estrutura base do nó.
struct Node
{
    int nData;
    struct Node *proximo;
};
 
typedef struct Node node; 
//Função pra printar o nó na tela.
void displayLL(node *p)
{
    printf("Mostrando a lista:\n"); 
    if(p)
    {
        do
        {
            printf(" %d", p->nData);
            p=p->proximo;
        }
        while(p);
    }
    else
        printf("Lista vazia.");
}
 
 
 
int main(void)
{
    node *pNode1 = NULL;
    node *pNode2 = NULL;
    node *pNode3 = NULL;
     
    //Criando os nos e associando os dados.
    pNode1 = (node*) malloc(sizeof(node*));
    pNode1->nData = 10;
     
    pNode2 = (node*) malloc(sizeof(node*));
    pNode2->nData = 20;
     
    pNode3 = (node*) malloc(sizeof(node*));
    pNode3->nData = 30;
     
    //Conectando os nós
    pNode1->proximo = pNode2;
    pNode2->proximo = pNode3;  
    pNode3->proximo = NULL;
     
    //Mostrando a lista.
    if(pNode1)  
        displayLL(pNode1);
  
  free(pNode1);
  free(pNode2);
  free(pNode3);
  
  return 0;
}