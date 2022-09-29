#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

class Node {
public:
    int data{};
    Node* next;
    Node* previous;

    Node(int data) {
        this->data = data;
    }
};

class List {
private:
    const int max_value_ = 2 * pow(10, 9);

    bool isValid(int value) {
        return value >= -max_value_ || value <= max_value_;
    }

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    List(int* values, size_t size) {
        for (int i = 0; i < size; ++i) {
            if (!isValid(values[i])) {
                throw std::runtime_error("Wrong Value!");
            }
        }
    }

    ~List() {
        delete head;
        delete tail;
    }

    void pushBack(int value) {
        if (!isValid(value)) {
            throw std::runtime_error("Wrong Value!");
        }

        if (head == nullptr) {
            tail = new Node(value);
            head = tail;

            head->previous = tail;
            tail->next = head;
        } else {
            Node* temp = tail;

            tail = new Node(value);
            tail->next = head;
            temp->next = tail;
            tail->previous = temp;

            // delete head->previous;
            head->previous = tail;
        }
    }

    void pushFront(int value) {
    }

    int pop();
    int pop(size_t position);
    void push(int value, size_t position);

    Node* head{};
    Node* tail{};
};

using std::cin;
using std::cout;

int main() {
    int* arr = new int[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }

    List list;
    list.pushBack(1);
    cout << list.head->data << " " << list.tail->data << "\n";
    list.pushBack(2);
    list.pushBack(3);
    list.pushBack(3);
    list.pushBack(3);

    // cout << list.head->next->data << "\t";

    //    Node* current = list.head->next;
    //    cout << list.head->data << "\t";
    //    while (current != list.head) {
    //        cout << current->data << "\t";
    //        current = current->next;
    //    }

    Node* current = list.head;

    do {
        cout << current->data << "\t";
        current = current->next;
    } while (current != list.tail);

    return 0;
}
