#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
  int dia;
  int mes;
  int ano;
} Data;

typedef struct aluno{
  char matricula[10];
  char nome[40];
  float media_geral;
  Data data_nascimento;
  struct aluno *proximo;
} Aluno;

Aluno *primeiro_aluno;

void printData(Data d){
  printf("%d/%d/%d", d.dia, d.mes, d.ano);
}

void print_aluno(Aluno *aluno){
  printf("%s, ", aluno->matricula);
  printf("%s, ", aluno->nome);
  printData(aluno->data_nascimento);
  printf(", ");
  printf("%.2f\n", aluno->media_geral);
}

void inserirAluno(){
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  scanf("%s", &aluno->matricula);
  scanf("%s", &aluno->nome);
  scanf("%d/%d/%d", &aluno->data_nascimento.dia, &aluno->data_nascimento.mes, &aluno->data_nascimento.ano);
  scanf("%f", &aluno->media_geral);
  aluno->proximo = NULL;

  if (!primeiro_aluno){
    primeiro_aluno = aluno;
  }else{
    Aluno *alunoI = primeiro_aluno;
    while (alunoI){
      if (!alunoI->proximo){
        alunoI->proximo = aluno;
        break;
      }
    alunoI = alunoI->proximo;
    }
  }
}

void apagarAluno(){
  char matricula[10];
  scanf("%s", &matricula);
  Aluno *alunoAux = primeiro_aluno;
  Aluno *prevAluno;
  while (alunoAux){
    if (!strcmp(alunoAux->matricula, matricula)){
      if (alunoAux == primeiro_aluno){
        Aluno *aux = primeiro_aluno->proximo;
        free(alunoAux);
        primeiro_aluno = aux;
      }else{
        prevAluno->proximo = alunoAux->proximo;
        free(alunoAux);
      }
    }
    prevAluno = alunoAux;
    alunoAux = alunoAux->proximo;
  }
}

void mostraLista(){
  Aluno *alunoAux = primeiro_aluno;
  if (!primeiro_aluno){
    printf("Lista vazia\n");
    return;
  }
  while (alunoAux){
    print_aluno(alunoAux);
    alunoAux = alunoAux->proximo;
  }
}

int contaAlunos(){
  int acc = 0;
  Aluno *alunoAux = primeiro_aluno;
  while (alunoAux){
    acc++;
    alunoAux = alunoAux->proximo;
  }
  return acc;
}

void mostraQuantidade(){
  printf("%d\n", contaAlunos());
}

void mostraListaInvertida(){
  if (!primeiro_aluno){
    printf("Lista vazia\n");
    return;
  }
  for (int i = contaAlunos() - 1; i >= 0; i--){
    Aluno *alunoAux = primeiro_aluno;
    for (int j = i - 1; j >= 0; j--){
        alunoAux = alunoAux->proximo;
    }
    print_aluno(alunoAux);
  }
}

void zeraLista(){
  Aluno *alunoAux = primeiro_aluno;
  while (alunoAux != NULL){
    Aluno *aux = alunoAux->proximo;
    free(alunoAux);
    printf("-");
    alunoAux = aux;
  }
  printf("\n");
}

int main(){
  int menu;

  while (scanf("%d", &menu)){
    switch (menu){
    case 1:
      inserirAluno();
      break;

    case 2:
      apagarAluno();
      break;

    case 3:
      mostraLista();
      break;

    case 4:
      mostraListaInvertida();
      break;

    case 5:
      mostraQuantidade();
      break;

    case 0:
      zeraLista();
      return 0;
    }
  };

  return 0;
}