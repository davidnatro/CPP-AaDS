#include <iostream>
#include <stack>

using std::cin;
using std::cout;

int main() {
    std::stack<char> stack;

    std::string input;
    cin >> input;

    for (const char& bracket : input) {
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            stack.push(bracket);
        } else if (bracket == ')' || bracket == '}' || bracket == ']') {
            if (stack.empty()) {
                cout << "NO";
                return 0;
            }
            char peek = stack.top();
            stack.pop();
            if (!(peek == '(' && bracket == ')' || peek == '{' && bracket == '}' ||
                  peek == '[' && bracket == ']')) {
                cout << "NO";
                return 0;
            }
        }
    }
    if (stack.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
