#ifndef LEETCODE_PROBLEMS_MEDIUM_HEADERS_CLONE_GRAPH_H_
#define LEETCODE_PROBLEMS_MEDIUM_HEADERS_CLONE_GRAPH_H_

#include <map>
#include <queue>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node();
    Node(int val);
    Node(int val, std::vector<Node*> neighbors);
    ~Node();
};

class CloneGraph {
public:
    Node* cloneGraph(Node* node);
};

#endif
