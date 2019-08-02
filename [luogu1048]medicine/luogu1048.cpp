#include <iostream>
#include <cmath>

using namespace std;

int f[1001] = {0};
int w[101] = {0};
int v[101] = {0};

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
        for (int j = T; j >= w[i]; --j)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[T];
    return 0;
}