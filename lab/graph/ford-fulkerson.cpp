#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &res, int s, int t, vector<int> &parent){
    fill(p.begin(), p.end(), -1); p[s] = s;
    queue<pair<int,int>> q;
    q.push({s,1e9});

    while (!q.empty()) {
        auto [u, flow] = q.front(), q.pop();
        for(int v = 0; v < r.size; v++){
            if (p[v] == -1 && r[u][v] > 0){
                p[v] = u;
                int newf = min(flow, r[u][v])
                if (v==t) return newf; // reached sink
                q.push({v, newf});
            }
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> cap={{0,16,13,0,0,0},
                             {0,0,10,12,0,0},
                             {0,4,0,0,14,0},
                             {0,0,9,0,0,20},
                             {0,0,0,7,0,4},
                             {0,0,0,0,0,0}};
                             
    int n=6,s=0,t=5,flow=0,newf;
    vector<int> p(n);
    while(newf=bfs(cap,s,t,p)) {
        flow += newf;
        int cur = t;
        while(cur!=s){
            int prev = p[cur];
            cap[prev][cur]-=newf;
            cap[cur][prev]+=newf;
            cur=prev;
        }
    }
    cout<<flow;
    return 0;
}