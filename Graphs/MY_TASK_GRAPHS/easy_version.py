import sys

sys.setrecursionlimit(300000)

with open("input.txt", "r") as fin, open("output.txt", "w") as fout:
    n = int(fin.readline())

    parent = [i for i in range(n + 1)]
    dist = [0] * (n + 1)

    def find(x):
        if parent[x] != x:
            orig_parent = parent[x]
            parent[x] = find(parent[x])
            dist[x] += dist[orig_parent]
        return parent[x]

    while True:
        line = fin.readline()
        if not line:
            break
        line = line.strip()
        if line == "O":
            break
        cmd = line.split()
        if cmd[0] == "E":
            i = int(cmd[1])
            find(i)
            fout.write(f"{dist[i]}\n")
        elif cmd[0] == "I":
            i, j = int(cmd[1]), int(cmd[2])
            parent[i] = j
            dist[i] = abs(i - j) % 1000
