#include <bits/stdc++.h>
using namespace std;

int bfs(int s, int t, vector<vector<int>>& cap, vector<int>& parent, vector<vector<int>>& adj) {
    fill(parent.begin(), parent.end(), -1); parent[s]=s;
    queue<pair<int,int>> q; q.push({s,INT_MAX});
    while(!q.empty()){
        auto [u,f]=q.front();q.pop();
        for(int v:adj[u])
            if(parent[v]==-1 && cap[u][v]>0){
                parent[v]=u;
                int newf=min(f,cap[u][v]);
                if(v==t)return newf;
                q.push({v,newf});
            }
    }
    return 0;
}

int maxFlow(int n, int s, int t, vector<vector<int>>& cap, vector<vector<int>>& adj){
    int flow, maxF=0; vector<int> p(n);
    while(flow=bfs(s,t,cap,p,adj)){
        maxF+=flow; int cur=t;
        while(cur!=s){int prev=p[cur]; cap[prev][cur]-=flow; cap[cur][prev]+=flow; cur=prev;}
    }
    return maxF;
}

int main(){
    int left=3,right=3;
    int s=0,t=left+right+1,n=t+1;
    vector<vector<int>> cap(n,vector<int>(n)); vector<vector<int>> adj(n);
    auto add=[&](int u,int v,int c){adj[u].push_back(v);adj[v].push_back(u);cap[u][v]=c;};
    for(int i=1;i<=left;i++) add(s,i,1);
    for(int i=1;i<=right;i++) add(left+i,t,1);
    add(1,4,1); add(1,5,1); add(2,5,1); add(3,6,1);
    cout<<"Max Matching = "<<maxFlow(n,s,t,cap,adj);
}
