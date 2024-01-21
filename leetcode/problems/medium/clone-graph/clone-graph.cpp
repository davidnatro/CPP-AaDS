#include "clone-graph.h"

Node::Node() {
    val = 0;
    neighbors = std::vector<Node *>();
}

Node::Node(int val) {
    this->val = val;
    neighbors = std::vector<Node *>();
}

Node::Node(int val, std::vector<Node *> neighbors) {
    this->val = val;
    this->neighbors = neighbors;
}

Node::~Node() {
    for (Node *node : neighbors) {
        delete node;
        node = nullptr;
    }
}

Node *CloneGraph::cloneGraph(Node *node) {
    if (node == nullptr) {
        return nullptr;
    }

    std::map<Node *, Node *> visited_nodes;
    std::queue<Node *> bfs;

    Node *head = new Node(node->val);
    visited_nodes[node] = head;

    bfs.emplace(node);

    while (!bfs.empty()) {
        Node *q_node = bfs.front();
        bfs.pop();

        for (Node *neighbor : q_node->neighbors) {
            if (!visited_nodes.count(neighbor)) {
                Node *cloned_node = new Node(neighbor->val);
                visited_nodes[neighbor] = cloned_node;
                bfs.emplace(neighbor);
            }

            visited_nodes[q_node]->neighbors.emplace_back(visited_nodes[neighbor]);
        }
    }

    return head;
}