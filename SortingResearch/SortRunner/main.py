from array_generator import ArrayGenerator
from application import App
import result_checker
import csv

if __name__ == '__main__':
    app = App()
    app.run()

    # with open('../Results.csv', 'w', encoding='UTF-8') as f:
    #     writer = csv.writer(f)
    #
    #     writer.writerows(data)
    #     writer.writerow(ad)
