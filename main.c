#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "input.h"

int task(char* input)
{
  int reg,i = 0;
  Stack* s = malloc(sizeof(Stack));
  s->head = NULL;
  while(input[i])
  {
    if(input[i] >= '0' && input[i] <= '9')
    {
      push(s,(int)(input[i] - '0'));
    }
    else
    {
      if(length(s) < 2)
      {
        printf("\nError: Incorrect input\n");
        clear(s);
        return 1;
      }
      switch(input[i])
      {
        case '+':
          reg = pop(s);
          reg += pop(s);
          push(s,reg);
          break;
        case '-':
          reg = pop(s);
          reg -= pop(s);
          push(s,reg);
          break;
        case '*':
          reg = pop(s);
          reg *= pop(s);
          push(s,reg);
          break;
        case '/':
          reg = pop(s);
          reg /= pop(s);
          push(s,reg);
          break;
        default:
          printf("\nError: Incorrect input\n");
          clear(s);
          return 1;
      }
    }
    i++;
  }
  printf("\n");
  if(input[0] != 0)
    printf("Answer: %d\n", pop(s));
  clear(s);
  return 0;
}

int main()
{
  char *a = NULL;
  int flag = 1;
  printf("Enter your calculation in prefix notation.\nProgram is working untill EOF(Ctrl+D)\n");
  do
  {
    a = input(&flag);

    task(a);
    free(a);
  }while(flag);
  return 0;
}