#include <iostream>
#include <vector>
#include <algorithm>

//"intelliSenseMode": "msvc-x64",

using namespace std;

struct node
{
    int w;
    int v;
};

vector<node> list[101];
int f[1001] = {0};

int main()
{
    int m, n;
    cin >> m >> n;
    node temp;
    int num;
    int t = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp.w >> temp.v >> num;
        list[num].push_back(temp);
        if (num > t)
            t = num;
    }

    int maxv = 0;
    for (int i = 0; i <= t; ++i)
    {
        for (int j = m; j >= 0; --j)
        {
            maxv = 0;
            for (int p = 0; p < list[i].size(); ++p)
            {
                if (list[i][p].w > j)
                {
                    maxv = max(f[j], maxv);
                    continue;
                }
                else
                {
                    int tmaxv = max(f[j], f[j - list[i][p].w] + list[i][p].v);
                    maxv = max(maxv, tmaxv);
                    continue;
                }
            }
            f[j] = maxv;
        }
    }

    cout << f[m];
    return 0;
}