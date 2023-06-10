from matrix import Matrix
from matrix_checker import MatrixChecker
import pandas as pd


class ResultBuilder:

    @staticmethod
    def result_for_connected_graphs():
        pass

    @staticmethod
    def result_for_complete_graph():
        pass

    @staticmethod
    def result_for_sparse_connected_graph():
        pass

    @staticmethod
    def get_rows_and_columns_count_for_excel():
        count = 0
        for i in range(10, 1010 + 1, 50):
            count += 1

        return count
