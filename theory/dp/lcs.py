s1 = "abcd"
s2 = "gbcs"

m = len(s1)
n = len(s2)

def lcs_naive(s1, s2):
    def recurse(i, j):
        if min(i, j) < 0:
            return 0
        if s1[i] == s2[j]:
            return recurse(i-1,j-1)
        else:
            return max(recurse(i-1,j), recurse(i, j-1))
    return recurse(m-1,n-1)

def lcs_memo(s1,s2):
    memo = {}
    def recurse(i, j):
        if min(i, j) < 0:
            return 0

        if (i,j) in memo:
            return memo[(i,j)]

        if s1[i] == s2[j]:
            memo[(i,j)] = recurse(i-1,j-1)
        else:
            memo[(j,j)] = max(recurse(i-1,j), recurse(i, j-1))
        return memo[(i,j)]
    return recurse(m-1,n-1)

def lcs_tabulate(s1,s2):
    dp = [[0]*(m+1) for _ in range(n+1)]

    for i in range(1,n+1):
        for j in range(1,m+1):
            if s1[i] == s2[j]:
                dp[i][j] = 1 + dp[i-1,j-1]
            else:
                dp[i,j] = max(dp[i-1][j], dp[i][j-1])

    return dp[n][m]
