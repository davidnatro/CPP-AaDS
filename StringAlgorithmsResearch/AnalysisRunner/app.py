from random import SystemRandom
from data_generator import DataGenerator

import os
import numpy


class App:
    def __init__(self):
        self.data = DataGenerator()

        self.crypto_generator = SystemRandom()

        self.headers = ["размер паттерна", "нативный бин 10к", "нативный бин 100к", "нативный днк 10к",
                        "нативный днк 100к", "кмп бин 10к", "кмп бин 100к", "кмп днк 10к", "кмп днк 100к",
                        "кмп оптимизированный бин 10к", "кмп оптимизированный бин 100к", "кмп оптимизированный днк 10к",
                        "кмп оптимизированный днк 100к"]

        self.max_pattern_length = 3000

        self.native_path = "./../StringAlgorithms/NaivePatternSearch/cmake-build-debug/NaivePatternSearch"
        self.kmp_path = "./../StringAlgorithms/KMP/cmake-build-debug/KMP"
        self.kmp_optimized_path = "./../StringAlgorithms/KMP_Optimized/cmake-build-debug/KMP_Optimized"
        # "бинарный 10к символов", "бинарный 100к символов", "днк 10к символов","днк 100к символов"

    @staticmethod
    def runtime(pattern, text, path):
        data = " " + pattern + " " + text
        result = int(os.popen(path + data).readlines()[0].strip())
        return result

    def run(self):
        binary10k = self.data.get_binary10k()
        binary10k_results = []

        binary100k = self.data.get_binary100k()
        binary100k_results = []

        alphabet10k = self.data.get_alphabet10k()
        alphabet10k_results = []

        alphabet100k = self.data.get_alphabet100k()
        alphabet100k_results = []

        sizes = []
        for i in range(100, self.max_pattern_length, 100):
            sizes.append(i)

        # native

        print("native binary 10k")

        binary10k_native = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(binary10k) - pattern_length):
                pattern = binary10k[start:pattern_length + start:]
                result += self.runtime(pattern, binary10k, self.native_path)
                patterns += 1
            result /= patterns
            binary10k_native.append(result)
        binary10k_results.append(binary10k_native)

        print("native binary 100k")

        binary100k_native = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(binary100k) - pattern_length):
                pattern = binary100k[start:pattern_length + start:]
                result += self.runtime(pattern, binary100k, self.native_path)
                patterns += 1
            result /= patterns
            binary100k_native.append(result)
        binary100k_results.append(binary100k_native)

        print("native alphabet 10k")

        alphabet10k_native = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(alphabet10k) - pattern_length):
                pattern = alphabet10k[start:pattern_length + start:]
                result += self.runtime(pattern, alphabet10k, self.native_path)
                patterns += 1
            result /= patterns
            alphabet10k_native.append(result)
        alphabet10k_results.append(alphabet10k_native)

        print("native alphabet 100k")

        alphabet100k_native = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(alphabet100k) - pattern_length):
                pattern = alphabet100k[start:pattern_length + start:]
                result += self.runtime(pattern, alphabet100k, self.native_path)
                patterns += 1
            result /= patterns
            alphabet100k_native.append(result)
        alphabet100k_results.append(alphabet100k_native)

        # kmp

        print("kmp binary 10k")

        binary10k_kmp = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(binary10k) - pattern_length):
                pattern = binary10k[start:pattern_length + start:]
                result += self.runtime(pattern, binary10k, self.kmp_path)
                patterns += 1
            result /= patterns
            binary10k_kmp.append(result)
        binary10k_results.append(binary10k_kmp)

        print("kmp binary 100k")

        binary100k_kmp = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(binary100k) - pattern_length):
                pattern = binary100k[start:pattern_length + start:]
                result += self.runtime(pattern, binary100k, self.kmp_path)
                patterns += 1
            result /= patterns
            binary100k_kmp.append(result)
        binary100k_results.append(binary100k_kmp)

        print("kmp alhapbet 10k")

        alphabet10k_kmp = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(alphabet10k) - pattern_length):
                pattern = alphabet10k[start:pattern_length + start:]
                result += self.runtime(pattern, alphabet10k, self.kmp_path)
                patterns += 1
            result /= patterns
            alphabet10k_kmp.append(result)
        alphabet10k_results.append(alphabet10k_kmp)

        print("kmp alhapbet 100k")

        alphabet100k_kmp = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(alphabet100k) - pattern_length):
                pattern = alphabet100k[start:pattern_length + start:]
                result += self.runtime(pattern, alphabet100k, self.kmp_path)
                patterns += 1
            result /= patterns
            alphabet100k_kmp = [].append(result)
        alphabet100k_results.append(alphabet100k_kmp)

        # kmp optimized

        print("kmp optimized binary 10k")

        binary10k_kmp_optimized = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(binary10k) - pattern_length):
                pattern = binary10k[start:pattern_length + start:]
                result += self.runtime(pattern, binary10k, self.kmp_optimized_path)
                patterns += 1
            result /= patterns
            binary10k_kmp_optimized.append(result)
        binary10k_results.append(binary10k_kmp_optimized)

        print("kmp optimized binary 100k")

        binary100k_kmp_optimized = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(binary100k) - pattern_length):
                pattern = binary100k[start:pattern_length + start:]
                result += self.runtime(pattern, binary100k, self.kmp_optimized_path)
                patterns += 1
            result /= patterns
            binary100k_kmp_optimized.append(result)
        binary100k_results.append(binary100k_kmp_optimized)

        print("kmp optimized alhpabet 10k")

        alphabet10k_kmp_optimized = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(alphabet10k) - pattern_length):
                pattern = alphabet10k[start:pattern_length + start:]
                result += self.runtime(pattern, alphabet10k, self.kmp_optimized_path)
                patterns += 1
            result /= patterns
            alphabet10k_kmp_optimized.append(result)
        alphabet10k_results.append(alphabet10k_kmp_optimized)

        print("kmp optimized alhpabet 100k")

        alphabet100k_kmp_optimized = []
        for pattern_length in range(100, self.max_pattern_length, 100):
            result = 0
            patterns = 0
            print("pattern length: " + str(pattern_length))
            for start in range(0, len(alphabet100k) - pattern_length):
                pattern = alphabet100k[start:pattern_length + start:]
                result += self.runtime(pattern, alphabet100k, self.kmp_optimized_path)
                patterns += 1
            result /= patterns
            alphabet100k_kmp_optimized.append(result)
        alphabet100k_results.append(alphabet100k_kmp_optimized)

        matrix = []

        matrix.append(sizes)
        for i in range(0, len(binary10k_results)):
            matrix.append(binary10k_results[i])
            matrix.append(binary100k_results[i])
            matrix.append(alphabet10k_results[i])
            matrix.append(alphabet100k_results[i])

        matrix_result = numpy.transpose(matrix).tolist()

        return self.headers, matrix_result
