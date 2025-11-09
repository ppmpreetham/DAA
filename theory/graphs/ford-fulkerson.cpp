#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool dfs(int u, int t, vector<vector<int>>& cap, vector<int>&vis, vector<vector<int>>& adj, int flow){
    if (u == t) return flow; // base case
    vis[u] = 1; // start by marking u to be visited
    for(auto v: adj[u]){ // for each neighbour
        if (!vis[v] && cap[u][v] > 0) // if not visited and has capacity
            if(int pushed = dfs(v, t, cap, vis, adj, min(flow, cap[u][v]))){ // reduced flow
                cap[u][v] -= pushed;
                cap[v][u] += pushed;
                return pushed;
            }
    }
    return 0;
}

int fordFulkerson(int n, int s, int t, vector<vector<int>> &cap, vector<vector<int>> &adj){
    int max_flow = 0;
    while (true){
        vector<int> vis(n);
        int flow = dfs(s, t, cap, vis, adj, INT_MAX);
        if (!flow) break;
        max_flow += flow;
    }
    return max_flow;
}

int main() {
    int n = 4, s = 0, t = 3;
    vector<vector<int>> cap(n, vector<int>(n));
    vector<vector<int>> adj(n);
    auto add = [&](int u, int v, int c){ adj[u].push_back(v); adj[v].push_back(u); cap[u][v]=c; };
    add(0,1,3); add(0,2,2); add(1,2,5); add(1,3,2); add(2,3,3);
    cout << "Max Flow = " << fordFulkerson(n,s,t,cap,adj);
}