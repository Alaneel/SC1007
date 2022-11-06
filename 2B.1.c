#include <stdio.h>
#include <stdlib.h>

struct mystruct {
    int number;
    struct mystruct *nextstruct;
};

int main()
{
    struct mystruct *firststruct;

    firststruct = malloc(sizeof(struct mystruct));
    firststruct->number = 1;
    firststruct->nextstruct = malloc(sizeof(struct mystruct)); // important!

    firststruct->nextstruct->number = 2;
    firststruct->nextstruct->nextstruct = NULL;

    return 0;
}