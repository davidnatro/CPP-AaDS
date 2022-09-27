#include <iostream>
#include <initializer_list>

class Vector {
public:
    struct Iterator {
        using IteratorCategory = std::random_access_iterator_tag;
        using DifferenceType = std::ptrdiff_t;

        explicit Iterator(int *ptr) : m_ptr_(ptr){};

        int &operator*() const {
            return *m_ptr_;
        }

        int *operator->() {
            return m_ptr_;
        }

        Iterator &operator++() {
            ++m_ptr_;
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            ++m_ptr_;
            return old;
        }

        Iterator &operator--() {
            --m_ptr_;
            return *this;
        }

        Iterator operator--(int) {
            Iterator old = *this;
            --m_ptr_;
            return old;
        }

        Iterator operator+(const DifferenceType &movement) {
            Iterator copy = *this;
            copy += movement;
            return copy;
        }

        Iterator operator-(const DifferenceType &movement) {
            Iterator copy = *this;
            copy -= movement;
            return copy;
        }

        Iterator &operator+=(const DifferenceType &movement) {
            m_ptr_ += movement;
            return *this;
        }

        Iterator &operator-=(const DifferenceType &movement) {
            m_ptr_ -= movement;
            return *this;
        }

        friend int64_t operator-(const Iterator &a, const Iterator &b) {
            return a.m_ptr_ - b.m_ptr_;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.m_ptr_ == b.m_ptr_;
        }

        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return !(a == b);
        }

