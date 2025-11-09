#include <bits/stdc++.h>
using namespace std;
struct Point{int x,y;};
Point p0;
int dist(Point a,Point b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int orientation(Point a,Point b,Point c){
    int v=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
    if(v==0)return 0;
    return (v>0)?1:2;
}
bool cmp(Point a,Point b){
    int o=orientation(p0,a,b);
    if(o==0)return dist(p0,a)<dist(p0,b);
    return (o==2);
}
vector<Point> convexHull(vector<Point>& pts){
    int n=pts.size(), ymin=0;
    for(int i=1;i<n;i++)
        if(pts[i].y<pts[ymin].y||(pts[i].y==pts[ymin].y&&pts[i].x<pts[ymin].x)) ymin=i;
    swap(pts[0],pts[ymin]); p0=pts[0];
    sort(pts.begin()+1,pts.end(),cmp);
    vector<Point> st={pts[0],pts[1],pts[2]};
    for(int i=3;i<n;i++){
        while(st.size()>1 && orientation(st[st.size()-2],st.back(),pts[i])!=2)
            st.pop_back();
        st.push_back(pts[i]);
    }
    return st;
}
int main(){
    vector<Point> pts={{0,3},{1,1},{2,2},{4,4},{0,0},{1,2},{3,1},{3,3}};
    auto hull=convexHull(pts);
    for(auto&p:hull) cout<<"("<<p.x<<","<<p.y<<") ";
}
