with open("in.txt") as f:
    text = f.readlines()


x, y, z, A, B = [el.strip() for el in text]
x, y, z = int(x), int(y), int(z)
n = len(A)
m = len(B)

dp = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    dp[i][0] = i * x

for j in range(1, m + 1):
    dp[0][j] = j * x


for i in range(1, n + 1):
    for j in range(1, m + 1):
        if A[i - 1] == B[j - 1]:
            dp[i][j] = dp[i - 1][j - 1]
        else:
            dp[i][j] = min(dp[i - 1][j] + x, dp[i][j - 1] + y, dp[i - 1][j - 1] + z)

with open("out.txt", "w") as f:
    f.write(str(dp[n][m]))