    private:
        int *m_ptr_;
    };

    Vector() {
        data_ = new int[capacity_];
    }

    explicit Vector(int size) {
        size_ = size;
        capacity_ = size * 2;
        data_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = 0;
        }
    }

    Vector(const int *vals, int size) {
        size_ = size;
        capacity_ = size * 2;
        data_ = new int[capacity_];
        for (int i = 0; i < size; ++i) {
            data_[i] = vals[i];
        }
    }

    Vector(const Vector &vector) {
        size_ = vector.size_;
        capacity_ = vector.capacity_;
        data_ = new int[capacity_];
        for (int i = 0; i < size_; ++i) {
            data_[i] = vector.data_[i];
        }
    }

    Vector(std::initializer_list<int> vals) {
        size_ = vals.size();
        capacity_ = size_ * 2;
        data_ = new int[capacity_];
        int index = 0;
        for (const int *it = vals.begin(); it != vals.end(); ++it) {
            data_[index] = *it;
            ++index;
        }
    }

    int getSize() const {
        return size_;
    }

    int getCapacity() const {
        return capacity_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    void resize(int new_size) {
        int *new_arr;
        if (new_size >= capacity_) {
            capacity_ = 2 * new_size;
            new_arr = new int[capacity_];
        } else {
            new_arr = new int[new_size];
        }

        if (new_size > size_) {
            for (int i = size_; i < new_size; ++i) {
                new_arr[i] = 0;
            }

            for (int i = 0; i < size_; ++i) {
                new_arr[i] = data_[i];
            }
        } else {
            for (int i = 0; i < new_size; ++i) {
                new_arr[i] = data_[i];
            }
        }

        size_ = new_size;

        delete[] data_;
        data_ = new_arr;
    }

    void pushBack(int value) {
        if (size_ >= capacity_) {
            resize(capacity_);
        }
        data_[size_] = value;
        ++size_;
    }

    void popBack() {
        if (isEmpty()) {
            throw std::runtime_error("Empty Array!");
        }

        --size_;
    }

    void clear() {
        size_ = 0;
    }

    void insert(int pos, int value) {
        if (pos < 0 || pos > size_) {
            throw std::runtime_error("Wrong Position!");
        }

        if (size_ >= capacity_) {
            resize(capacity_);
        }

        for (int index = size_ - 1; index >= pos; --index) {
            data_[index + 1] = data_[index];
        }

        data_[pos] = value;
        ++size_;
    }

    void erase(int pos) {
        if (isEmpty()) {
            throw std::runtime_error("Empty Array!");
        } else if (pos < 0 || pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }

        for (int i = pos; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        --size_;
    }

    int at(int pos) {
        if (pos < 0 || pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }

        return data_[pos];
    }

    int front() {
        if (isEmpty()) {
            throw std::runtime_error("Empty Array!");
        }

        return data_[0];
    }

    int back() {
        if (isEmpty()) {
            throw std::runtime_error("Empty Array!");
        }
        return data_[size_ - 1];
    }

    int &operator[](int pos) const {
        if (pos < 0 || pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }

        return data_[pos];
    }

    Vector &operator=(const Vector &other) {
        size_ = other.size_;
        capacity_ = other.capacity_;

        delete[] data_;
        data_ = new int[capacity_];

        for (int i = 0; i < other.size_; ++i) {
            data_[i] = other.data_[i];
        }

        return *this;
    }

    Iterator begin() {
        return Iterator(data_);
    }

    Iterator end() {
        return Iterator(data_ + size_);
    }

    ~Vector() {
        delete[] data_;
    }

private:
    int *data_;
    int capacity_ = 10;
    int size_ = 0;
};

Vector merge(Vector::Iterator &begin, Vector::Iterator &middle, Vector::Iterator &end) {
    Vector vector;
    Vector::Iterator i = begin;
    Vector::Iterator j = middle;
    while (i != middle && j != end) {
        if (*i <= *j) {
            vector.pushBack(*i++);
        } else {
            vector.pushBack(*j++);
        }
    }

    while (i != middle) {
        vector.pushBack(*i++);
    }

    while (j != end) {
        vector.pushBack(*j++);
    }

    return vector;
}

void mergeSort(Vector::Iterator begin, Vector::Iterator end) {
    int64_t distance = end - begin;
    if (distance <= 1) {
        return;
    }

    Vector::Iterator middle = begin + distance / 2;

    mergeSort(begin, middle);
    mergeSort(middle, end);

    Vector vector = merge(begin, middle, end);

    int index = 0;
    for (Vector::Iterator it = begin; it != end; ++it) {
        *it = vector[index];
        ++index;
    }
}

void insertionSort(Vector::Iterator begin, Vector::Iterator end) {
    for (Vector::Iterator it = begin; it != end; ++it) {
        for (Vector::Iterator jt = it + 1; jt != end; ++jt) {
            if (*it > *jt) {
                std::swap(*it, *jt);
            }
        }
    }
}

using std::cout;

void print(Vector &vector) {
    // cout << "size: " << vector.getSize() << " capacity: " << vector.getCapacity() << "\n";
    for (Vector::Iterator it = vector.begin(); it != vector.end(); ++it) {
        cout << *it << "\t";
    }

    cout << "\n";
}

int main() {

    int *arr = new int[10];
    int ind = 0;
    for (int i = 9; i >= 0; --i) {
        arr[ind] = i;
        ++ind;
    }

    Vector vector(arr, 10);

    cout << "initial: "
         << "\n";
    print(vector);
    cout << "\n\n";

    cout << "sorting..."
         << "\n";

    mergeSort(vector.begin(), vector.end());

    cout << "\n";

    cout << "sorted: "
         << "\n";
    print(vector);

    return 0;
}

////     Vector vector(5);
////    cout << "size: " << vector.getSize() << "\n";
////    cout << "capacity: " << vector.getCapacity() << "\n";
////    for (int i = 0; i < 10; ++i) {
////        vector.pushBack(i);
////    }
////
////    cout << "size: " << vector.getSize() << "\n";
////    cout << "capacity: " << vector.getCapacity() << "\n";
////
////    for (int i = 0; i < vector.getSize(); ++i) {
////        cout << vector[i] << "\t";
////    }
////    cout << "\n";
////
////    vector.popBack();
////    vector.popBack();
////    vector.popBack();
////
////    for (int i = 0; i < vector.getSize(); ++i) {
////        cout << vector[i] << "\t";
////    }
////    cout << "\n";
////    cout << "size: " << vector.getSize() << "\n";
////    cout << "capacity: " << vector.getCapacity() << "\n";
////
////    // vector.clear();
////    cout << "size: " << vector.getSize() << "\n";
////    cout << "capacity: " << vector.getCapacity() << "\n";
////    if (vector.getSize() == 0) {
////        cout << "empty"
////             << "\n";
////    } else {
////        for (int i = 0; i < vector.getSize(); ++i) {
////
////            cout << vector[i] << "\t";
////        }
////        cout << "\n";
////    }
////    cout << std::boolalpha << vector.isEmpty() << "\n";
////
////    for (auto it = vector.begin(); it != vector.end(); ++it) {
////        cout << *it << "\t";
////    }
////    cout << "\n";
////    vector.insert(3, 4);
////
////    for (auto it = vector.begin(); it != vector.end(); ++it) {
////        cout << *it << "\t";
////    }
////
////    cout << "\n";
////    vector.erase(4);
////    vector.erase(0);
////    vector.erase(2);
////    vector.insert(2, 3);
////    vector.popBack();
////    for (auto it = vector.begin(); it != vector.end(); ++it) {
////        cout << *it << "\t";
////    }
////    cout << "\n";
////
////    cout << vector.back() << "\n";
////    cout << vector.front() << "\n";
////    cout << vector.at(0) << "\n";