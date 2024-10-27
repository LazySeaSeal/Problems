#include <bits/stdc++.h>

using namespace std;
int minHeightShelves(vector<vector<int>> &v, int w)
{
    int res = INT_MIN;
    int i = 0;
    int sum = 0;
    int ans = 0;
    int n = v.size();
    while (i < v.size())
    {
        if (sum + v[n - 1 - i][0] <= w)
        {
            sum += v[n - 1 - i][0];
            res = max(res, v[n - 1 - i][1]);
            i++;
        }
        else
        {
            sum = 0;
            ans += res;
            res = INT_MIN;
        }
    }
    return ans + res;
}
int main()
{
}
