def multiply(x,y):
    if min(x,y) < 10:
        return x*y

    m = max(len(str(x)), len(str(y))) // 2

    a, b = divmod(x, 10**m)
    c, d = divmod(y, 10**m)

    z0 = multiply(b,d)
    z1 = multiply(a,c)
    z2 = multiply((a+c),(b+d))

    return z1*10**(2*m) + (z2-z0-z1)*10**m + z0