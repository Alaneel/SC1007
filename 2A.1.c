#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;
    i = malloc(sizeof(int));
    if (i == NULL)
        printf("Uh oh\n");
    printf("Enter you number: \n");
    scanf("%d", i);
    printf("The magic number is %d\n", *i);
    return 0;
}