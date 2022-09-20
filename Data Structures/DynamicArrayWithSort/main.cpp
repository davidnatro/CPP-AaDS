#include <iostream>

template <typename T>
class Vector {
public:
    struct Iterator {
        using IteratorCategory = std::random_access_iterator_tag;
        using DifferenceType = std::ptrdiff_t;

        explicit Iterator(int *ptr) : m_ptr_(ptr){};

        int &operator*() const;

        int *operator->();

        Iterator &operator++();

        Iterator operator++(int);

        Iterator &operator--();

        Iterator operator--(int);

        Iterator operator+(const DifferenceType &movement);

        Iterator operator-(const DifferenceType &movement);

        Iterator &operator+=(const DifferenceType &movement);

        Iterator &operator-=(const DifferenceType &movement);

        friend bool operator==(const Iterator &a, const Iterator &b);

        friend bool operator!=(const Iterator &a, const Iterator &b);

    private:
        int *m_ptr_;
    };

    Vector() {
        capacity_ = 0;
        size_ = 0;
        data_ = new T[capacity_];
    }

    explicit Vector(int size) {
        this->size_ = 0;
        capacity_ = size * 2;
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

        size_ = new_size;
        capacity_ = size_ * 2;

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
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        --size_;
    }

    void clear() {
        size_ = 0;
    }

    void insert(int pos, int value) {
    }

    void erase(int pos);

    int at(int pos);

    int front() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return data_[0];
    }

    int back() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return data_[size_ - 1];
    }

    int &operator[](int pos) const {
        return data_[pos];
    }

    Vector &operator=(const Vector &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;

        delete[] data_;
        data_ = new T[capacity_];

        for (int i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    Iterator begin() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
    }

    Iterator end() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
    }

    ~Vector() {
        delete[] data_;
    }

private:
    int *data_;
    int capacity_;
    int size_;
};

using std::cout;

int main() {
    Vector<int> vector(5);
    cout << "size: " << vector.getSize() << "\n";
    cout << "capacity: " << vector.getCapacity() << "\n";
    for (int i = 0; i < 10; ++i) {
        vector.pushBack(i);
    }

    cout << "size: " << vector.getSize() << "\n";
    cout << "capacity: " << vector.getCapacity() << "\n";

    for (int i = 0; i < vector.getSize(); ++i) {
        cout << vector[i] << "\t";
    }
    cout << "\n";

    vector.popBack();
    vector.popBack();
    vector.popBack();

    for (int i = 0; i < vector.getSize(); ++i) {
        cout << vector[i] << "\t";
    }
    cout << "\n";
    cout << "size: " << vector.getSize() << "\n";
    cout << "capacity: " << vector.getCapacity() << "\n";

    vector.clear();
    cout << "size: " << vector.getSize() << "\n";
    cout << "capacity: " << vector.getCapacity() << "\n";
    if (vector.getSize() == 0) {
        cout << "empty"
             << "\n";
    } else {
        for (int i = 0; i < vector.getSize(); ++i) {

            cout << vector[i] << "\t";
        }
        cout << "\n";
    }
    cout << std::boolalpha << vector.isEmpty() << "\n";

    return 0;
}
