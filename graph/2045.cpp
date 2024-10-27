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
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));
    // dp[i][j] = Dist to reach j using atmost i edges from src
    for (int i = 0; i <= K + 1; i++)
    {
        dp[i][src] = 0; // Dist to reach src always zero
    }
    for (int i = 1; i <= K + 1; i++)
    {
        for (auto &f : flights)
        {
            // Using indegree
            int u = f[0];
            int v = f[1];
            int w = f[2];

            if (dp[i - 1][u] != INT_MAX)
                dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
        }
    }
    return (dp[K + 1][dst] == INT_MAX) ? -1 : dp[K + 1][dst];
}
int f(int k, int time, int change)
{
    int current = 0;
    int currentChange = 0;
    for (int i = 0; i < k; i++)
    {
        if ((current / change) % 2 == 1)
        {
            currentChange = change - (current % change);
            current += currentChange;
        }
        current += time;
    }
    return current;
}
int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
{
    unordered_map<int, vector<pair<int, int>>> umap;
    for (const auto &edge : edges)
    {
        umap[edge[0] - 1].push_back({edge[1] - 1, time});
        umap[edge[1] - 1].push_back({edge[0] - 1, time});
    }
    unordered_map<int, int> distances = dijkstra(n, 0, umap);
    int k = distances[n - 1] / time; // 9adeh men edge mché
    // tawa yezlm nal9aw best path de facon que yabda mechi k-2 (lapse)
    vector<vector<int>> v1;
    for (int i = 0; i < edges.size(); i++)
    {
        v1.push_back({edges[i][0] - 1, edges[i][1] - 1, time});
        v1.push_back({edges[i][1] - 1, edges[i][0] - 1, time});
    }

    int a = findCheapestPrice(n, v1, 0, n - 1, k + 1);

    if (a == -1) // n'ex
        return (f(k + 2, time, change));
    return (min(f(k + 2, time, change), f(a / time, time, change)));
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> umap;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};

    cout << secondMinimum(5, edges, 3, 5) << endl;
};