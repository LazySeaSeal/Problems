#include <bits/stdc++.h>
using namespace std;

int merge(int a, int b)
{
    return max(a, b);
}
void build(vector<int> &v, vector<int> &tree, int n)
{
    for (int i = 0; i < n; i++)
        tree[i + n] = v[i];
    for (int i = n - 1; i > 0; i--)
        tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
}
void update(vector<int> &tree, int i, int x, int n)
{
    i += n;
    tree[i] = x;
    int new_val;
    while (i > 1)
    {
        i /= 2; // every time we group 2 -> 1 to elements to one elemnt ...
        new_val = merge(tree[i * 2], tree[i * 2 + 1]);
        if (new_val != tree[i]) // if there's a change in the child update the parent
            tree[i] = new_val;
        else // if there's no change in the child there's no need to update the parent :p
            return;
    }
    return;
}

static int minutes(string a)
{
    int h = stoi(a.substr(0, 2));
    int m = stoi(a.substr(3, 2));
    return (h * 60 + m);
}
static bool f(string &a, string &b)
{
    return (minutes(a) > minutes(b));
}
int findMinDifference(vector<string> &v)
{
    sort(v.begin(), v.end(), f);
    int res = INT_MAX;
    for (int i = 1; i < v.size(); i++)
        res = min(res, abs(minutes(v[i - 1]) - minutes(v[i])));
    return min(res, 1440 - abs(minutes(v[v.size() - 1]) - minutes(v[0])));
}

int main()
{
    vector<int> v = {1, 2, 3, 4};
    int n = v.size();
    vector<int> tree(2 * n);
    build(v, tree, n);
    for (int i = 0; i < 2 * n; i++)
        cout << tree[i] << " ";
    update(tree, 2, 10, n);
    cout << endl;
    for (int i = 0; i < 2 * n; i++)
        cout << tree[i] << " ";
}