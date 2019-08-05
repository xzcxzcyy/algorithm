#include <iostream>
#include <algorithm>

using namespace std;

long long dp[30][30];
int ctrlp[30][30];

int main()
{
    int n, m;
    int mi, mj;
    cin >> n >> m >> mi >> mj;
    ctrlp[mi][mj] = 1;
    for (int i = -2; i <= 2; i += 4)
    {
        for (int j = -1; j <= 1; j += 2)
        {
            if (mi + i >= 0 && mj + j >= 0)
            {
                ctrlp[mi + i][mj + j] = 1;
            }
            if (mi + j >= 0 && mj + i >= 0)
            {
                ctrlp[mi + j][mj + i] = 1;
            }
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (ctrlp[i][j] == 0)
            {
                if (i >= 0 && j - 1 >= 0 && ctrlp[i][j - 1] == 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
                if (i - 1 >= 0 && j >= 0 && ctrlp[i - 1][j] == 0)
                {
                    dp[i][j] += dp[i - 1][j];
                }
            }
        }
    }

    cout << dp[n][m];
    return 0;
}
