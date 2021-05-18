#include "ArraySequence.h"

#ifndef LABORATORY2_SQUAREMATRIX_H
#define LABORATORY2_SQUAREMATRIX_H

template <typename T> class SquareMatrix {
private:
    int size;
    ArraySequence<T>* array_sequence;
public:

    //Constructor
    SquareMatrix() {
        array_sequence = new ArraySequence<T>;
        size = 0;
    }

    SquareMatrix(int size_m) {
        array_sequence = new ArraySequence<T>(size_m * size_m);
        size = size_m;
    }

    SquareMatrix(T *array, int size_m) {
        array_sequence = new ArraySequence<T>(array, size_m * size_m);
        size = size_m;
    }

    SquareMatrix(const ArraySequence<T> arraySequence, int size_m) {
        size = size_m;
        array_sequence = arraySequence;
    }

    //Destructor
    ~SquareMatrix() = default;


    //Decomposition
    int GetSize() {
        return size;
    }

    T Get(int row, int col) {
        if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
            throw out_of_range("Index out of range!");
        return array_sequence->Get(row * size + col);
    }

    //Operations
    void Append(T item) {
        return array_sequence->Append(item);
    };

    void Set(T item, int row, int col) {
            if (row < 0 || col < 0 || col >= this->GetSize() || row >= this->GetSize())
                throw out_of_range("Index out of range!");
            return array_sequence->Set(row * size + col, item);

        };

    template<typename U> U MatrixNorm() {
            U sum = 0;
            for (int i = 0; i < this->GetSize(); i++)
                for (int j = 0; j < this->GetSize(); j++)
                    sum = sum + this->Get(i, j) * this->Get(i, j);
            return sqrt(sum);
        }

        SquareMatrix<T> *SumOfMatrix(SquareMatrix<T> *matrix) {
            if (size != matrix->size) {
                throw length_error("Different size!");
            }
            T *new_array = new T[size * size];
            for (int i = 0; i < size * size; i++) {
                new_array[i] = array_sequence->Get(i) + matrix->array_sequence->Get(i);
            }
            auto *newArray = new SquareMatrix<T>(new_array, size);
            return newArray;
        }

        SquareMatrix<T> *MultiplyOnScalar(float scalar) {
            T *new_array = new T[size*size];
            for (int i = 0; i < size*size; ++i) {
                new_array[i] = array_sequence->Get(i) * scalar;
            }
            auto *newArray = new SquareMatrix<T>(new_array, size);
            return newArray;
        }

        SquareMatrix<T> *MultiplyMatrix(SquareMatrix<T> *matrix) {
            if (size != matrix->size)
                throw length_error("Different size!");
            T *a = new T[size * size];
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j) {
                    a[i * size + j] = 0;
                    for (int k = 0; k < size; ++k) {
                        a[i * size + j] = a[i * size + j] +
                                          array_sequence->Get(i * size + k) * matrix->array_sequence->Get(k * size + j);
                    }
                }
            }
            auto *newArray = new SquareMatrix<T>(a, size);
            return newArray;
        }



        void MultiplyRow(SquareMatrix<T> *matrix, int row, T scalar) {
            if (row < 1 || row > size)
                throw out_of_range("Index out of range!");
            for (int i = 0; i < size; i++) {
                matrix->Set(array_sequence->Get((row - 1) * size + i) * scalar, row - 1, i);
            }
        }

    void AddRowToRow(SquareMatrix<T> *matrix, int first, int second) {

        if (first < 1 || first > size || second < 1 || second > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; ++i) {
            matrix->Set(matrix->array_sequence->Get((first - 1) * size + i) + matrix->array_sequence->Get((second - 1) * size + i), first-1, i);
        }
    }

    void MultiplyCol(SquareMatrix<T> *matrix, int col, T scalar) {
        if (col < 1 || col > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; i++) {
            matrix->Set(array_sequence->Get(i * size + col - 1) * scalar, i, col - 1);
        }
    }

    void AddColToCol(SquareMatrix<T> *matrix, int first, int second) {

        if (first < 1 || first > size || second < 1 || second > size)
            throw out_of_range("Index out of range!");
        for (int i = 0; i < size; ++i) {
            matrix->Set(matrix->array_sequence->Get(i * size + first - 1) + matrix->array_sequence->Get(i * size + second - 1), i, first - 1);
        }
    }

    SquareMatrix<complex> *MultiplyMatrixComplex(SquareMatrix<complex> *matrix) {
        if (size != matrix->size)
            throw length_error("Different size!");
        T *a = new T[size * size];
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                a[i * size + j] = complex(0,0);
                for (int k = 0; k < size; ++k) {
                    a[i * size + j] = a[i * size + j] +
                                      array_sequence->Get(i * size + k) * matrix->array_sequence->Get(k * size + j);
                }
            }
        }
        auto *newArray = new SquareMatrix<T>(a, size);
        return newArray;
    }
    };

template<>
template<> inline
complex SquareMatrix<complex>::MatrixNorm<complex>() {
    complex sum = complex(0,0);
    for (int i = 0; i<this->GetSize(); i++) {
        for (int j = 0; j < this->GetSize(); j++)
            sum = sum + ((this->Get(i,j))*(this->Get(i,j)));
    }
    return sum.sqrt_complex();
}
#endif //LABORATORY2_SQUAREMATRIX_H
