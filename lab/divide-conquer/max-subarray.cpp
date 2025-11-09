#include <bits/stdc++.h>
using namespace std;

long long dfs(int l, int r, const vector<long long>& arr) {
    if (l > r) return LLONG_MIN; // base case

    int m = (l + r) >> 1;

    // compute max sum on left side crossing mid
    long long lss = 0, css = 0;
    for (int i = m - 1; i >= l; --i) {
        css += arr[i];
        lss = max(lss, css);
    }

    // compute max sum on right side crossing mid
    long long rss = 0;
    css = 0;
    for (int i = m + 1; i <= r; ++i) {
        css += arr[i];
        rss = max(rss, css);
    }

    long long cross = lss + arr[m] + rss;

    long long left = dfs(l, m - 1, arr);
    long long right = dfs(m + 1, r, arr);

    return max({left, right, cross});
}

int main() {
    vector<long long> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum = " << dfs(0, arr.size() - 1, arr);
    return 0;
}
