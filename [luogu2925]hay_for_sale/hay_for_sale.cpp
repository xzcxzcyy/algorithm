#include <iostream>
#include <cmath>

using namespace std;

int f[50001] = {0};
int w[5001] = {0};

int main()
{
    int c, h;
    cin >> c >> h;
    for (int i = 1; i <= h; ++i)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= h; ++i)
    {
        for (int j = c; j >= w[i]; --j)
        {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }
    cout << f[c];
    return 0;
}
