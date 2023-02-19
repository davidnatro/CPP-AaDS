import os
from array_generator import ArrayGenerator
from result_checker import ResultChecker


class App:
    def __init__(self):
        self.data_from_0to5 = ArrayGenerator.generate_from0to5(4100)
        self.data_from_0to4000 = ArrayGenerator.generate_from0to4000(4100)
        self.data_almost_sorted = ArrayGenerator.generate_almost_sorted(4100)
        self.data_reverse_sorted = ArrayGenerator.generate_reverse_sorted(4100)

        with open('../Arrays/from0to5.txt', 'w', encoding='UTF-8') as f:
            f.write(str(self.data_from_0to5))
            f.write("\n\n==========================\n\n")
            clone = ArrayGenerator.clone_array(4100, self.data_from_0to5)
            clone.sort()
            f.write(str(clone))

        with open('../Arrays/from0to4000.txt', 'w', encoding='UTF-8') as f:
            f.write(str(self.data_from_0to4000))
            f.write("\n\n==========================\n\n")
            clone = ArrayGenerator.clone_array(4100, self.data_from_0to4000)
            clone.sort()
            f.write(str(clone))

        with open('../Arrays/almost_sorted.txt', 'w', encoding='UTF-8') as f:
            f.write(str(self.data_almost_sorted))
            f.write("\n\n==========================\n\n")
            clone = ArrayGenerator.clone_array(4100, self.data_almost_sorted)
            clone.sort()
            f.write(str(clone))

        with open('../Arrays/reverse_sorted.txt', 'w', encoding='UTF-8') as f:
            f.write(str(self.data_reverse_sorted))
            f.write("\n\n==========================\n\n")
            clone = ArrayGenerator.clone_array(4100, self.data_reverse_sorted)
            clone.sort()
            f.write(str(clone))

        self.run_times = 25

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
        operations = int(result_arr[len(result_arr) - 1])
        result_arr.pop(len(result_arr) - 1)

        return time, result_arr, operations

    def run(self, start, end, step):
        subfolders = self.get_all_sorting_folders()

        head = ['размеры массива']
        results = []
        operations_results = []
        operations = []

        for folder in subfolders:
            head.append(os.path.basename(folder) + " от 0 до 5")
            head.append(os.path.basename(folder) + " от 0 до 4000")
            head.append(os.path.basename(folder) + " почти отсортированный")
            head.append(os.path.basename(folder) + " отсортированный в обратном порядке")

        for i in range(start, end + 1, step):
            times = [i]
            operations = [i]
            for folder in subfolders:
                print("Running " + os.path.basename(folder) + " size " + str(i))

                datafrom0to5 = ArrayGenerator.clone_array(i, self.data_from_0to5)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, datafrom0to5)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)
                operations.append(result[2])

                datafrom0to4000 = ArrayGenerator.clone_array(i, self.data_from_0to4000)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, datafrom0to4000)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)
                operations.append(result[2])

                dataalmostsorted = ArrayGenerator.clone_array(i, self.data_almost_sorted)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, dataalmostsorted)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)
                operations.append(result[2])

                datareversesorted = ArrayGenerator.clone_array(i, self.data_reverse_sorted)
                time = 0

                for j in range(self.run_times):
                    result = self.calculate_time(folder, datareversesorted)
                    if ResultChecker.is_sorted(result[1]):
                        time += result[0]

                time = time / self.run_times
                times.append(time)
                operations.append(result[2])

            results.append(times)
            operations_results.append(operations)

        return head, results, operations_results
