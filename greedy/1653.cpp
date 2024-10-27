#include <bits/stdc++.h>

using namespace std;
int minimumDeletions(string s)
{
    int n = s.size();
    vector<int> a(n);
    vector<int> b(n);
    a[0] = s[0] == 'a';
    b[n - 1] = s[n - 1] == 'b';
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + (s[i] == 'a');                 // cumule mte3 a
        b[n - i - 1] = b[n - i] + (s[n - i - 1] == 'b'); // cumule mte3 b
    }
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int oa = (i + 1) - a[i];
        int ob = (n - i - 1) - b[i + 1];
        res = min(res, oa + ob);
    }
    return res;
}
int main()
{
    string s = "aaaaaaaaaaaaaaba";
    cout << minimumDeletions(s);
}
