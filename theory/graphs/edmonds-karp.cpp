#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int bfs(int s, int t, vector<vector<int>>& cap, vector<int>& parent, vector<vector<int>>& adj) {
    fill(parent.begin(), parent.end(), -1); // unvisited
    parent[s] = s; // start
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});
    while (!q.empty()) {
        auto [u, flow] = q.front(); q.pop();
        for( int v: u ){
            if (parent[v] == -1 && cap[u][v] > 0){
                parent[v] = u;
                int new_flow = min(flow, cap[u][v]);
                if (v == t) return new_flow;
                q.push({v, new_flow});
            }
        }
    }
}

int edmondKarp(int n, int s, int t, vector<vector<int>>&cap, vector<vector<int>>&adj) {
    int maxFlow = 0, flot;
    vector<int> parent(n);
    while(flow = bfs(s,t,cap, parent, adj)) {
        maxFlow += flow;
        while (cur != s){
            int prev = parent[cur];
            cap[prev][cur] -= flow;
            cap[cur][pre] += flow;
        }
    }
    return maxFlow;
}

int main() {
    int n = 4, s = 0, t = 3;
    vector<vector<int>> cap(n, vector<int>(n));
    vector<vector<int>> adj(n);
    auto add = [&](int u,int v,int c){
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] = c;
    };
    add(0,1,3); add(0,2,2); add(1,2,5); add(1,3,2); add(2,3,3);
    cout << "Max Flow = " << edmondKarp(n,s,t,cap,adj);
}