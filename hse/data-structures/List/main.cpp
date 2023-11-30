#include <iostream>
#include <cmath>

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
    int size_ = 0;

    bool isValid(int value) {
        return value >= -max_value_ && value <= max_value_;
    }

public:
    Node* head{};
    Node* tail{};

    List() {
        head = nullptr;
        tail = nullptr;
    }

    List(int* values, size_t size) {
        for (size_t i = 0; i < size; ++i) {
            if (!isValid(values[i])) {
                this->~List();
                throw std::runtime_error("Wrong Value!");
            }

            pushBack(values[i]);
        }
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

            temp->next = tail;
            tail->previous = temp;

            tail->next = head;
            head->previous = tail;
        }

        ++size_;
    }

    void pushFront(int value) {
        if (!isValid(value)) {
            throw std::runtime_error("Wrong Value!");
        }

        if (head == nullptr) {
            head = new Node(value);
            tail = head;

            tail->next = head;
            head->previous = tail;
        } else {
            Node* temp = head;
            head = new Node(value);

            head->next = temp;
            temp->previous = head;

            head->previous = tail;
            tail->next = head;
        }

        ++size_;
    }

    int pop() {
        if (head == nullptr) {
            throw std::runtime_error("Can not pop such element!");
        }

        int result;
        --size_;

        if (head == tail) {
            result = head->data;
            delete head;
            head = tail = nullptr;

            return result;
        } else if (head->next == tail) {
            result = head->data;
            delete head;
            head = tail;
            head->next = tail;
            tail->previous = head;

            return result;
        }

        result = head->data;

        Node* new_head = head->next;
        delete head;
        head = new_head;

        tail->next = head;
        head->previous = tail;

        return result;
    }

    int pop(size_t position) {
        if (position >= size_ - 1 || position < 0 || size_ == 1 || size_ == 0) {
            throw std::runtime_error("Wrong Position!");
        }

        --size_;
        int result;

        position += 1;
        Node* current = head;
        if (position != 0) {
            while (--position) {
                current = current->next;
            }
        }

        Node* to_delete = current->next;
        result = to_delete->data;
        current->next = to_delete->next;
        to_delete->next->previous = current;

        if (to_delete == tail) {
            tail = current;
        }

        delete to_delete;

        return result;
    }

    void push(int value, size_t position) {
        if (!isValid(value)) {
            throw std::runtime_error("Wrong Value!");
        } else if (position >= size_ || position < 0) {
            throw std::runtime_error("Wrong Position!");
        }

        Node* current = head;
        position += 1;
        if (position != 0) {
            while (--position) {
                current = current->next;
            }
        }

        Node* new_next = current->next;
        Node* new_node = new Node(value);

        current->next = new_node;
        new_node->next = new_next;
        new_next->previous = new_node;
        new_node->previous = current;

        if (current == tail) {
            tail = new_node;
            tail->next = head;
            head->previous = tail;
        }

        ++size_;
    }

    ~List() {
        Node* temp;
        while (head != tail) {
            temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }
};

using std::cin;
using std::cout;

#include <list>
#include <ctime>

int main() {
    int* arr = new int[5];
    for (int i = 0; i < 5; ++i) {
        arr[i] = i + 1;
    }

    std::clock_t start = std::clock();

    List list(arr, 5);

    for (int i = 0; i < 5; ++i) {
        list.push(i + 1, 0);
    }

    //    for (int i = 0; i >= -5; --i) {
    //        list.pushFront(i);
    //    }

    int index = 0;
    Node* begin = list.head;
    while (begin != list.tail) {
        begin = begin->next;
        ++index;
    }
    ++index;
    cout << "length: " << index << "\n";

    // 1	5	4	3	2	1	2	3	4	5
    for (int i = index; i >= 0; --i) {
        try {
            cout << list.pop(i) << "\t";
        } catch (const std::runtime_error& error) {
            cout << error.what() << "\n";
        }
    }
    cout << list.pop() << "\n";

    std::clock_t end = std::clock();
    std::cout << "CPU time used: " << 1000.0 * (end - start) / CLOCKS_PER_SEC << " ms\n";

    List list2;
    list2.pushBack(1);
    cout << list.pop(0) << "\n";

    return 0;
}
