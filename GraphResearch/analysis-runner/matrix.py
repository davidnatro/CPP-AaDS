from random import SystemRandom

cryptogen = SystemRandom()


class Matrix:

    @staticmethod
    def generate_connected_graph(num_vertices, density):
        max_edges = (num_vertices * (num_vertices - 1)) // 2
        num_edges = int(density * max_edges)

        # Создание пустого графа
        graph = [[0] * num_vertices for _ in range(num_vertices)]

        # Генерация случайных ребер
        edges = cryptogen.choices(range(num_vertices), k=num_edges)
        for i in range(num_edges):
            u = edges[i]
            v = cryptogen.choice([x for x in range(num_vertices) if x != u])
            weight = cryptogen.randint(1, 10)  # Вес ребра (случайное число от 1 до 10)
            graph[u][v] = weight
            graph[v][u] = weight

        return graph

    @staticmethod
    def generate_sparse_connected_graph(num_vertices):
        graph = [[0] * num_vertices for _ in range(num_vertices)]

        # Соединяем все вершины в цикл
        for i in range(num_vertices - 1):
            weight = cryptogen.randint(1, 10)  # Вес ребра (случайное число от 1 до 10)
            graph[i][i + 1] = weight
            graph[i + 1][i] = weight
        weight = cryptogen.randint(1, 10)  # Вес ребра между последней и первой вершинами (цикл)
        graph[num_vertices - 1][0] = weight
        graph[0][num_vertices - 1] = weight

        # Генерация дополнительных ребер
        max_extra_edges = int(
            (num_vertices * (num_vertices - 1)) / 10)  # Примерно 10% от максимального количества ребер
        num_extra_edges = cryptogen.randint(1, max_extra_edges)  # Случайное количество дополнительных ребер

        vertices = list(range(num_vertices))

        for _ in range(num_extra_edges):
            u = cryptogen.randint(0, num_vertices - 1)
            v = cryptogen.randint(0, num_vertices - 1)
            while u == v or graph[u][v] != 0:
                u = cryptogen.randint(0, num_vertices - 1)
                v = cryptogen.randint(0, num_vertices - 1)
            weight = cryptogen.randint(1, 10)  # Вес ребра (случайное число от 1 до 10)
            graph[u][v] = weight
            graph[v][u] = weight

        return graph

    @staticmethod
    def generate_complete_graph(num_vertices):
        graph = [[0] * num_vertices for _ in range(num_vertices)]

        for i in range(num_vertices):
            for j in range(i + 1, num_vertices):
                weight = cryptogen.randint(1, 10)
                graph[i][j] = weight
                graph[j][i] = weight

        return graph

    @staticmethod
    def count_edges(adjacency_matrix):
        num_vertices = len(adjacency_matrix)
        edge_count = 0

        for i in range(num_vertices):
            for j in range(i + 1, num_vertices):
                if adjacency_matrix[i][j] != 0:
                    edge_count += 1

        return edge_count

    @staticmethod
    def print(matrix):
        for row in matrix:
            for element in row:
                print(row, end='\t')
            print()

    @staticmethod
    def to_string(matrix):
        result = str(len(matrix)) + ' ' + str(len(matrix[0]))
        for row in matrix:
            for element in row:
                result += ' ' + str(element)

        return result
