#include <iostream>

template<typename T>
class Vector {
public:
    struct Iterator {
    };

    Vector() {
        capacity_ = 0;
        size_ = 0;
        data_ = new T[capacity_];
    }

    explicit Vector(int size) {
        this->size_ = 0;
        capacity_ = size;
        data_ = new T[capacity_];
    }

    Vector(const int *vals, int size) {
        size_ = size;
        capacity_ = size;
        data_ = new T[capacity_];
        for (int i = 0; i < size; ++i) {
            data_[i] = vals[i];
        }
    }

    Vector(const Vector &vector) {
        size_ = vector.size_;
        capacity_ = vector.capacity_;
        data_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = vector[i];
        }
    }

    Vector(std::initializer_list<int> vals) {
        size_ = vals.size();
        capacity_ = size_;
    }

    int getSize() const {
        return size_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    int getCapacity() const {
        return capacity_;
    }

    void resize(int new_size) {
        int *new_arr = new T[new_size];
        for (int i = 0; i < size_; ++i) {
            new_arr[i] = data_[i];
        }
        delete[] data_;
        data_ = new_arr;
    }

    void pushBack(int value) {
        if (size_ >= capacity_) {
            capacity_ *= 2;
            resize(capacity_);
        }
        data_[size_] = value;
        ++size_;
    }

    void popBack() {
        --size_;
    }

    void clear() {
        size_ = 0;
    }

    void insert(int pos, int value) {
        if ()
    }

    ~Vector() {
        delete[] data_;
    }

public:
    int *data_;
    int capacity_;
    int size_;
};

using std::cout;

int main() {
    Vector<int> vector(5);
    cout << vector.size_ << "\n";
    cout << vector.capacity_ << "\n";
    for (int i = 0; i < 10; ++i) {
        vector.pushBack(i);
    }

    cout << vector.size_ << "\n";
    cout << vector.capacity_ << "\n";

    for (int i = 0; i < 10; ++i) {
        cout << vector.data_[i] << "\n";
    }

    vector.popBack();

    cout << vector.size_ << "\n";
    cout << vector.capacity_ << "\n";

    return 0;
}
