#include <bits/stdc++.h>

using namespace std;
int f(vector<int> &v, int c)
{
    int d = 0;
    int tmp = 0;
    int res = INT_MAX;
    for (int f = 0; f < v.size(); f++)
    {
        tmp += (v[f] == 1); // tracks how many ones in my window
        if (f - d + 1 == c)
        {
            res = min(res, (f - d + 1) - tmp);
            tmp -= (v[d] == 1);
            d++;
        }
    }
    return res;
}
int minSwaps(vector<int> &v)
{
    int c = 0;
    int n = v.size();
    vector<int> v1(v.size());
    int mid = (n + 1) / 2; // Midpoint calculation to handle both even and odd sizes

    // Single loop to rearrange elements
    for (int i = 0; i < n; ++i)
    {
        if (i < n - mid)
        {
            v1[i] = v[mid + i]; // Second half to the beginning of v1
        }
        else
        {
            v1[i] = v[i - (n - mid)]; // First half to the end of v1
        }
    }
    for (int &i : v)
        c += (i == 1);
    return (min(f(v, c), f(v1, c)));
}

int main()
{
    vector<int> v = {1, 1, 0, 0, 0, 1};
    cout << minSwaps(v) << endl;
}