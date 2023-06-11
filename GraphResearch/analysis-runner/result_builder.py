from matrix import Matrix
from runner import Runner
from matrix_checker import MatrixChecker


class ResultBuilder:

    @staticmethod
    def result_for_connected_graphs(algorithm):
        from_el = 10
        to_el = 110
        rows_columns = ResultBuilder.get_rows_and_columns_for_excel(from_el, to_el) + 1
        matrix = Matrix.zero_matrix(rows_columns, rows_columns)

        row_column_index = 1
        for vertices in range(from_el, to_el + 1, 50):
            matrix[row_column_index][0] = vertices
            matrix[0][row_column_index] = vertices * (vertices - 1) / 2
            row_column_index += 1

        for i in range(1, rows_columns):
            for j in range(1, rows_columns):
                graph = Matrix.generate_connected_graph(matrix[j][0], matrix[0][j], 0.4)
                if not MatrixChecker.is_connected_graph(graph):
                    print("invalid connected graph")
                    if j > 0:
                        j -= 1
                    continue

                time_result = Runner.run_avg(algorithm, Matrix.to_string(graph))
                matrix[i][j] = time_result
                print(str(i) + 'x' + str(j))

        return matrix

    @staticmethod
    def result_for_complete_graph(algorithm):
        from_el = 10
        to_el = 110
        rows_columns = ResultBuilder.get_rows_and_columns_for_excel(from_el, to_el) + 1
        matrix = Matrix.zero_matrix(rows_columns, rows_columns)

        row_column_index = 1
        for vertices in range(from_el, to_el + 1, 50):
            matrix[row_column_index][0] = vertices
            matrix[0][row_column_index] = vertices * (vertices - 1) / 2
            row_column_index += 1

        for i in range(1, rows_columns):
            for j in range(1, rows_columns):
                graph = Matrix.generate_complete_graph(matrix[j][0], matrix[0][j])
                if not MatrixChecker.is_complete_graph(graph):
                    print("invalid complete graph")
                    if j > 0:
                        j -= 1
                    continue

                time_result = Runner.run_avg(algorithm, Matrix.to_string(graph))
                matrix[i][j] = time_result
                print(str(i) + 'x' + str(j))

        return matrix

    @staticmethod
    def result_for_sparse_connected_graph(algorithm):
        from_el = 10
        to_el = 110
        rows_columns = ResultBuilder.get_rows_and_columns_for_excel(from_el, to_el) + 1
        matrix = Matrix.zero_matrix(rows_columns, rows_columns)

        row_column_index = 1
        for vertices in range(from_el, to_el + 1, 50):
            matrix[row_column_index][0] = vertices
            matrix[0][row_column_index] = vertices * (vertices - 1) / 2
            row_column_index += 1

        for i in range(1, rows_columns):
            for j in range(1, rows_columns):
                graph = Matrix.generate_sparse_connected_graph(matrix[j][0], matrix[0][j])
                if not MatrixChecker.is_sparse_connected_graph(graph):
                    print("invalid sparse connected graph")
                    if j > 0:
                        j -= 1
                    continue

                time_result = Runner.run_avg(algorithm, Matrix.to_string(graph))
                matrix[i][j] = time_result
                print(str(i) + 'x' + str(j))

        return matrix

    @staticmethod
    def get_rows_and_columns_for_excel(from_v, to_v):
        count = 0
        for i in range(from_v, to_v + 1, 50):
            count += 1

        return count
