import math


def polynomial(x, n):
    return (x**2 - 1) % n

def algorithm(n):
    d = 1
    x = y = 2
    while d == 1:
        x = int(polynomial(x, n))
        y = int(polynomial(polynomial(y, n), n))
        d = math.gcd(int(abs(x - y)), n)

    return d
