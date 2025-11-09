#include <bits/stdc++.h>
using namespace std;

int pushRelabel(vector<vector<int>>& cap, int s, int t) {
    int n = cap.size();
    vector<int> height(n), excess(n);
    vector<vector<int>> flow(n, vector<int>(n));
    auto push = [&](int u, int v) {
        int send = min(excess[u], cap[u][v] - flow[u][v]);
        if (send > 0 && height[u] == height[v] + 1) {
            flow[u][v] += send;
            flow[v][u] -= send;
            excess[u] -= send;
            excess[v] += send;
        }
    };
    height[s] = n; excess[s] = INT_MAX;
    for (int v=0; v<n; ++v) push(s,v);
    queue<int> q;
    for (int i=0; i<n; ++i) if (i!=s && i!=t && excess[i]>0) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v=0; v<n; ++v) push(u,v);
        if (excess[u] > 0) { height[u]++; q.push(u); }
    }
    int maxFlow = 0;
    for (int i=0;i<n;i++) maxFlow += flow[s][i];
    return maxFlow;
}

int main() {
    vector<vector<int>> cap = {
        {0,3,2,0},
        {0,0,5,2},
        {0,0,0,3},
        {0,0,0,0}
    };
    cout << "Max Flow = " << pushRelabel(cap,0,3);
}
