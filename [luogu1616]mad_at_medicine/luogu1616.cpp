#include <iostream>

using namespace std;

int f[100001] = {0};
int w[10001] = {0};
int v[10001] = {0};

int main()
{
    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= M; ++i)
    {
        for (int j = w[i]; j <= T; ++j)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }

    cout << f[T];
    return 0;
}



