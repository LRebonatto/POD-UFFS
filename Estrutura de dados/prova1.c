#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tpoint
{
  int x, y;
  struct tpoint *next, *prev;
};

struct tsent
{
  struct tpoint *first;
  struct tpoint *last;
};

typedef struct tpoint point;
typedef struct tsent sentinela;

sentinela *Intersec(sentinela *s1, sentinela *s2)
{
  sentinela *sr = {NULL, NULL};
  point *aux1, *aux2, *p;
  sr = (sentinela *)malloc(sizeof(sentinela));
  sr->first = NULL;
  sr->last = NULL;
  for (aux1 = s1->first; aux1 != NULL; aux1 = aux1->next)
  {
    for (aux2 = s2->first; aux2 != NULL; aux2 = aux2->next)
    {
      if (aux1->x == aux2->x && aux1->y == aux2->y){
          p = (point *)malloc(sizeof(point));
          p->x=aux1->x;
          p->y=aux1->y;
          p->next= NULL;
          p->prev = NULL;
          if (sr->first=NULL){
            sr->first = p;
            sr-> last = p;
          } else {
            sr->last->prev = p;
            p-> prev = sr->last;
            sr->last = p;
          }
          break;
      }
    }
    return sr;
  }
}

int main()
{
  
}