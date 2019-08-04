#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node
{
private:
    vector<int> floor;

public:
    int n;
    int dp[5051];
    int sum;
    friend istream &operator>>(istream &in, Node &node)
    {
        int temp;
        node.sum = 0;
        while (true)
        {
            cin >> temp;
            if (temp == -1)
            {
                break;
            }
            else
            {
                node.floor.push_back(temp);
                node.sum += temp;
            }
        }

        node.n = node.floor.size();
        return in;
    }

    int get(int i)
    {
        //int test = floor[i - 1];
        return floor[i - 1];
    }

    void cal(int m)
    {
        for (int i = 0; i <= m; ++i)
        {
            dp[i] = 0;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = m; j >= get(i); --j)
            {
                //int test = get(i);
                dp[j] = max(dp[j], dp[j - get(i)] + get(i));
            }
        }
    }
};

int main()
{
    vector<Node> castles;
    Node temp;
    int N;
    cin >> N;
    int minsum = 100000;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        castles.push_back(temp);
        if (castles[i].sum < minsum)
        {
            minsum = castles[i].sum;
        }
    }

    for (int i = 0; i < N; ++i)
    {
        castles[i].cal(minsum);
    }

    bool flag = true;
    int i, s;
    for (s = minsum; s >= 0 && flag; --s)
    {
        for (i = 0; i < N; ++i)
        {
            if (castles[i].dp[s] != castles[0].dp[s])
                break;
        }
        if (i == N && castles[i - 1].dp[s] == castles[0].dp[s])
        {
            flag = false;
        }
    }
    cout << castles[0].dp[s + 1];
    return 0;
}
