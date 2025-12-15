import heapq


with open("input.txt", "r") as fin:
    data = fin.read().strip().split()

it = iter(data)
n = int(next(it))
m = int(next(it))

g = [[] for _ in range(n + 1)]
for _ in range(m):
    u = int(next(it))
    v = int(next(it))
    w = int(next(it))
    g[u].append((v, w))
    g[v].append((u, w))

INF = 10**9
dist = [INF] * (n + 1)
dist[1] = 0
pq = [(0, 1)]

while pq:
    d, v = heapq.heappop(pq)
    if d != dist[v]:
        continue
    if v == n:
        break
    for to, w in g[v]:
        nd = d + w
        if nd < dist[to]:
            dist[to] = nd
            heapq.heappush(pq, (nd, to))

with open("output.txt", "w") as fout:
    result = str(dist[n])

    fout.write(result)
