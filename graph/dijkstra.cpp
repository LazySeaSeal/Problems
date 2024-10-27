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

int main()
{
    // the umap should be [node] = [(neighbour, distance),(neighbour, distance),...]
    return 0;
}