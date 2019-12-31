#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <assert.h>
#pragma GCC("-W1,--stack=128000000")

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
    //freopen(".\\qsort\\testdata.in", "r", stdin);
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
    int temp = *p;
    int *a = begin, *b = end;
    while (1)
    {
        while (*(++a) < temp)
        {
            if (a == end - 1)
            {
                break;
            }
        }
        while (temp < *(--b))
        {
            if (b == begin)
            {
                break;
            }
        }
        if (a >= b)
        {
            break;
        }
        swap(a, b);
    }
    swap(p, b);
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
    int a = rand() % length;
    int b = rand() % length;
    int c = rand() % length;

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
