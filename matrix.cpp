#include <iostream>
#include "matrix.h"

namespace Mtrx {
    Matrix *create(int rows, int cols) {
        Matrix *matrix, m;
        matrix = &m;

        matrix->rows = rows;
        matrix->cols = cols;
        matrix->matrix = new double *[matrix->rows];

        for (int i = 0; i < matrix->rows; ++i)
            matrix->matrix[i] = new double[matrix->cols];

        return matrix;
    }

    void fill(Matrix *matrix) { //ToDo read file
        for (int i = 0; i < matrix->rows; ++i) {
            for (int j = 0; j < matrix->cols; ++j) {
                matrix->matrix[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    }

    void print(Matrix *matrix) {
        std::cout << "%" << matrix->rows << "%";
        for (int i = 0; i < matrix->rows; ++i) {
            for (int j = 0; j < matrix->cols; ++j) {
                std::cout << matrix->matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void clear(Matrix *matrix) {
        for (int i = 0; i < matrix->rows; ++i)
            delete[] matrix->matrix[i];
        delete[] matrix->matrix;
    }

    void multiply_row(Matrix *matrix, int row, double num) {
        for (int i = 0; i < matrix->cols; ++i) {
            matrix->matrix[row][i] *= num;
            std::cout << i;
        }
    }

    void clear_col(Matrix *matrix, int row, int col) {
        std::cout << "%";
        Matrix *mp = create(6, 6);
        print(mp);
        std::cout << "%";
//        double factor = matrix->matrix[row][col], devider = matrix->matrix[row + 1][col];
//        multiply_row(matrix, row + 1, factor);
//        for (int i = 0; i < matrix->cols; ++i) {
//            matrix->matrix[row + 1][i] -= devider*factor;
//        }
    }

    void test_function(Matrix *matrix) {
        std::cout << "%" << matrix->rows << "%";
    }
}