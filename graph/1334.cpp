#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> dijkstra(int n, int s, unordered_map<int, vector<pair<int, int>>> &umap)
{
    unordered_map<int, int> res;
    unordered_map<int, int> visited; // 0 not visited 1 visited
    for (int i = 0; i < n; i++)
    {
        res[i] = INT_MAX;
        visited[i] = 0;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    minHeap.push({0, s});
    while (!minHeap.empty())
    {
        auto [dist, node] = minHeap.top(); // dist is the distance from source to node cumule
        minHeap.pop();
        if (visited[node] == 1)
            continue;
        visited[node] = 1;
        res[node] = dist;
        for (const auto &neighbour : umap[node])
        {
            int a = neighbour.first;  // a is the neighbour node
            int b = neighbour.second; // b is the distance between node and neighbour
            if (visited[a] == 0)
            {
                if (res[a] > res[node] + b)
                {
                    res[a] = res[node] + b;
                    minHeap.push({res[a], a});
                }
            }
        }
    }
    return res;
}
bool static tmp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
        return a[1] > b[1];
    return a[0] < b[0];
};
int findTheCity(int n, vector<vector<int>> &v, int distanceThreshold)
{
    vector<vector<int>> res;
    unordered_map<int, vector<pair<int, int>>> umap;
    for (const auto &edge : v)
    {
        umap[edge[0]].push_back({edge[1], edge[2]});
        umap[edge[1]].push_back({edge[0], edge[2]});
    }
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> distances = dijkstra(n, i, umap);
        int c = 0;
        for (auto y : distances)
        {
            if ((int)y.second <= distanceThreshold)
                c++;
        }
        c--;
        res.push_back({c, i});
    }
    sort(res.begin(), res.end(), tmp);
    return res[0][1];
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> umap;
    vector<vector<int>> v = {{0, 3, 7}, {2, 4, 1}, {0, 1, 5}, {2, 3, 10}, {1, 3, 6}, {1, 2, 1}};
    cout << findTheCity(6, v, 417);
    return 0;
};