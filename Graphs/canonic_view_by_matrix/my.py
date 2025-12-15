with open("input.txt", "r") as f, open("output.txt", "w") as out:
    n = int(f.readline().strip())
    parent = [0 for _ in range(n)]
    for i in range(n):
        line = f.readline().strip().split()
        lil = [int(x) for x in line]
        for j in range(n):
            if lil[j] == 1:
                parent[j] = i + 1
    out.write(" ".join(str(x) for x in parent))
