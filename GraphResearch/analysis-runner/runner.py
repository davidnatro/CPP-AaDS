import os


class Runner:

    @staticmethod
    def run(path):
        return os.popen(path).readlines()[0].strip()

    @staticmethod
    def run_avg(path, args):
        Runner.write_to_file(path, args)
        avg = 0
        for i in range(10):
            avg += int(Runner.run(path))

        avg /= 15

        return avg

    @staticmethod
    def write_to_file(path, matrix):
        with open(path.split('/')[-1] + '.txt', 'w') as f:
            f.write(matrix)
