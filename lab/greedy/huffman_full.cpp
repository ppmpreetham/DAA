#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

// Node structure for Huffman tree
struct Node {
    char c;
    int f;
    Node *l, *r;

    Node(char c, int f) : c(c), f(f), l(NULL), r(NULL) {}
    Node(int f) : c('#'), f(f), l(NULL), r(NULL) {}
};

// Comparison function for priority queue (min-heap)
struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->f > b->f;
    }
};

// DFS to print the Huffman code (encoding)
void dfs(Node* r, string s = "", unordered_map<char, string>& codes) {
    if (!r) return;
    if (r->c != '#') {
        codes[r->c] = s;  // Store the Huffman code for the character
    }
    dfs(r->l, s + "0", codes);
    dfs(r->r, s + "1", codes);
}

// Decoding function
string decode(Node* root, const string& encodedStr) {
    string decodedStr = "";
    Node* current = root;  // Start from the root of the tree
    
    // Iterate through each character in the encoded string
    for (char bit : encodedStr) {
        // Traverse the tree according to the bit ('0' = left, '1' = right)
        if (bit == '0') {
            current = current->l;
        } else {
            current = current->r;
        }
        
        // If a leaf node is reached, add the character to the decoded string
        if (current->c != '#') {
            decodedStr += current->c;
            current = root;  // Go back to the root for the next character
        }
    }
    return decodedStr;
}

// Function to encode a string using the Huffman codes
string encode(const string& input, const unordered_map<char, string>& codes) {
    string encodedStr = "";
    for (char c : input) {
        encodedStr += codes.at(c);  // Append the corresponding Huffman code for each character
    }
    return encodedStr;
}

int main() {
    // Frequency table for characters
    vector<pair<char, int>> f = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    
    // Min-heap priority queue to build the Huffman tree
    priority_queue<Node*, vector<Node*>, cmp> pq;
    
    // Create leaf nodes for each character and add them to the priority queue
    for (auto& [c, fr] : f) {
        pq.push(new Node(c, fr));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();  // Extract two nodes with the lowest frequencies
        Node* r = pq.top(); pq.pop();
        
        // Create a new internal node with the sum of frequencies
        Node* p = new Node(l->f + r->f);
        p->l = l;
        p->r = r;

        // Push the internal node back into the priority queue
        pq.push(p);
    }

    // The root of the tree is the last remaining node in the priority queue
    Node* root = pq.top();

    // Store Huffman codes for each character in a map
    unordered_map<char, string> codes;
    dfs(root, "", codes);

    // Display the generated Huffman codes
    cout << "Huffman Encoding:" << endl;
    for (const auto& [c, code] : codes) {
        cout << c << ": " << code << endl;
    }

    // Example string to encode
    string input = "abcdef";
    
    // Encode the input string
    string encodedStr = encode(input, codes);
    cout << "\nEncoded string: " << encodedStr << endl;

    // Decode the encoded string using the Huffman tree
    string decodedStr = decode(root, encodedStr);
    cout << "\nDecoded string: " << decodedStr << endl;

    return 0;
}
