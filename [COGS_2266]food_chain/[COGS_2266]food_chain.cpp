#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100001;
vector<int> G[maxn];
//int ind[maxn];
int ind2[maxn];
int outd[maxn];
int cnt = 0;
vector<int> topos;
int d[maxn];
int n, m;

int dp(int i);
void init();
void work();

int main()
{
	freopen("chain_2016.in", "r", stdin);
	freopen("chain_2016.out", "w", stdout);
	init();
	for (int i = 1; i <= n; ++i)
	{
		dp(i);
	}
	work();
	cout << cnt << endl;
	return 0;
}

void init()
{
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		G[u].push_back(v);
		//++ind[v];
		++ind2[v];
		++outd[u];
	}
}

int dp(int i)
{
	if (d[i] != 0)
	{
		return d[i];
	}
	if (outd[i] == 0)
	{
		d[i] = 1;
		return d[i];
	}
	d[i] = 0;
	int size = G[i].size();
	for (int j = 0; j < size; ++j)
	{
		d[i] += dp(G[i][j]);
	}
	return d[i];
}

void work()
{
	cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (ind2[i] == 0 && outd[i] != 0)
		{
			cnt += d[i];
		}
	}
	return;
}
