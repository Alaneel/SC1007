#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    int *int_arr;
    printf("How many integets do you have: \n");
    scanf("%d", &n);
    int_arr = malloc(n * sizeof(int));
    if (int_arr == NULL)
        printf("Uh oh\n");
    printf("Enter the numbers: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", int_arr+i);
    }
    for (i=0; i<n; i++)
        printf("The magic number %d: %d\n", i+1, *(int_arr+i));
    return 0;
}