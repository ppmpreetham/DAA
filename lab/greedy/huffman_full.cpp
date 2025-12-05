#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    char c;
    int f;
    Node *l, *r;

    Node(char c, int f) : c(c), f(f), l(NULL), r(NULL) {}
    Node(int f) : c('#'), f(f), l(NULL), r(NULL) {}
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};


void dfs(Node* n, string s = "", unordered_map<char, string>& codes) {
    if (!n) return;
    if (n->c != '#') {
        codes[n->c] = s;
    }
    dfs(n->l, s + "0", codes);
    dfs(n->r, s + "1", codes);
}


string decode(Node* root, const string& encodedStr) {
    string decodedStr = "";
    Node* current = root;

    for (char bit : encodedStr) {
        if (bit == '0') {
            current = current->l;
        } else {
            current = current->r;
        }

        if (current->c != '#') {
            decodedStr += current->c;
            current = root;
        }
    }
    return decodedStr;
}


string encode(const string& input, const unordered_map<char, string>& codes) {
    string encodedStr = "";
    for (char c : input) {
        encodedStr += codes.at(c);
    }
    return encodedStr;
}

int main() {
    vector<pair<char, int>> f = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    priority_queue<Node*, vector<Node*>, cmp> pq;

    for (auto& [c, fr] : f) {
        pq.push(new Node(c, fr));
    }

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        Node* p = new Node(l->f + r->f);
        p->l = l;
        p->r = r;
        pq.push(p);
    }

    Node* root = pq.top();
    unordered_map<char, string> codes;
    dfs(root, "", codes);

    cout << "Huffman Encoding:" << endl;
    for (const auto& [c, code] : codes) {
        cout << c << ": " << code << endl;
    }

    string input = "abcdef";
    string encodedStr = encode(input, codes);
    cout << "\nEncoded string: " << encodedStr << endl;

    string decodedStr = decode(root, encodedStr);
    cout << "\nDecoded string: " << decodedStr << endl;

    return 0;
}
