#include <string.h>
#include <stdlib.h>
#include "stack.h"

typedef struct V
{
    int* arr;
    int len;
}V;

void push(Stack* self, int k){
    if(self->head != NULL){
        ((V*)self->head)->arr = realloc(((V*)self->head)->arr, (((V*)self->head)->len + 1)*sizeof(int));
        (((V*)self->head)->arr)[((V*)self->head)->len] = k;
        ((V*)self->head)->len += 1;
    }
    else{
        self->head = malloc(sizeof(V));
        ((V*)self->head)->arr = malloc(sizeof(int));
        ((V*)self->head)->arr[0] = k;
        ((V*)self->head)->len = 1;
    } 
}

int length(Stack* s)
{
    int res = 0;
    if(s->head)
    {
        V* c = s->head;
        res = c->len; 
    }
    return res;
}

int pop(Stack* self){
    if(self->head != NULL){
        int l = ((V*)self->head)->len;
        int k = ((V*)self->head)->arr[l-1];
        ((V*)self->head)->arr = realloc(((V*)self->head)->arr, (l-1) * sizeof(int));
        ((V*)self->head)->len -= 1;
        return k;
    }else{
        return 0;
    }
}



void clear(Stack* s)
{
    if(s->head != NULL)
    {
        free(((V*)s->head)->arr);
        free(s->head);
    }
    if(s != NULL)
    free(s);
}