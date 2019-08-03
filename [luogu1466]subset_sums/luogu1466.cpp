#include <iostream>
#include <algorithm>

using namespace std;

long long f[781] = {0};

int main()
{
    int n;
    cin >> n;
    int sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0)
    {
        cout << 0;
        return 0;
    }
    sum /= 2;
    f[0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = sum; j >= i; --j)
        {
            f[j] = f[j] + f[j - i];
        }
    }
    cout << f[sum] / 2;
    return 0;
}
