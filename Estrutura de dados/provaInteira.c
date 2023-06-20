#include <stdio.h>
#include <stdlib.h>

struct tpoint
{
    int x, y;
    struct tpoint *next, *prev;
}; typedef struct tpoint point;

struct tsent
{
    struct tpoint *first, *last;
}; typedef struct tsent sentinela;

// Questão 1
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
            if (aux1->x == aux2->x && aux1->y == aux2->y)
            {
                p = (point *)malloc(sizeof(point));
                p->x = aux1->x;
                p->y = aux1->y;
                p->next = NULL;
                p->prev = NULL;
                if (sr->first == NULL)
                {
                    sr->first = p;
                    sr->last = p;
                }
                else
                {
                    sr->last->next = p;
                    p->prev = sr->last;
                    sr->last = p;
                }
                break;
            }
        }
    }
    return sr;
}

// Questão 4
void insertAfter(sentinela *list, point *new, int x, int y)
{
    point *aux;
    if (list->first == NULL)
    {
        list->first = new;
        list->last = new;
    }
    else
    {
        for (aux = list->first; aux != NULL; aux = aux->next)
        {
            if (aux->x == x && aux->y == y)
            {
                if (list->last == aux)
                {
                    new->prev = aux; // =list->last
                    list->last->next = new;
                    list->last = new;
                }
                else
                {
                    new->prev = aux;
                    new->next = aux->next;
                    aux->next->prev = new;
                    aux->next = new;
                }
                break;
            }
        }
    }
}

// Questão 2
void deletePoint(sentinela *s, int x, int y)
{
    point *aux;
    for (aux = s->first; aux != NULL; aux = aux->next)
    {
        if (aux->x == x && aux->y == y)
        {                       // encontrou
            if (aux = s->first) // primeiro caso
            {
                s->first = aux->next;
                free(s->first->prev);
                s->first->prev = NULL;
                aux = s->first;
            }
            else
            {
                if (aux == s->last)
                { // terceiro caso
                    s->last = s->last->prev;
                    free(s->last->next);
                    s->last->next = NULL;
                    aux = s->last;
                }
                else
                { // segundo caso
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    aux = aux->prev;
                    free(aux->next);
                }
            }
        }
    }
}
