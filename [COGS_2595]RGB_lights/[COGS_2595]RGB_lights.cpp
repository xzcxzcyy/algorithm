#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>
//#define DEBUG

using namespace std;

const char color[3] = {'R', 'G', 'B'};

int main()
{
    freopen("lightt.in", "r", stdin);
    freopen("lightt.out", "w", stdout);
    int n;
    long long m;
    cin >> n >> m;
    int cur;
    stack<int> sta;
    cur = m % 3;
    sta.push(cur);
    for (int i = 1; i < n; ++i)
    {
        m /= 3;
        cur = m % 3;
        sta.push(cur);
    }

    int temp;
    while (!sta.empty())
    {
        temp = sta.top();
        sta.pop();
        cout << color[temp];
    }
    return 0;
}
