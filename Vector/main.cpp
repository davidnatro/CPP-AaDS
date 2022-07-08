#include <iostream>

using namespace std;

class Vector {
private:
    int * data;

    size_t capacity;
    size_t size_arr;

public:
    Vector(int size = 0) {
        data = new int[size];
        capacity = size;
        size_arr = size;
    }

    Vector(const Vector& other) {
        size_arr = other.size_arr;
        capacity = other.capacity;
        data = new int[capacity];
        for (size_t i = 0; i < other.size_arr; ++i) {
            data[i] = other.data[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] data;
        size_arr = other.size_arr;
        capacity = other.capacity;
        data = new int[capacity];
        for (size_t i = 0; i < capacity; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    int operator[](const size_t& x) const {
        return data[x];
    }

    int& operator[](const size_t& x) {
        return data[x];
    }

    size_t size() const {
        return size_arr;
    }

    void push_back(const int& element) {
        if (size() >= capacity) {
            resize();
        }
        data[size_arr] = element;
        ++size_arr;
    }

    void pop_back() {
        --size_arr;
    }

    void resize() {
        if (capacity == 0) {
            capacity = 1;
        }
        capacity *= 2;
        int * newArr = new int[capacity];
        for (size_t i = 0; i < size(); ++i) {
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
    }

    ~Vector() {
        delete[] data;
    }
};

int main() {
    Vector vector(3);

    for (int i = 0; i < vector.size(); ++i) {
        vector[i] = i;
    }

    vector.push_back(1020);

    for (int i = 0; i < vector.size(); ++i) {
        cout << vector[i] << "\t";
    }

    return 0;
}
