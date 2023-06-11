from random import SystemRandom
import numpy as np

cryptogen = SystemRandom()


class Matrix:

    @staticmethod
    def generate_connected_graph(num_vertices, num_edges, density):
        if num_edges < num_vertices - 1:
            raise ValueError("Invalid number of edges for a connected graph.")

        max_possible_edges = (num_vertices * (num_vertices - 1)) / 2
        max_allowed_edges = int(density * max_possible_edges)
        num_edges = min(num_edges, max_allowed_edges)

        adjacency_matrix = np.zeros((num_vertices, num_vertices), dtype=int)

        # Создаем список всех вершин
        vertices = list(range(num_vertices))

        # Соединяем первую вершину со всеми остальными
        for vertex in vertices[1:]:
            weight = cryptogen.randint(1, 10)  # Вес ребра (можно изменить по вашему усмотрению)
            adjacency_matrix[0][vertex] = weight
            adjacency_matrix[vertex][0] = weight
            num_edges -= 1

        # Добавляем оставшиеся ребра
        while num_edges > 0:
            # Выбираем случайную вершину
            vertex1 = cryptogen.choice(vertices)
            vertex2 = cryptogen.choice(vertices)

            # Проверяем, что выбранные вершины не совпадают и между ними еще нет ребра
            if vertex1 != vertex2 and adjacency_matrix[vertex1][vertex2] == 0:
                weight = cryptogen.randint(1, 10)  # Вес ребра (можно изменить по вашему усмотрению)
                adjacency_matrix[vertex1][vertex2] = weight
                adjacency_matrix[vertex2][vertex1] = weight
                num_edges -= 1

        return adjacency_matrix

    @staticmethod
    def generate_sparse_connected_graph(num_vertices, num_edges):
        if num_edges < num_vertices - 1 or num_edges > (num_vertices * (num_vertices - 1)) // 2:
            raise ValueError("Invalid number of edges for the given number of vertices")

            # Создаем пустую матрицу смежности
        adjacency_matrix = [[0] * num_vertices for _ in range(num_vertices)]

        # Список всех возможных ребер
        possible_edges = [(i, j) for i in range(num_vertices) for j in range(i + 1, num_vertices)]

        # Выбираем случайную стартовую вершину
        current_vertex = cryptogen.randint(0, num_vertices - 1)

        # Список вершин, которые еще не были посещены
        unvisited_vertices = set(range(num_vertices))
        unvisited_vertices.remove(current_vertex)

        # Добавляем (num_vertices - 1) ребер для обеспечения связности графа
        for _ in range(num_vertices - 1):
            next_vertex = cryptogen.choice(list(unvisited_vertices))
            adjacency_matrix[current_vertex][next_vertex] = 1
            adjacency_matrix[next_vertex][current_vertex] = 1
            unvisited_vertices.remove(next_vertex)
            current_vertex = next_vertex

        # Добавляем оставшиеся ребра до достижения заданного числа ребер
        while len(possible_edges) > 0 and len(unvisited_vertices) > 0 and num_edges > num_vertices - 1:
            next_vertex = cryptogen.choice(list(unvisited_vertices))
            edge = cryptogen.choice(possible_edges)
            adjacency_matrix[edge[0]][edge[1]] = 1
            adjacency_matrix[edge[1]][edge[0]] = 1
            possible_edges.remove(edge)
            unvisited_vertices.remove(next_vertex)
            num_edges -= 1

        return adjacency_matrix

    @staticmethod
    def generate_complete_graph(num_vertices, num_edges):
        # Проверяем, что число вершин и ребер удовлетворяют условиям полного графа
        if num_edges != num_vertices * (num_vertices - 1) / 2:
            raise ValueError("Invalid number of edges for a complete graph")

        # Создаем пустую матрицу смежности
        adjacency_matrix = [[0] * num_vertices for _ in range(num_vertices)]

        # Заполняем матрицу смежности
        for i in range(num_vertices):
            for j in range(i + 1, num_vertices):
                adjacency_matrix[i][j] = 1
                adjacency_matrix[j][i] = 1

        return adjacency_matrix

    @staticmethod
    def zero_matrix(n, m):
        return [[0 for i in range(n)] for j in range(m)]

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
            for _ in row:
                print(row, end='\t')
            print()

    @staticmethod
    def to_string(matrix):
        result = str(len(matrix)) + ' ' + str(len(matrix[0]))
        for row in matrix:
            for element in row:
                result += ' ' + str(element)

        return result
