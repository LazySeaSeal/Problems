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
    for (int i = 0; i < n; i++)
    {
        if (res[i] == INT_MAX)
            res[i] = -1;
    }
    return res;
}

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{
    unordered_map<int, vector<pair<int, int>>> umap;
    vector<unordered_map<int, int>> dp(26);
    for (int i = 0; i < original.size(); i++)
        umap[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
    for (int i = 0; i < 26; i++)
        dp[i] = dijkstra(26, i, umap);
    int res = 0;
    for (int i = 0; i < target.size(); i++)
    {
        if (source[i] == target[i])
            continue;
        unordered_map<int, int> distances = dijkstra(26, source[i] - 'a', umap);
        if (dp[source[i] - 'a'][target[i] - 'a'] == -1) // mafemch path yaani ...
            return -1;
        res += dp[source[i] - 'a'][target[i] - 'a'];
    }
    return res;
}

int main()
{
    string source = "abcd";
    string target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    cout << minimumCost(source, target, original, changed, cost) << endl;

    return 0;
}