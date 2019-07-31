#include <iostream>
#include <cstdio>
#include <iomanip>
#define DEBUG

using namespace std;

double a, b;

int main()
{
#ifndef DEBUG
    freopen("aplusb.in", "r", stdin);
    freopen("aplusb.out", "w", stdout);
#endif
    cin >> a >> b;
    cout << setiosflags(ios::fixed) << setprecision(0) << a + b << endl;
    return 0;
}