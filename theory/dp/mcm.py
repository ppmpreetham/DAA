import sys

def matrix_chain(dims):
    n = len(dims)
    m = [[0]*(n+1) for _ in range(n+1)]

    for l in range(2, n+1):
        for i in range(1, n-l+2):
            j = i+l-1
            m[i][j] = sys.maxsize
            for k in range(i,j):
                cost = m[i][k] + m[k+1][j] + dims[i-1]*dims[j]*dims[k]
                m[i][j] = min(m[i][j], cost)

    return m[1][n]