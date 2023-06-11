import pandas as pd


class ExcelWriter:

    @staticmethod
    def write_results(path, head, matrix):
        df = pd.DataFrame(matrix, columns=head)
        with pd.ExcelWriter(path + ".xlsx") as writer:
            df.to_excel(writer)
