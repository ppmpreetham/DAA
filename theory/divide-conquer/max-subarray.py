def dfs(l,r, arr):
    if l>r:
        return float("-inf")
    
    m = (l+r) >> 1
    lss = rss = css = 0
    for i in range(m-1, l-1, -1):
        css += arr[i]
        lss = max(lss, css)
    
    css = 0
    for i in range(m+1, r+1, 1):
        css += arr[i]
        rss = max(rss, css)
    
    return dfs(l, m-1, arr) + dfs(m+1, r, arr) + lss + rss + arr[i]
    