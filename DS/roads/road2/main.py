def main():
    import sys

    sys.setrecursionlimit(10**7)
    input = sys.stdin.readline

    n, m, q = map(int, input().split())
    edges = []
    for _ in range(m):
        u, v = map(int, input().split())
        edges.append((u - 1, v - 1))
    queries = []
    removed_set = set()
    for _ in range(q):
        x = int(input())
        queries.append(x - 1)
        removed_set.add(x - 1)

    # Сначала добавим все рёбра, которые НЕ будут удалены
    dsu_parent = list(range(n))
    dsu_rank = [1] * n
    component_count = n

    def find(u):
        while u != dsu_parent[u]:
            dsu_parent[u] = dsu_parent[dsu_parent[u]]
            u = dsu_parent[u]
        return u

    def union(u, v):
        nonlocal component_count
        u = find(u)
        v = find(v)
        if u == v:
            return
        # Сливаем по рангам
        if dsu_rank[u] < dsu_rank[v]:
            dsu_parent[u] = v
            dsu_rank[v] += dsu_rank[u]
        else:
            dsu_parent[v] = u
            dsu_rank[u] += dsu_rank[v]
        component_count -= 1

    # Построим начальный граф (без удалённых дорог)
    for i in range(m):
        if i not in removed_set:
            u, v = edges[i]
            union(u, v)

    # Теперь будем возвращать дороги в обратном порядке и сохранять результат
    res = []
    for x in reversed(queries):
        # После каждого восстановления проверим связность
        if component_count == 1:
            res.append("1")
        else:
            res.append("0")
        # Восстановим дорогу
        u, v = edges[x]
        union(u, v)
    # Ответ (нужно обратить res)
    print("".join(reversed(res)))


if __name__ == "__main__":
    main()
