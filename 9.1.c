// Generic Search Algorithm

#include <stdio.h>

int main()
{
    int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}, key = 0, i = 0;
    for (i=0; i<9; i++)
    {
        if (numbers[i] == key) return 1;
        return 0;
    }
}