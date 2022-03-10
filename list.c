
#include <stdlib.h>
#include "stack.h"
#include "input.h"

typedef struct Item
{
    int item;
    struct Item* next;

}Item;

void push(Stack* self, int k){
    Item* tmp = malloc(sizeof(Item));
    tmp->item = k;
    tmp->next = self->head;
    self->head = tmp;
}

int length(Stack* s)
{
    int res = 0;
    Item* tmp = s->head;
    while(tmp)
    {
        res++;
        tmp = tmp->next;
    }
    return res;
}

int pop(Stack* self){
    Item* a = self->head;
    self->head = a->next;
    int k = a->item;
    free(a);
    return k;
}



void clear(Stack* s)
{
    if(s->head != NULL)
    {
     Item *_tmp = s->head, *_td;
     s->head = NULL;
     while(_tmp)
     {
        _td = _tmp;
        _tmp = _tmp->next;
        free(_td);
     }   
    }
    if(s != NULL)
    free(s);
}