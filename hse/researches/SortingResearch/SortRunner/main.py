from application import App
import pandas as pd


def main():
    app = App()
    from50to300_results = app.run(50, 300, 50)

    from100to4100_results = app.run(100, 4100, 100)

    df = pd.DataFrame(from50to300_results[1], columns=from50to300_results[0])
    with pd.ExcelWriter("../TimeResults0_50.xlsx") as writer:
        df.to_excel(writer)

    df = pd.DataFrame(from50to300_results[2], columns=from50to300_results[0])
    with pd.ExcelWriter("../OperationsResults0_50.xlsx") as writer:
        df.to_excel(writer)

    df = pd.DataFrame(from100to4100_results[1], columns=from100to4100_results[0])
    with pd.ExcelWriter("../TimesResults100_4100.xlsx") as writer:
        df.to_excel(writer)

    df = pd.DataFrame(from100to4100_results[2], columns=from100to4100_results[0])
    with pd.ExcelWriter("../OperationsResults100_4100.xlsx") as writer:
        df.to_excel(writer)


if __name__ == '__main__':
    main()
