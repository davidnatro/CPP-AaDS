import random


class ArrayGenerator:
    @staticmethod
    def clone_array(size, data):
        result = []

        for i in range(0, size):
            result.append(data[i])

        return result

    @staticmethod
    def generate_from0to5(size):
        result = []
        for i in range(0, size):
            result.append(random.randint(0, 5))

        return result

    @staticmethod
    def generate_from0to4000(size):
        result = []

        for i in range(0, size):
            result.append(random.randint(0, 4000));

        return result

    @staticmethod
    def generate_almost_sorted(size):
        result = []

        index = 0
        for i in range(0, size):
            if index % 2 == 0:
                result.append(random.randint(0, 4000));
            else:
                result.append(i)

        return result

    @staticmethod
    def generate_reverse_sorted(size):
        result = []
        for i in range(size, 0, -1):
            result.append(i)

        return result
