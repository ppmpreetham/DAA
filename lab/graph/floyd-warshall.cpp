#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    const int INF = 1e9;

    vector<vector<int>> dist={{0,5,INF,10},
                              {INF,0,3,INF},
                              {INF,INF,0,1},
                              {INF,INF,INF,0}};

    int n = dist.size();
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for(auto &r: dist)
        for(auto d: r)
            if (d==INF) {
                cout << "INF" << endl;
            } else {
                cout << d << endl;
            }
    return 0;
}
