#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;

class SqrtOnly {
public:
    explicit SqrtOnly(const int *array, int size, const std::function<int(int, int)> &func)
        : size_(size),
          block_size_(std::ceil(sqrt(size))),
          data_(size_, 0),
          blocks_(block_size_, 0),
          func_(func) {
        int block = 0;
        for (int i = 0; i < size_; ++i) {
            data_[i] = array[i];

            blocks_[block] = func_(blocks_[block], data_[i]);

            if ((i + 1) % block_size_ == 0) {
                ++block;
                if (block < block_size_) {
                    blocks_[block] = 0;
                }
            }
        }
    }

    void insert(int position, int value) {
        if (position < 1 || position > size_ + 1) {
            throw std::runtime_error("Wrong position!");
        }
        position -= 1;

        data_.insert(data_.begin() + position, value);
        size_ += 1;

        int new_block_size = std::ceil(sqrt(size_));
        if (new_block_size > block_size_) {
            blocks_.resize(block_size_ = new_block_size);

            int block = 0;
            blocks_[block] = 0;
            for (int i = 0; i < size_; ++i) {
                blocks_[block] = func_(blocks_[block], data_[i]);

                if ((i + 1) % block_size_ == 0) {
                    ++block;
                    if (block < block_size_) {
                        blocks_[block] = 0;
                    }
                }
            }
        } else {
            int block = position / block_size_;  // Блок
            blocks_[block] = 0;
            position -= position % block_size_;  // начало блока

            for (int i = position; i < size_; ++i) {
                blocks_[block] = func_(blocks_[block], data_[i]);
                if ((i + 1) % block_size_ == 0) {
                    ++block;
                    if (block < block_size_) {
                        blocks_[block] = 0;
                    }
                }
            }
        }
    }

    void erase(int position) {
        if (position < 1 || position > size_) {
            throw std::runtime_error("Wrong position!");
        }
        position -= 1;

        data_.erase(data_.begin() + position);
        size_ -= 1;

        int new_block_size = std::ceil(sqrt(size_));
        if (new_block_size < block_size_ - 1) {
            blocks_.resize(block_size_ = new_block_size);

            int block = 0;
            blocks_[block] = 0;
            for (int i = 0; i < size_; ++i) {
                blocks_[block] = func_(blocks_[block], data_[i]);

                if ((i + 1) % block_size_ == 0) {
                    ++block;
                    if (block < block_size_) {
                        blocks_[block] = 0;
                    }
                }
            }
        } else {
            int block = position / block_size_;  // Блок
            blocks_[block] = 0;
            position -= position % block_size_;  // начало блока

            for (int i = position; i < size_; ++i) {
                blocks_[block] = func_(blocks_[block], data_[i]);
                if ((i + 1) % block_size_ == 0) {
                    ++block;
                    if (block < block_size_) {
                        blocks_[block] = 0;
                    }
                }
            }
        }
    }

    void change(int position, int value) {
        if (position < 1 || position > size_) {
            throw std::runtime_error("Wrong position!");
        }
        position -= 1;

        data_[position] = value;
        int block = position / block_size_;  // Блок
        blocks_[block] = 0;
        position -= position % block_size_;  // начало блока

        for (int i = 0; i < block_size_; ++i) {
            if (position >= size_) {
                break;
            }
            blocks_[block] = func_(blocks_[block], data_[position++]);
        }
    }

    int at(int position) const {
        if (position < 1 || position > size_) {
            throw std::runtime_error("Wrong position!");
        }

        return data_[--position];
    }

    int compute(int left, int right) const {
        if (left < 1 || right > size_) {
            throw std::runtime_error("Wrong position!");
        }

        int result = 0;
        for (int i = left - 1; i < right; ++i) {
            if (i + block_size_ - 1 < right) {
                if (i / block_size_ == (i + block_size_ - 1) / block_size_) {
                    if (i % block_size_ == 0 &&
                        (i + block_size_ - 1) % block_size_ == block_size_ - 1) {
                        result = func_(result, blocks_[i / block_size_]);
                        i += block_size_ - 1;
                        continue;
                    }
                }
            }

            result = func_(result, data_[i]);
        }
        return result;
    }

    int size() const {
        return size_;
    }

private:
    int size_;
    int block_size_;

    std::vector<int> data_;
    std::vector<int> blocks_;

    std::function<int(int, int)> func_;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    std::string operation;
    cin >> operation;
    std::function<int(int, int)> func;
    if (operation == "^") {
        func = [](int x, int y) { return x ^ y; };
    } else if (operation == "+") {
        int mod;
        cin >> mod;
        func = [mod](int x, int y) {
            x += y;
            x %= mod;
            while (x < 0) {
                x += mod;
            }
            return x;
        };
    }

    int size;
    cin >> size;

    int *array = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
    cout.flush();

    SqrtOnly sqrt_only(array, size, func);

    int operations;
    cin >> operations;

    std::string command;
    int input1, input2;
    for (int i = 0; i < operations; ++i) {
        cin >> command;
        if (command == "compute") {
            cin >> input1 >> input2;
            cout << sqrt_only.compute(input1, input2) << "\n";
        } else if (command == "size") {
            cout << sqrt_only.size() << "\n";
        } else if (command == "insert") {
            cin >> input1 >> input2;
            sqrt_only.insert(input1, input2);
        } else if (command == "erase") {
            cin >> input1;
            sqrt_only.erase(input1);
        } else if (command == "change") {
            cin >> input1 >> input2;
            sqrt_only.change(input1, input2);
        } else if (command == "at") {
            cin >> input1;
            cout << sqrt_only.at(input1) << "\n";
        }
    }

    delete[] array;

    return 0;
}