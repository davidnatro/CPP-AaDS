from array_generator import ArrayGenerator
from application import App
import result_checker
import csv


def main():
    app = App()
    from50to300_results = app.run(50, 300, 50)

    from100to4100_results = app.run(100, 4100, 100)

    with open('../Results0_50.csv', 'w', encoding='UTF-8') as f:
        writer = csv.writer(f, delimiter=';')

        writer.writerow(from50to300_results[0])
        writer.writerows(from50to300_results[1])

    with open('../Results100_4100.csv', 'w', encoding='UTF-8') as f:
        writer = csv.writer(f, delimiter=';')

        writer.writerow(from100to4100_results[0])
        writer.writerows(from100to4100_results[1])


if __name__ == '__main__':
    main()
