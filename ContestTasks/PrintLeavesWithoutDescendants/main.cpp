#include <iostream>
#include <memory>

using std::cin;
using std::cout;

class Tree {
public:
    Tree() {
    }

    ~Tree() {
    }

    void insert(int value) {
        if (size_ == 0) {
            data_ = value;
            ++size_;
            return;
        }

        if (value > data_) {
            if (right_ == nullptr) {
                right_ = std::shared_ptr<Tree>(new Tree());
            }
            right_->insert(value);
        } else if (value < data_) {
            if (left_ == nullptr) {
                left_ = std::shared_ptr<Tree>(new Tree());
            }
            left_->insert(value);
        }
    }

    void print() {
        if (left_ == nullptr && right_ == nullptr) {
            cout << data_ << "\n";
            return;
        }

        if (left_ != nullptr) {
            left_->print();
        }

        if (right_ != nullptr) {
            right_->print();
        }
    }

private:
    int data_;
    int size_ = 0;

    std::shared_ptr<Tree> left_ = nullptr;
    std::shared_ptr<Tree> right_ = nullptr;
};

#include <fstream>
std::ifstream f_in("../input.txt");
// #include <ctime>
// #include <random>
// #include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //    while (true) {
    //        std::clock_t c_start = std::clock();
    //        std::random_device dev;
    //        std::mt19937 rng(dev());
    //        std::uniform_int_distribution<std::mt19937::result_type> size(0, 5 * pow(10, 5));
    //        std::uniform_int_distribution<std::mt19937::result_type> num_range(1, pow(10, 9));

    std::shared_ptr<Tree> tree(new Tree());
    int input;
    f_in >> input;
    int count = 0;

    while (input != 0) {
        ++count;
        tree->insert(input);
        f_in >> input;
    }

    if (count >= 0) {
        tree->print();
    }

    //        std::clock_t c_end = std::clock();
    //        long double time_elapsed_ms = 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC;
    //        if (time_elapsed_ms / 1000.0 > 1) {
    //            std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";
    //            std::cout << "CPU time used: " << time_elapsed_ms / 1000.0 << " s\n";
    //            return 0;
    //        }
    //    }
    return 0;
}