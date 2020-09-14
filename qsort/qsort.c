#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

void mqsort(int *begin, int *end);
void swap(int *x, int *y);
int mrand(int length);

uint32_t xor128(void)
{
    static uint32_t x = 123456789;
    static uint32_t y = 362436069;
    static uint32_t z = 521288629;
    static uint32_t w = 88675123;
    uint32_t t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = w ^ (w >> 19) ^ (t ^ (t >> 8));
}

int arr[100010];

int main()
{
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
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

    int *i = begin, *j = end - 1;
    int pivot = *(begin + mrand(end - begin));
    while (i <= j)
    {
        while (*i < pivot)
        {
            ++i;
        }
        while (*j > pivot)
        {
            --j;
        }
        if (i <= j)
        {
            swap(i, j);
            ++i;
            --j;
        }
    }

    mqsort(begin, j + 1);
    mqsort(i, end);
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
    int a = xor128() % length;
    int b = xor128() % length;
    int c = xor128() % length;

    if (a <= b && b <= c || c <= b && b <= a)
    {
        return b;
    }
    else if (b <= a && a <= c || c <= a && a <= b)
    {
        return a;
    }
    else
    {
        return c;
    }
}
