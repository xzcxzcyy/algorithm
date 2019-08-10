#include <iostream>
#include <algorithm>

using namespace std;

int f[20001];
int w[31];

int main()
{
    int v;
    cin >> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> w[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = v; j >= w[i]; --j)
        {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }

    cout << v - f[v];

    return 0;
}
