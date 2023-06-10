import os


class Runner:

    @staticmethod
    def run(path, args):
        return os.popen(path + ' ' + args).readlines()[0].strip()
