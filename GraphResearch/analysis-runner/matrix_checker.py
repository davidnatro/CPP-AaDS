class MatrixChecker:
    @staticmethod
    def is_sparse_connected_graph(adjacency_matrix):
        num_vertices = len(adjacency_matrix)

        # Проверяем, является ли граф связным
        visited = [False] * num_vertices
        stack = [0]  # Используем стек для обхода в глубину
        visited[0] = True

        while stack:
            current_vertex = stack.pop()

            # Проходим по соседним вершинам
            for neighbor in range(num_vertices):
                if adjacency_matrix[current_vertex][neighbor] != 0 and not visited[neighbor]:
                    stack.append(neighbor)
                    visited[neighbor] = True

        if False in visited:
            return False

        # Проверяем, является ли граф разреженным
        num_edges = 0
        for i in range(num_vertices):
            for j in range(i + 1, num_vertices):
                if adjacency_matrix[i][j] != 0:
                    num_edges += 1

        max_edges = int(num_vertices * (num_vertices - 1) / 2)  # Максимальное количество ребер для полного графа

        # Если количество ребер меньше половины от максимального, считаем граф разреженным
        if num_edges < max_edges / 2:
            return True
        else:
            return False

    @staticmethod
    def is_connected_graph(adjacency_matrix):
        num_vertices = len(adjacency_matrix)

        # Проверяем, является ли граф связным
        visited = [False] * num_vertices
        stack = [0]  # Используем стек для обхода в глубину
        visited[0] = True

        while stack:
            current_vertex = stack.pop()

            # Проходим по соседним вершинам
            for neighbor in range(num_vertices):
                if adjacency_matrix[current_vertex][neighbor] != 0 and not visited[neighbor]:
                    stack.append(neighbor)
                    visited[neighbor] = True

        if False in visited:
            return False
        else:
            return True

    @staticmethod
    def is_complete_graph(adjacency_matrix):
        num_vertices = len(adjacency_matrix)

        # Проверяем, что все вершины, кроме главной диагонали, имеют связи
        for i in range(num_vertices):
            for j in range(num_vertices):
                if i != j and adjacency_matrix[i][j] == 0:
                    return False

        return True
