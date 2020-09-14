#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    string s;
    cin >> s;
    int res = lengthOfLongestSubstring(s);
    cout << res << endl;
    return 0;
}

int lengthOfLongestSubstring(string s)
{
    vector<int> dp(s.length());
    for (int i = 0; i < s.length(); ++i)
    {
        if (i == 0)
        {
            dp[i] = 1;
            continue;
        }
        else
        {
            auto c = s[i];
            //bool flag = true;
            int j;
            for (j = 0; j < dp[i - 1]; j++)
            {
                if (s[i - 1 - j] == c)
                {
                    //flag = false;
                    break;
                }
            }
            dp[i] = i - (i - 1 - j);
        }
    }

    return *max_element(dp.begin(), dp.end());
}
