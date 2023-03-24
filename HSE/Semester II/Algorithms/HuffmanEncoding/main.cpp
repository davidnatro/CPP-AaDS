#include <iostream>
#include <queue>
#include <map>
#include <functional>

using std::cin;
using std::cout;

struct Node {
    char data;
    int frequency;

    Node* left = nullptr;
    Node* right = nullptr;

    ~Node() {
        delete left;
        delete right;
    }
};

std::map<char, std::string> codes;

std::map<char, int> frequency;

std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> data(
    [](const Node* a, const Node* b) { return a->frequency > b->frequency; });

void generateCode(const Node* root, std::string result) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '\0') {
        codes[root->data] = result;
        return;
    }

    generateCode(root->left, result + "0");
    generateCode(root->right, result + "1");
}

std::string huffman(const std::string& input) {
    for (const char letter : input) {
        frequency[letter] += 1;
    }

    for (const auto& [key, value] : frequency) {
        data.emplace(new Node{key, value});
    }

    if (data.size() == 1) {
        std::string result;
        for (const char letter : input) {
            result += "0";
        }
        codes[input[0]] = "0";
        delete data.top();
        return result;
    }

    while (data.size() > 1) {
        Node* left = data.top();
        data.pop();

        Node* right = data.top();
        data.pop();

        Node* parent = new Node{'\0', left->frequency + right->frequency};
        parent->left = left;
        parent->right = right;

        data.emplace(parent);
    }

    generateCode(data.top(), "");

    std::string result;
    for (const char letter : input) {
        result += codes[letter];
    }

    delete data.top();

    return result;
}

int main() {
    std::string input;
    cin >> input;

    std::string full_code = huffman(input);

    cout << frequency.size() << " " << full_code.size() << '\n';

    for (const auto& [letter, code] : codes) {
        cout << letter << ": " << code << '\n';
    }

    cout << full_code << "\n";

    return 0;
}
