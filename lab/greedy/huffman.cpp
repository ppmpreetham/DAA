#include <vector>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct Node{
    char c; int f;
    Node *l, *r;
    Node(char c, int f): c(c), f(f), l(NULL), r(NULL); // leaf node will have c as #
}

struct cmp{bool operator()(Node* a, Node* b){return a.f > b.f;}};

// encode
void dfs(Node* r, string s = ""){
    if(!r) return;
    if(r.c!='#') cout << r.c << s << endl;
    dfs(r.l, s+"0");
    dfs(r.r, s+"1");
}

int main(){
    vector<pair<char, int>> f = {{'a', 5}, {'b', 0}, {'c', 1}, {'d', 4}};
    priority_queue<Node*, vector<Node*>, cmp> pq;
    for(auto &[c,fr] : f) pq.push(new Node(c,fr));
    while(pq.size() > 1){
        Node* l = pq.top(); pq.pop(); Node* r = pq.top(); pq.pop();
        Node* p = new Node('#', l.f + r.f);
        p.l = l; p.r = r;
        pq.push(p);
    }
    return 0;
}