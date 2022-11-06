#include <stdio.h>
#define N 15

// Recursive Version
int binarySearch(int E[], int first, int last, int k);
int binarySearch_iter(int E[], int first, int last, int k);

int main()
{
    int E[N] = {6, 13, 14, 25, 33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97};
    printf("binarySearch(): %d\n", binarySearch(E, 0, 14, 33));
    printf("binarySearch_iter(): %d\n", binarySearch_iter(E, 0, 14, 33));
    return 0;
}

int binarySearch(int E[], int first, int last, int k)
{
    if (last < first) return -1;
    else 
    {
        int mid = (first + last) / 2;
        if (k == E[mid]) return mid;
        else if (k < E[mid]) return binarySearch(E, first, mid-1, k);
        else return binarySearch(E, mid+1, last, k);
    }
}

int binarySearch_iter(int E[], int first, int last, int k)
{
    while (first <= last)
    {
        int mid = (first + last) / 2;
        if (E[mid] == k) return mid;
        else if (k < E[mid]) last = mid - 1;
        else first = mid + 1;
    }
    return -1;
}