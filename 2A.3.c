#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char *str;
    printf("How long is your string: \n");
    scanf("%d", &n);
    str = malloc(n+1); // With the '\0' at the end
    if (str == NULL) printf("Uh oh\n");
    scanf("%s", str);
    printf("Your string is: %s\n", str);
    return 0;
}