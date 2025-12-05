def dfs(l, r, arr):
    if l == r:
        return arr[l]
    if l > r:
        return float("-inf")

    m = (l + r) >> 1

    # compute left-suffix sum
    css = 0
    lss = rss = float("-inf")
    for i in range(m - 1, l - 1, -1):
        css += arr[i]
        lss = max(lss, css)

    # compute right-prefix sum
    css = 0
    for i in range(m + 1, r + 1):
        css += arr[i]
        rss = max(rss, css)

    cross = arr[m] + max(lss, 0) + max(rss, 0)

    return max(dfs(l, m - 1, arr), cross, dfs(m + 1, r, arr))
