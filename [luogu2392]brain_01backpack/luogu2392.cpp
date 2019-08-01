#include <iostream>
#include <cmath>

using namespace std;

const int INF = -100000;
int f[1201] = {0};
int w[21];

int init(int s);
int cal(int s, int atime);

int main()
{
    int s[5], atime;
    int sum = 0;
    for (int i = 1; i <= 4; ++i)
    {
        cin >> s[i];
    }

    for (int i = 1; i <= 4; ++i)
    {
        atime = init(s[i]);
        sum += cal(s[i], atime);
    }
    cout << sum;

    return 0;
}

int init(int s)
{
    int atime = 0;
    for (int i = 1; i <= s; ++i)
    {
        cin >> w[i];
        atime += w[i];
    }

    f[0] = 0;
    for (int i = 1; i <= atime; ++i)
        f[i] = INF;

    return atime;
}

int cal(int s, int atime)
{
    for (int i = 1; i <= s; ++i)
    {
        for (int j = atime; j >= w[i]; --j)
        {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }

    int m = atime / 2;
    while (f[m] < 0)
        --m;

    return (atime - f[m]);
}
