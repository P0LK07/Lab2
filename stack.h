#ifndef STACK 
#define STACK

typedef struct Stack{
    void* head; 
}Stack;

void push(Stack*, int);
int pop(Stack*);
void clear(Stack*);
int length(Stack*);
#endif