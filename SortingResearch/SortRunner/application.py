import os
from array_generator import ArrayGenerator


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

    def run(self):
        subfolders = self.get_all_sorting_folders()

        head = ['размеры массива']

        for folder in subfolders:
            head.append(os.path.basename(folder))

            for i in range(50, 300, 50):
                datafrom0to5 = ArrayGenerator.clone_array(i, self.data_from_0to5)
                datafrom0to4000 = ArrayGenerator.clone_array(i, self.data_from_0to4000)
                dataalmostsorted = ArrayGenerator.clone_array(i, self.data_almost_sorted)
                datareversesorted = ArrayGenerator.clone_array(i, self.data_reverse_sorted)
