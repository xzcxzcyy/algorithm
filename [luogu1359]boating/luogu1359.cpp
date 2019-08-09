#include <iostream>
#include <algorithm>

//#define DEBUG

using namespace std;

int r[201][201];
int dp(int i, int j);
int f[201][201];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            cin >> r[i][j];
            f[i][j] = -1;
        }
    }
    cout << dp(1, n);
    return 0;
}

int dp(int i, int j)
{

#ifdef DEBUG
    if (i >= j)
    {
        cout << "error:i>=j" << endl;
        abort();
    }
#endif

    if (i + 1 == j)
    {
        return r[i][j];
    }
    if (f[i][j] != -1)
    {
        return f[i][j];
    }

    int minc = r[i][j];
    for (int x = i + 1; x < j; ++x)
    {
        minc = min(minc, dp(i, x) + dp(x, j));
    }
    f[i][j] = minc;
    return f[i][j];
}
