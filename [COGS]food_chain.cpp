#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn=100001;
vector<int> G[maxn];
int ind[maxn];
int ind2[maxn];
int outd[maxn];
int cnt=0;
vector<int> topos;
int d[maxn];
int n,m;

void toposort();
void dp();
void init();
void work();

int main()
{
	freopen("chain_2016.in","r",stdin);
	freopen("chain_2016.out","w",stdout);
	init();
	toposort();
	dp();
	work();
	cout<<cnt<<endl;
	return 0;
}

void init()
{
	cin>>n>>m;
	int u,v;
	for (int i=1;i<=m;++i)
	{
		cin>>u>>v;
		G[u].push_back(v);
		++ind[v];
		++ind2[v];
		++outd[u];
	}
}

void toposort()
{
	for (int i=1;i<=n;++i)
	{
		int j=1;
		while (ind[j]!=0) ++j;
		topos.push_back(j);
		ind[j]=-1;
		int size=G[j].size();
		for (int k=0;k<size;++k)
		{
			--ind[G[j][k]];
		}
	}
}

void dp()
{
    int size=topos.size();
    for (int i=size-1;i>=0;--i)
    {
        int cur=topos[i];
        d[cur]=0;
        if (outd[cur]==0)
        {
            d[cur]=1;
            continue;
        }
        for (int j=0;j<G[cur].size();++j)
        {
            d[cur] += d[ G[cur][j] ];
        }
    }
}

void work()
{
	cnt=0;
	for (int i=1;i<=n;++i)
	{
		if (ind2[i]==0&&outd[i]!=0)
		{
			cnt+=d[i];
		}
	}
	return;
}
