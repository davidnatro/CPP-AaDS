import pandas as pd

from result_builder import ResultBuilder

c = 21
i = 10


class AlgoRunner:

    @staticmethod
    def run_algo(path):
        connected_graph_result = ResultBuilder.result_for_connected_graphs(path)
        complete_graph_result = ResultBuilder.result_for_complete_graph(path)
        sparse_connected_graph_result = ResultBuilder.result_for_sparse_connected_graph(path)

        return connected_graph_result, complete_graph_result, sparse_connected_graph_result

    @staticmethod
    def bellman_ford():
        path = "../bellman-ford/cmake-build-debug/bellman_ford"
        xlsx_path = "../bellman-ford.xlsx"
        result = AlgoRunner.run_algo(path)

        cols = c
        index = i

        head = [""] * cols
        head[index] = "bellman ford"

        v = [""] * cols
        v[index] = "вершины"

        e = [""] * cols
        e[index] = "ребра"

        connected = result[0]
        complete = result[1]
        sparse_connected = result[2]

        matrix_connected_graph = pd.DataFrame([head, v, connected[2], connected[0], e, connected[3], connected[1]])
        matrix_complete_graph = pd.DataFrame([head, v, complete[2], complete[0], e, complete[3], complete[1]])
        matrix_sparse_connected_graph = pd.DataFrame([head, v, sparse_connected[2], sparse_connected[0], e,
                                                      sparse_connected[3], sparse_connected[1]])

        excel_writer = pd.ExcelWriter(xlsx_path, engine='openpyxl')
        matrix_connected_graph.to_excel(excel_writer, sheet_name='connected-graph', index=False)
        matrix_complete_graph.to_excel(excel_writer, sheet_name='complete-graph', index=False)
        matrix_sparse_connected_graph.to_excel(excel_writer, sheet_name='sparse-connected-graph', index=False)

        excel_writer.close()

    @staticmethod
    def dijkstra():
        path = "../dijkstra/cmake-build-debug/dijkstra"
        xlsx_path = "../dijkstra.xlsx"

        result = AlgoRunner.run_algo(path)

        cols = c
        index = i

        head = [""] * cols
        head[index] = "dijkstra"

        v = [""] * cols
        v[index] = "вершины"

        e = [""] * cols
        e[index] = "ребра"

        connected = result[0]
        complete = result[1]
        sparse_connected = result[2]

        matrix_connected_graph = pd.DataFrame([head, v, connected[2], connected[0], e, connected[3], connected[1]])
        matrix_complete_graph = pd.DataFrame([head, v, complete[2], complete[0], e, complete[3], complete[1]])
        matrix_sparse_connected_graph = pd.DataFrame([head, v, sparse_connected[2], sparse_connected[0], e,
                                                      sparse_connected[3], sparse_connected[1]])

        excel_writer = pd.ExcelWriter(xlsx_path, engine='openpyxl')
        matrix_connected_graph.to_excel(excel_writer, sheet_name='connected-graph', index=False)
        matrix_complete_graph.to_excel(excel_writer, sheet_name='complete-graph', index=False)
        matrix_sparse_connected_graph.to_excel(excel_writer, sheet_name='sparse-connected-graph', index=False)

        excel_writer.close()

    @staticmethod
    def floyd_warshall():
        path = "../floyd-warshall/cmake-build-debug/floyd_warshall"
        xlsx_path = "../floyd-warshall.xlsx"

        result = AlgoRunner.run_algo(path)

        cols = c
        index = i

        head = [""] * cols
        head[index] = "floyd warshall"

        v = [""] * cols
        v[index] = "вершины"

        e = [""] * cols
        e[index] = "ребра"

        connected = result[0]
        complete = result[1]
        sparse_connected = result[2]

        matrix_connected_graph = pd.DataFrame([head, v, connected[2], connected[0], e, connected[3], connected[1]])
        matrix_complete_graph = pd.DataFrame([head, v, complete[2], complete[0], e, complete[3], complete[1]])
        matrix_sparse_connected_graph = pd.DataFrame([head, v, sparse_connected[2], sparse_connected[0], e,
                                                      sparse_connected[3], sparse_connected[1]])

        excel_writer = pd.ExcelWriter(xlsx_path, engine='openpyxl')
        matrix_connected_graph.to_excel(excel_writer, sheet_name='connected-graph', index=False)
        matrix_complete_graph.to_excel(excel_writer, sheet_name='complete-graph', index=False)
        matrix_sparse_connected_graph.to_excel(excel_writer, sheet_name='sparse-connected-graph', index=False)

        excel_writer.close()

    @staticmethod
    def spfa():
        path = "../spfa/cmake-build-debug/spfa"
        xlsx_path = "../spfa.xlsx"

        result = AlgoRunner.run_algo(path)

        cols = c
        index = i

        head = [""] * cols
        head[index] = "spfa"

        v = [""] * cols
        v[index] = "вершины"

        e = [""] * cols
        e[index] = "ребра"

        connected = result[0]
        complete = result[1]
        sparse_connected = result[2]
        a = [v, connected[2], connected[0], v, connected[3], connected[1]]
        matrix_connected_graph = pd.DataFrame([head, v, connected[2], connected[0], e, connected[3], connected[1]])
        matrix_complete_graph = pd.DataFrame([head, v, complete[2], complete[0], e, complete[3], complete[1]])
        matrix_sparse_connected_graph = pd.DataFrame([head, v, sparse_connected[2], sparse_connected[0], e,
                                                      sparse_connected[3], sparse_connected[1]])

        excel_writer = pd.ExcelWriter(xlsx_path, engine='openpyxl')
        matrix_connected_graph.to_excel(excel_writer, sheet_name='connected-graph', index=False)
        matrix_complete_graph.to_excel(excel_writer, sheet_name='complete-graph', index=False)
        matrix_sparse_connected_graph.to_excel(excel_writer, sheet_name='sparse-connected-graph', index=False)

        excel_writer.close()
