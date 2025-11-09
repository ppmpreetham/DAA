#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string pat) {
    int m = pat.size(), plen = 0;
    vector<int> lps(m);
    for (int i = 1; i < m; ) {
        if (pat[i] == pat[plen]) lps[i++] = ++plen;
        else if (plen) plen = lps[plen - 1];
        else lps[i++] = 0;
    }
    return lps;
}

void KMPSearch(string text, string pat) {
    auto lps = buildLPS(pat);
    int i = 0, j = 0, n = text.size(), m = pat.size();
    while (i < n) {
        if (text[i] == pat[j]) i++, j++;
        if (j == m) cout << "Found at index " << i - j << "\n", j = lps[j - 1];
        else if (i < n && text[i] != pat[j])
            j ? j = lps[j - 1] : i++;
    }
}

int main() {
    KMPSearch("ABABDABACDABABCABAB", "ABABCABAB");
}
