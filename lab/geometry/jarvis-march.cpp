#include <bits/stdc++.h>
using namespace std;

struct Point{int x,y;};

int orientation(Point a,Point b,Point c){
    int v=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
    if(v==0)return 0;
    return (v>0)?1:2;
}

vector<Point> jarvis(vector<Point>& pts){
    int n=pts.size(), l=0;
    for(int i=1;i<n;i++) if(pts[i].x<pts[l].x) l=i;
    vector<Point> hull; int p=l,q;
    do{
        hull.push_back(pts[p]); q=(p+1)%n;
        for(int i=0;i<n;i++) if(orientation(pts[p],pts[i],pts[q])==2) q=i;
        p=q;
    }while(p!=l);
    return hull;
}

int main(){
    vector<Point> pts={{0,3},{1,1},{2,2},{4,4},{0,0},{1,2},{3,1},{3,3}};
    auto hull=jarvis(pts);
    for(auto&p:hull) cout<<"("<<p.x<<","<<p.y<<") ";
}