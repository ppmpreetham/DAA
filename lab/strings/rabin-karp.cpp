#include <bits/stdc++.h>
using namespace std;
#define d 256
#define q 101 // prime modulus

void rabinKarp(string text, string pat) {
    int n = text.size(), m = pat.size();
    int h = 1, p = 0, t = 0;

    for (int i = 0; i < m - 1; i++) h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && text.substr(i, m) == pat)
            cout << "Found at index " << i << "\n";

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
}

int main() {
    rabinKarp("ABABDABACDABABCABAB", "ABABCABAB");
}
