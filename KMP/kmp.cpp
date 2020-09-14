#include <iostream>
#include <cstring>

using namespace std;

const int mmax = 100;
int n[mmax];

void makeNext(char *p);
int kmp(char *s, char *p);

int main()
{
}

void makeNext(char *p)
{
    int k, j;
    k = -1;
    j = 0;
    n[0] = -1;
    int len = strlen(p);
    while (j < len)
    {
        if (k == -1 || p[k] == p[j])
        {
            ++k;
            ++p;
            if (p[j] == p[k])
            {
                n[j] = n[k];
            }
            else
            {
                n[j] = k;
            }
        }
        else
        {
            k = n[k];
        }
        }
}
