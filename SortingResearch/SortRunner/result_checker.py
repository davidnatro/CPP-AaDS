class ResultChecker:
    @staticmethod
    def get_result(time, data):
        pass

    @staticmethod
    def is_sorted(data):
        for i in range(0, len(data) - 1):
            if data[i] > data[i + 1]:
                return False

        return True
