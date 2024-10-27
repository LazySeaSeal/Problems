#include <bits/stdc++.h>
using namespace std;
int g(int n, int x, int y, vector<vector<int>> &v)
{

    if (v.size() - x < 0 || v.size() - y < 0)
        return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == 0)
                return 0;
    return 1;
}

int f(int n, vector<vector<int>> &v)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < v.size(); j++)
            res += g(n, i, j, v);
    return res;
}
int countSquares(vector<vector<int>> &v)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
        res += f(i + 1, v);
    return res;
}

int main()
{
    vector<vector<int>> v = {{0, 1, 1, 1},
                             {1, 1, 1, 1},
                             {0, 1, 1, 1}};
    cout << countSquares(v);

    return 0;
}
