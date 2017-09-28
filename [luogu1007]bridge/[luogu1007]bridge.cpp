#include <iostream>

using namespace std;

bool exit[6000] = {0};
int main()
{
    int L;
    cin >> L;
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "0 0" << endl;
        return 0;
    }
    int pos;
    for (int i = 1; i <= n; ++i)
    {
        cin >> pos;
        exit[pos] = true;
    }
    int j, k;
    if (L % 2 == 0)
    {
        j = L / 2;
        k = j + 1;
    }
    else
    {
        j = k = (L + 1) / 2;
    }
    for (; j >= 1, k <= L; --j, ++k) //min time
    {
        if (exit[j])
        {
            cout << j - 0 << " ";
            break;
        }
        if (exit[k])
        {
            cout << L + 1 - k << " ";
            break;
        }
    }
    j = 1;
    k = L;
    for (; j <= k; ++j, --k) //max time
    {
        if (exit[j])
        {
            cout << L + 1 - j << " ";
            break;
        }
        if (exit[k])
        {
            cout << k - 0 << " ";
            break;
        }
    }
    return 0;
}