from collections import deque


def bfs(matrix):
    n = len(matrix)
    labels = [0] * (n + 1)
    visited = [False] * (n + 1)
    next_label = 1

    def bfs_from(start_vertex, current_label):
        queue = deque([start_vertex])
        visited[start_vertex] = True
        labels[start_vertex] = current_label
        current_label += 1

        while queue:
            current = queue.popleft()

            neighbors = []
            for neighbor in range(1, n + 1):
                if matrix[current - 1][neighbor - 1] == 1 and not visited[neighbor]:
                    neighbors.append(neighbor)

            neighbors.sort()

            for neighbor in neighbors:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    labels[neighbor] = current_label
                    current_label += 1
                    queue.append(neighbor)

        return current_label

    for vertex in range(1, n + 1):
        if not visited[vertex]:
            next_label = bfs_from(vertex, next_label)

    return labels[1:]


with open("input.txt", "r") as f, open("output.txt", "w") as out:
    n = int(f.readline().strip())
    matrix = [list(map(int, f.readline().split())) for _ in range(n)]
    result = bfs(matrix)
    output = " ".join(str(x) for x in result)
    out.write(output)
