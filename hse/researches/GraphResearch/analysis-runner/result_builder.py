from matrix import Matrix
from runner import Runner
from matrix_checker import MatrixChecker


class ResultBuilder:

    @staticmethod
    def result_for_connected_graphs(algorithm):
        from_el = 10
        to_el = 1010
        verts = []
        vertices_results = []
        edges = []
        edges_results = []

        for vertices in range(from_el, to_el + 1, 50):
            edges_num = vertices * (vertices - 1) / 2
            graph = Matrix.generate_connected_graph(vertices, edges_num, 0.4)
            if not MatrixChecker.is_connected_graph(graph):
                print("invalid connected graph")
                if vertices >= 60:
                    vertices -= 50
                continue

            verts.append(vertices)
            edges.append(edges_num)
            time_result = Runner.run_avg(algorithm, Matrix.to_string(graph))
            vertices_results.append(time_result)
            edges_results.append(time_result)
            print("running " + algorithm.split("/")[-1] + " connected : " +
                  str(vertices) + 'x' + str(edges_num))

        return vertices_results, edges_results, verts, edges

    @staticmethod
    def result_for_complete_graph(algorithm):
        from_el = 10
        to_el = 1010
        verts = []
        vertices_results = []
        edges = []
        edges_results = []

        for vertices in range(from_el, to_el + 1, 50):
            edges_num = vertices * (vertices - 1) / 2
            graph = Matrix.generate_complete_graph(vertices, edges_num)
            if not MatrixChecker.is_complete_graph(graph):
                print("invalid complete graph")
                if vertices >= 60:
                    vertices -= 50
                continue

            verts.append(vertices)
            edges.append(edges_num)
            time_result = Runner.run_avg(algorithm, Matrix.to_string(graph))
            vertices_results.append(time_result)
            edges_results.append(time_result)
            print("running " + algorithm.split("/")[-1] + " complete : " +
                  str(vertices) + 'x' + str(edges_num))

        return vertices_results, edges_results, verts, edges

    @staticmethod
    def result_for_sparse_connected_graph(algorithm):
        from_el = 10
        to_el = 1010
        verts = []
        vertices_results = []
        edges = []
        edges_results = []

        for vertices in range(from_el, to_el + 1, 50):
            edges_num = vertices * (vertices - 1) / 2
            graph = Matrix.generate_sparse_connected_graph(vertices, edges_num)
            if not MatrixChecker.is_sparse_connected_graph(graph):
                print("invalid sparse-connected graph")
                if vertices >= 60:
                    vertices -= 50
                continue

            verts.append(vertices)
            edges.append(edges_num)
            time_result = Runner.run_avg(algorithm, Matrix.to_string(graph))
            vertices_results.append(time_result)
            edges_results.append(time_result)
            print("running " + algorithm.split("/")[-1] + " sparse-connected : " +
                  str(vertices) + 'x' + str(edges_num))

        return vertices_results, edges_results, verts, edges
