#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[100];
    bool g(int j, string &s, string &a)
    {
        if (s.size() - j + 1 < a.size())
            return false;
        for (int i = 0; i < a.size(); i++)
        {
            if (s[j + i] != a[i])
                return false;
        }
        return true;
    }
    int f(int i, string &s, vector<string> &v, int res)
    {
        if (i >= s.size())
            return res;
        if (dp[i] != -1)
            return dp[i];
        int tmp = INT_MAX;
        for (int j = i; j < s.size(); j++)
        {
            for (string &a : v)
            {
                if (g(j, s, a))
                    tmp = min(tmp, f(j + a.size(), s, v, res - a.size()));
                if (tmp!=)
            }
        }
        return dp[i];
    }
    int minExtraChar(string s, vector<string> &v)
    {
        memset(dp, -1, sizeof(dp));
        int x = f(0, s, v, s.size());
        return x;
    }
};
int main()
{
    Solution s;
    string str = "abc";
    vector<string> v = {"bc", "x", "ac"};
    cout << s.minExtraChar(str, v);
}
