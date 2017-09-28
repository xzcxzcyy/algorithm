#include <iostream>

using namespace std;

int ans[100] = {0};
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            for (int k = 1; k <= c; ++k)
            {
                ans[i + j + k] += 1;
            }
        }
    }
    int times = ans[1];
    int sum = 1;
    for (int i = 1; i <= a + b + c; ++i)
    {
        if (ans[i] > times)
        {
            times = ans[i];
            sum = i;
        }
    }
    cout << sum << endl;
    return 0;
}