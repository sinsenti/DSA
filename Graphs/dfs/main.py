def foo(matrix):
    n = len(matrix)
    labels = [0] * (n + 1)
    visited = [False] * (n + 1)

    def dfs(current_vertex, current_label):
        visited[current_vertex] = True
        labels[current_vertex] = current_label[0]
        current_label[0] += 1

        neighbors = []
        for neighbor in range(1, n + 1):
            if matrix[current_vertex - 1][neighbor - 1] == 1 and not visited[neighbor]:
                neighbors.append(neighbor)

        neighbors.sort()

        for neighbor in neighbors:
            if not visited[neighbor]:
                dfs(neighbor, current_label)

    label_counter = [1]
    for vertex in range(1, n + 1):
        if not visited[vertex]:
            dfs(vertex, label_counter)

    return labels[1:]


with open("input.txt", "r") as f, open("output.txt", "w") as out:
    n = int(f.readline().strip())
    matrix = [list(map(int, f.readline().split())) for _ in range(n)]
    result = foo(matrix)
    output = " ".join(str(x) for x in result)
    out.write(output)
