#include <iostream>
#include <algorithm>

using namespace std;

int w[26] = {0};
int f[30001] = {0};
int v[26] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    int price, importance;
    for (int i = 1; i <= m; ++i)
    {
        cin >> price >> importance;
        w[i] = price;
        v[i] = price * importance;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = n; j >= w[i]; --j)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[n];
    return 0;
}
