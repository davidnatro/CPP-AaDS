#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
private:
    class Iterator {
    private:
        vector<T> matrix;
        size_t current;

    public:
        Iterator(const vector<vector<T>>& matrix, size_t current) {
            this->current = current;
            for (auto const& row : matrix) {
                for (auto const& el : row) {
                    this->matrix.push_back(el);
                }
            }
        }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            operator++();
            return old;
        }

        T& operator*() {
            return matrix[current];
            /*return thisMatrix.matrix[currentRow][current];*/
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    vector<vector<T>> matrix;
    using iterator = Iterator;

public:
    Matrix(const vector<vector<T>>& matrix) {
        this->matrix = matrix;
    }


    pair<size_t, size_t> size() const {
        pair<size_t, size_t> s(matrix.size(), matrix[0].size());
        return s;
    }

    Matrix<T>& transpose() {
        pair<size_t, size_t> sizes = size();
        Matrix<T> old(matrix);
        matrix.resize(sizes.second);
        for (size_t i = 0; i < sizes.second; ++i) {
            matrix[i].resize(sizes.first);
            for (size_t j = 0; j < sizes.first; ++j) {
                matrix[i][j] = old.matrix[j][i];
            }
        }

        return *this;
    }

    Matrix<T> transposed() const {
        Matrix cop(*this);
        cop.transpose();
        return cop;
    }

    Matrix<T>& operator*=(const Matrix<T>& other) {
        pair<size_t, size_t> thSize = size();
        pair<size_t, size_t> otherSize = other.size();

        Matrix<T> cop(*this);

        for (size_t i = 0; i < thSize.first; ++i) {
            matrix[i].resize(otherSize.second);
        }

        for (size_t i = 0; i < thSize.first; ++i) {
            for (size_t j = 0; j < otherSize.second; ++j) {
                T sum = 0;
                for (size_t k = 0; k < thSize.second; ++k) {
                    sum += cop.matrix[i][k] * other.matrix[k][j];
                }
                matrix[i][j] = sum;
            }
        }
        return *this;
    }

    Matrix<T> operator*(const Matrix<T>& other) const {
        Matrix<T> th(*this);
        th *= other;
        return th;
    }

    Matrix<T>& operator*=(const T& other) {
        pair<size_t, size_t> sizes = size();
        for (size_t i = 0; i < sizes.first; ++i) {
            for (size_t j = 0; j < sizes.second; ++j) {
                matrix[i][j] *= other;
            }
        }
        return *this;
    }

    Matrix<T> operator*(const T& other) const {
        Matrix th = *this;
        th *= other;
        return th;
    }

    Matrix<T>& operator+=(const Matrix<T>& other) {
        pair<size_t, size_t> sizes = size();
        for (size_t i = 0; i < sizes.first; ++i) {
            for (size_t j = 0; j < sizes.second; ++j) {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& other) const {
        Matrix<T> th = *this;
        th += other;
        return th;
    }

    iterator begin() {
        return iterator(matrix, 0);
    }

    iterator end() {
        return iterator(matrix, matrix.size() * matrix[0].size());
    }

    iterator begin() const {
        return iterator(matrix, 0);
    }

    iterator end() const {
        return iterator(matrix, matrix.size() * matrix[0].size());
    }

    friend ostream& operator<<(ostream& out, const Matrix& a) {
        size_t cols = a.size().first;
        for (size_t i = 0; i < cols; ++i) {
            size_t rows = a.size().second;
            for (size_t j = 0; j < rows; ++j) {
                out << a.matrix[i][j];
                if (j != rows - 1) { out << "\t"; }
            }
            if (i != cols - 1) { out << "\n"; }
        }
        return out;
    }
};

int main() {
    vector<vector<int>> v0 {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    vector<vector<int>> v1 {{1, 1, 1, 1}, {2, 2, 2, 2}};
    vector<vector<int>> v2 {{1, 1, 1}, {2, 2, 2}, {3,3,3}};
    Matrix<int> m0(v0);
    Matrix<int> m1(v1);
    Matrix<int> m2(v2);
    cout << endl << "------------------" << endl;
    cout << "transpose m0(4x2) and then add to m1(2x4)" << "\n";
    cout << m0.transposed() + m1 << "\n";
    cout << endl << "------------------" << endl;
    cout << m1 << "\n";
    cout << "transpose m1 by ref" << "\n";
    m1.transpose();
    cout << m1 << "\n";
    cout << endl << "------------------" << endl;
    cout << "multiply m0(4x2) by m1(2x4)(transposed back for a while(not by ref))" << "\n";
    m0 *= m1.transposed();
    cout << m0 << "\n";
    cout << endl << "------------------" << endl;
}