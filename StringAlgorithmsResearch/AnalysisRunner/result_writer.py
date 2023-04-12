import pandas as pd


class ResultWriter:
    def __init__(self, headers, matrix):
        self.headers = headers
        self.matrix = matrix

    def write_result(self, path):
        df = pd.DataFrame(self.matrix, columns=self.headers)
        with pd.ExcelWriter(path) as writer:
            df.to_excel(writer)
