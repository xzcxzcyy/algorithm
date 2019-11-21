#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mqsort(int *begin, int *end);
void swap(int *x, int *y);
int mrand(int length);

int arr[100000];


int main()
{
    //srand(time(NULL));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    mqsort(arr, arr + n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void mqsort(int *begin, int *end)
{
    if (end - begin <= 1)
    {
        return;
    }
    swap(begin, begin + (end - begin) / 2);
    int *p = begin;
    int *a = begin, *b = end - 1;
    while (a != b)
    {
        if (*p <= *b)
        {
            --b;
            continue;
        }
        if (*a <= *p)
        {
            ++a;
            continue;
        }
        swap(a, b);
    }
    swap(p, a);
    mqsort(begin, a);
    mqsort(a + 1, end);
}

void swap(int *x, int *y)
{
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

int mrand(int length)
{
    return rand() % length;
}
