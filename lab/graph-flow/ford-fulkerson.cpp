#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int t, vector<vector<int>>& cap, vector<int>& vis, vector<vector<int>>& adj, int flow) {
    if (u == t) return flow;
    vis[u] = 1;
    for (int v : adj[u])
        if (!vis[v] && cap[u][v] > 0)
            if (int pushed = dfs(v, t, cap, vis, adj, min(flow, cap[u][v]))) {
                cap[u][v] -= pushed;
                cap[v][u] += pushed;
                return pushed;
            }
    return 0;
}

int fordFulkerson(int n, int s, int t, vector<vector<int>>& cap, vector<vector<int>>& adj) {
    int maxFlow = 0;
    while (true) {
        vector<int> vis(n);
        int flow = dfs(s, t, cap, vis, adj, INT_MAX);
        if (!flow) break;
        maxFlow += flow;
    }
    return maxFlow;
}

int main() {
    int n = 4, s = 0, t = 3;
    vector<vector<int>> cap(n, vector<int>(n));
    vector<vector<int>> adj(n);
    auto add = [&](int u, int v, int c){ adj[u].push_back(v); adj[v].push_back(u); cap[u][v]=c; };
    add(0,1,3); add(0,2,2); add(1,2,5); add(1,3,2); add(2,3,3);
    cout << "Max Flow = " << fordFulkerson(n,s,t,cap,adj);
}
