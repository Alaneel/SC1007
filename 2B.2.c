#include <stdio.h>
#include <stdlib.h>

void myfunc();

int main()
{
    myfunc();
}

void myfunc()
{
    int *i = malloc(sizeof(int));
    free(i);
}