from result_builder import ResultBuilder
from excel_writer import ExcelWriter


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
        xlsx_path = "../bellman-ford"
        result = AlgoRunner.run_algo(path)

        ExcelWriter.write_results(xlsx_path, ["bellman ford", "", "", ""], result[0])
        ExcelWriter.write_results(xlsx_path, ["bellman ford", "", "", ""], result[1])
        ExcelWriter.write_results(xlsx_path, ["bellman ford", "", "", ""], result[2])

    @staticmethod
    def dijkstra():
        path = "../dijkstra/cmake-build-debug/dijkstra"
        xlsx_path = "../dijkstra"

    @staticmethod
    def floyd_warshall():
        path = "../floyd-warshall/cmake-build-debug/floyd_warshall"
        xlsx_path = "../floyd-warshall.xlsx"

    @staticmethod
    def spfa():
        path = "../spfa/cmake-build-debug/spfa"
        xlsx_path = "../spfa.xlsx"
