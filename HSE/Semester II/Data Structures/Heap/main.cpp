#include <iostream>
#include <vector>

template <class ValueType>
class Heap {
private:
    std::vector<ValueType> data_;

public:
    Heap() {
    }

    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        for (auto it = begin; it != end; ++it) {
            insert(*it);
        }
    }

    Heap(std::initializer_list<ValueType> initializer_list) {
        for (auto it = initializer_list.begin(); it != initializer_list.end(); ++it) {
            insert(*it);
        }
    }

    Heap(const Heap &other) {
        data_ = other.data_;
    }

    Heap &operator=(const Heap &other) {
        if (this == &other) {
            return *this;
        }

        data_ = other.data_;
        return *this;
    }

    Heap(Heap &&other) {
        data_ = std::move(other.data_);
    }

    Heap &operator=(Heap &&other) {
        if (this == &other) {
            return *this;
        }

        data_ = std::move(other.data_);
        return *this;
    }

    size_t size() const {
        return data_.size();
    }

    bool empty() const {
        return data_.empty();
    }

    void insert(const ValueType &value) {
        data_.emplace_back(value);
        restoreEnd(data_.size() - 1);
    }

    ValueType extract() {
        ValueType result = data_[0];
        data_[0] = data_[size() - 1];
        data_.erase(data_.end() - 1);
        restoreRoot(0);
        return result;
    }

    ~Heap() {
    }

private:
    void restoreRoot(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size() && data_[largest] < data_[left]) {
            largest = left;
        }

        if (right < size() && data_[largest] < data_[right]) {
            largest = right;
        }

        if (i != largest) {
            std::swap(data_[i], data_[largest]);
            restoreRoot(largest);
        }
    }

    void restoreEnd(int i) {
        int parent = (i - 1) / 2;
        while (i != parent) {
            if (data_[parent] < data_[i]) {
                std::swap(data_[i], data_[parent]);
            }

            i = parent;
            parent = (i - 1) / 2;
        }
    }
};

int main() {

    Heap<int> heap{1, 2, 3, 4, 5, 6, 7};

    for (int i = 0; i < heap.size(); ++i) {
        std::cout << "size: " << heap.size() << " element: " << heap.extract() << "\n";
    }

    return 0;
}
