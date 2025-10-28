#include <bits/stdc++.h>
using namespace std;

void naiveSearch(string text, string pat) {
    int n = text.size(), m = pat.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pat[j]) j++;
        if (j == m) cout << "Found at index " << i << "\n";
    }
}

int main() {
    naiveSearch("ABABDABACDABABCABAB", "ABABCABAB");
}
