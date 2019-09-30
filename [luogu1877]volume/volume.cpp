#include <iostream>
#include <algorithm>

using namespace std;

int dp[51][1001];
int w[51];

int main()
{
	int n,begin,max;
	cin>>n>>begin>>max;
	for (int i=1;i<=n;++i)
	{
		cin>>w[i];
	}
	if(begin+w[1]<=max)
		dp[1][begin+w[1]]=1;
	if(begin-w[1]>=0)
		dp[1][begin-w[1]]=1;

	bool flag=false;
	for (int i=2;i<=n;++i)
	{
		for (int j=0;j<=max;++j)
		{
			flag=false;
			if(j-w[i]>=0 && dp[i-1][j-w[i]])
				flag=true;
			if(j+w[i]<=max && dp[i-1][j+w[i]])
				flag=true;
			if(flag)
				dp[i][j]=1;
		}
	}

	int i=max;
	while(dp[n][i]==0 && i>=0)
		--i;

	cout<<i;
	return 0;
}

