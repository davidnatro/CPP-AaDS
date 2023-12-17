#include "../headers/trie.h"

Trie::Trie() {
    root_ = new Node();
}

void Trie::insert(std::string word) {
    Node *node = root_;
    for (int i = 0; i < word.size(); ++i) {
        int index = word[i] - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new Node();
        }
        node->children[index]->letter = word[i];
        if (i == word.size() - 1) {
            node->children[index]->terminal = true;
        }
        node = node->children[index];
    }
}

bool Trie::search(std::string word) {
    Node *node = root_;
    for (const char letter : word) {
        int index = letter - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }

    return node->terminal;
}

bool Trie::startsWith(std::string prefix) {
    Node *node = root_;
    for (const char letter : prefix) {
        int index = letter - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }

    return true;
}

void Trie::destroy(Node *node) {
    if (node == nullptr) {
        return;
    }

    for (Node *child : node->children) {
        destroy(child);
    }

    delete node;
}

Trie::~Trie() {
    destroy(root_);
}