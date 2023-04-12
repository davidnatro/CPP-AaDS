from random import SystemRandom


class DataGenerator:
    def __init__(self):
        self.binary10k = ""
        self.binary100k = ""

        self.alphabet10k = ""
        self.alphabet100k = ""

        self.alphabet = ["a", "b", "c", "d"]
        self.generator = SystemRandom()

        self.generate_binary10k()
        self.generate_binary100k()
        self.generate_alphabet10k()
        self.generate_alphabet100k()

    def get_binary10k(self):
        return self.binary10k

    def get_binary100k(self):
        return self.binary100k

    def get_alphabet10k(self):
        return self.alphabet10k

    def get_alphabet100k(self):
        return self.alphabet100k

    def generate_binary10k(self):
        for i in range(10000):
            self.binary10k += str(self.generator.randint(0, 1))

        with open('../Data/binary10k.txt', 'w', encoding='UTF-8') as f:
            f.write(self.binary10k)

    def generate_binary100k(self):
        for i in range(100000):
            self.binary100k += str(self.generator.randint(0, 1))

        with open('../Data/binary100k.txt', 'w', encoding='UTF-8') as f:
            f.write(self.binary100k)

    def generate_alphabet10k(self):
        for i in range(10000):
            self.alphabet10k += self.alphabet[self.generator.randint(0, 3)]

        with open('../Data/alphabet10k.txt', 'w', encoding='UTF-8') as f:
            f.write(self.alphabet10k)

    def generate_alphabet100k(self):
        for i in range(100000):
            self.alphabet100k += self.alphabet[self.generator.randint(0, 3)]

        with open('../Data/alphabet100k.txt', 'w', encoding='UTF-8') as f:
            f.write(self.alphabet100k)
