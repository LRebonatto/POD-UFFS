#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tdado {
	char c;
};
typedef struct tdado dado;
struct tfila {
	dado info;
	struct tfila *next;
};
typedef struct tfila fila;
struct tsent {
	fila *first; // head   
	fila *last; // tail
};
typedef struct tsent sentinela;
//
int emptyStack(sentinela s)
{
	if (s.first==NULL) return 1;
	return 0;
}
//
void initStack(sentinela *s) // sentinela initStack() {
{                            //   sentinela s;
	s->first=NULL;           //   s.first=NULL;
	s->last=NULL;            //   s.last=NULL;
}                            //   return s;}
//
void setItem(sentinela *s, dado d)
{
	fila *f;
	f=(fila *)malloc(sizeof(fila));
	f->info=d;
	f->next=NULL;
	if (emptyStack(*s)==1) {
		s->first=f;
		s->last=f;
		return;
	}
	s->last->next=f;
	s->last=f;
	return;
}
//
dado getItem(sentinela *s) {
	dado d={'@'};
	fila *aux=s->first;
	if (emptyStack(*s)==1) return d;
	d=s->first->info;
	s->first=s->first->next;
	free(aux);
	return d;
}
//
void freeStack(sentinela *s)
{
	fila *aux=s->first, *aux2;
	while (aux!=NULL)
	{
		aux2=aux;
		aux=aux->next;
		free(aux2);
    }
    initStack(s);
    return;
}
//
int main()
{
	sentinela s;
	dado d;
	char *st={"Inserir na pilha"};
	int i;
	initStack(&s);
	for (i=0;i<strlen(st);i++) {
		d.c=st[i];
		setItem(&s,d);
	}
	while (emptyStack(s)!=1)
	{
		d=getItem(&s);
		printf("%c\n",d.c);
	}
	return 0;
}