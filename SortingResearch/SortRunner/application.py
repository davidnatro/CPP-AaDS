import os
from array_generator import ArrayGenerator
from result_checker import ResultChecker


class App:
    def __init__(self):
        self.data_from_0to5 = ArrayGenerator.generate_from0to5(4100)
        self.data_from_0to4000 = ArrayGenerator.generate_from0to4000(4100)
        self.data_almost_sorted = ArrayGenerator.generate_almost_sorted(4100)
        self.data_reverse_sorted = ArrayGenerator.generate_reverse_sorted(4100)

        self.run_times = 15

    def get_all_sorting_folders(self):
        sorts = "../SortAlgorithms/"
        subfolders = [f.path for f in os.scandir(sorts) if f.is_dir()]

        return subfolders

    def calculate_time(self, path, arr):
        input_data = " " + str(len(arr)) + " "

        for i in range(len(arr)):
            input_data += str(arr[i])
            if i != len(arr) - 1:
                input_data += " "

        result = os.popen("./" + path + "/cmake-build-debug/" + os.path.basename(path) + input_data).readlines()

        time = int(result[0].strip())
        result_arr = [int(i) for i in result[1].strip().split("\t")]

        return time, result_arr

    def run(self, start, end, step):
        subfolders = self.get_all_sorting_folders()

        head = ['размеры массива']
        results = []
        times = []

        for folder in subfolders:
            print("Running " + os.path.basename(folder))
            head.append(os.path.basename(folder) + " от 0 до 5")
            head.append(os.path.basename(folder) + " от 0 до 4000")
            head.append(os.path.basename(folder) + " почти отсортированный")
            head.append(os.path.basename(folder) + " отсортированный в обратном порядке")

            for i in range(start, end + 1, step):
                print("Size " + str(i))
                times.append(i)

                datafrom0to5 = ArrayGenerator.clone_array(i, self.data_from_0to5)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, datafrom0to5)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)

                datafrom0to4000 = ArrayGenerator.clone_array(i, self.data_from_0to4000)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, datafrom0to4000)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)

                dataalmostsorted = ArrayGenerator.clone_array(i, self.data_almost_sorted)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, dataalmostsorted)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)

                datareversesorted = ArrayGenerator.clone_array(i, self.data_reverse_sorted)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, datareversesorted)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)

                results.append(times)
                times.clear()

        print(head)
        print(results)
