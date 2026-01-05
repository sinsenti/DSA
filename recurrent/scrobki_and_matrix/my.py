def matrix_chain_multiplication(dim):
    s = len(dim) - 1
    dp = [[0] * s for _ in range(s)]

    for length in range(2, s + 1):
        for i in range(s - length + 1):
            j = i + length - 1
            dp[i][j] = int(1e9)
            for k in range(i, j):
                cost = dp[i][k] + dp[k + 1][j] + dim[i] * dim[k + 1] * dim[j + 1]
                if cost < dp[i][j]:
                    dp[i][j] = cost
    return dp[0][s - 1]


with open("input.txt", "r") as fin:
    s = int(fin.readline())
    dim = []
    for i in range(s):
        n, m = map(int, fin.readline().split())
        if i == 0:
            dim.append(n)
        dim.append(m)

result = matrix_chain_multiplication(dim)

with open("output.txt", "w") as fout:
    fout.write(str(result) + "\n")
