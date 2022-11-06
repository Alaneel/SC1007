// Sequential Search

#include <stdio.h>
#define N 12

int seqSearch(int data[], int n, int key);

int main()
{
    int data[N] = {4, 21, 36, 14, 62, 91, 8, 22, 7, 81, 77, 10};
    printf("seqSearch(): %d\n", seqSearch(data, N, 14));
    return 0;
}

int seqSearch(int data[], int n, int key)
{
    int i;
    for (i=0; i<n; i++)
    {
        if (data[i] == key) return i;
    }
    return -1;
}