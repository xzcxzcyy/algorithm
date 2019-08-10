#include <iostream>
#include <algorithm>

using namespace std;

int f[2001];
int c[2001][2001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
        }
    }

    for (int j = 1; j <= m; ++j)
    {
        f[j] = c[j][1];
    }
    for (int i = 2; i <= n; ++i)
    {
        f[0] = f[m];
        for (int j = m; j >= 1; --j)
        {
            f[j] = min(f[j], f[j - 1]) + c[j][i];
        }
    }

    int mint = f[1];
    for (int j = 1; j <= m; ++j)
    {
        mint = (f[j] < mint ? f[j] : mint);
    }

    cout << mint;

    return 0;
}
