#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge(int u,v,w);

int main(){
    int V = 5, E = 0;
    vector<Edge> edges={{0,1,-1},{0,2,4},{1,2,3},{1,3,2},
                        {1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    vector<int> dist(V,1e9);
    dist[0]=0;
    
    for(int i = 0; i<V-1; i++){
        for (Edge &e: edges){
            if (dist[e.v] != 1e9)
            dist[e.v] = min(dist[e.v], dist[e.u] + e.w);
        }
    }
    
    bool negCycle = false;
    for (Edge &e: edges){
        if (dist[e.v] != 1e9)
            if (dist[e.v] > dist[e.u] + e.w)
                cout << "NegCycle Detected" << endl;
    }

    for(int i = 0; i < V; i++) cout << "Vertex " << i << ": " << dist[i] << "\n";

    return 0;
}