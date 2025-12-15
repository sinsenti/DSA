with open("input.txt", "r") as f1, open("output.txt", "w") as f2:
    n = int(f1.readline().strip())
    vec = [0] * (n + 1)
    for _ in range(n - 1):
        u, v = map(int, f1.readline().split())
        vec[v] = u

    f2.write(" ".join(str(vec[i]) for i in range(1, n + 1)))
