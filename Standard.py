def algorithm(N):
    sqrt = int(N**0.5) + 1
    for i in range(3, sqrt, 2):
        if N % i == 0:
            return i

    return N
