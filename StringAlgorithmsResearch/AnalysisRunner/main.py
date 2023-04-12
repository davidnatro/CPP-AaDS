from app import App
from result_writer import ResultWriter

if __name__ == '__main__':
    app = App()
    results = app.run()

    resultWriter = ResultWriter(results[0], results[1])
    resultWriter.write_result("../results.xlsx")
