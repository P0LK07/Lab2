#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "input.h"

char* get_line(int* f)
{
    int i = 0;
    char* res = malloc(1);
    char k;
    while((k = getchar()) != EOF)
    {
        if(k == '\n')
            break;
        i++;
        res = realloc(res, i+1);
        res[i-1] = k;
    }
    if(k != '\n')
        *f = 0;
    res[i] = 0;
    return res;
}

char* input(int* flag)
{
    printf("Enter expression: ");
    char* a = get_line(flag);
    int len = strlen(a), i, k;
    for(i = 0, k = len - 1; i < len/2; i++, k--)
    {
        a[i] ^= a[k];
        a[k] ^= a[i];
        a[i] ^= a[k];
    }
    return (char*)a;
}