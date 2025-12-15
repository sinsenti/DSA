with open("input.txt", "r") as f1, open("output.txt", "w") as f2:
    n, m = map(int, f1.readline().split())
    a = [[] for _ in range(n + 1)]  # +1 if vertices start from 1

    for _ in range(m):
        u, v = map(int, f1.readline().split())
        a[u].append(v)
        a[v].append(u)

    for i in range(1, n + 1):
        a[i].sort()
        lis = " ".join(str(x) for x in a[i])
        if a[i]:
            f2.write(f"{len(a[i])} {lis}\n")
        else:
            f2.write("0\n")
