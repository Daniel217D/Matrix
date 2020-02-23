#include <iostream>
#include <fstream>
#include <iostream>
#include "matrix.h"

namespace Mtrx {
    Matrix create(std::string path) {
        Matrix matrix{};
        std::ifstream in(path);

        if (!in.is_open()) {
            std::cout << "file isn't found";
            return matrix;
        }

        int temp, count_symbols = 0, count_space = 0;
        char symbol = ' ';

        while (!in.eof()) {
            in >> temp;
            count_symbols++;
        }

        in.seekg(0, std::ios::beg);
        in.clear();

        while (!in.eof() && symbol != '\n') {
            in.get(symbol);
            if (symbol == ' ') count_space++;
        }

        in.seekg(0, std::ios::beg);
        in.clear();

        int cols = count_space + 1;//число столбцов на единицу больше числа пробелов
        int rows = count_symbols / cols;//число строк

        matrix = create(rows, cols);

        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                in >> matrix.matrix[i][j];
            }
        }

        return matrix;
    }

    Matrix create(int rows, int cols) {
        Matrix matrix{};
        matrix.rows = rows;
        matrix.cols = cols;
        matrix.matrix = new double *[matrix.rows];

        for (int i = 0; i < matrix.rows; ++i)
            matrix.matrix[i] = new double[matrix.cols];

        return matrix;
    }

    Matrix create_identity(int rows, int cols) {
        Matrix matrix = create(rows, cols);

        for (int i = 0; i < matrix.cols; ++i) {
            for (int j = 0; j < matrix.rows; ++j) {
                matrix.matrix[i][j] = i == j ? 1 : 0;
            }
        }

        return matrix;
    }

    void print(Matrix *matrix) {
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

    bool check_square(Matrix *matrix) {
        return matrix->rows == matrix->cols;
    }

    void multiply_row(Matrix *matrix, int row, double num) {
        for (int i = 0; i < matrix->cols; ++i) {
            matrix->matrix[row][i] *= num;
        }
    }

    void clear_col(Matrix *matrix, Matrix *inverse, int row, int col, bool isDown) {
        double factor = matrix->matrix[row][col];

        if (factor == 0)
            return;

        if (isDown) {
            for (int i = row + 1; i < matrix->rows; ++i) {
                double devider = matrix->matrix[i][col];
                multiply_row(matrix, i, factor);
                multiply_row(inverse, i, factor);

                for (int j = 0; j < matrix->cols; ++j) {
                    matrix->matrix[i][j] -= devider * matrix->matrix[row][j];
                    inverse->matrix[i][j] -= devider * inverse->matrix[row][j];
                }
            }
        } else {
            for (int i = row - 1; i >= 0; --i) {
                double devider = matrix->matrix[i][col];
                multiply_row(matrix, i, factor);
                multiply_row(inverse, i, factor);

                for (int j = matrix->cols; j >= 0; --j) {
                    matrix->matrix[i][j] -= devider * matrix->matrix[row][j];
                    inverse->matrix[i][j] -= devider * inverse->matrix[row][j];
                }
            }
        }
    }

    void clear_diagonal(Matrix *matrix, Matrix *inverse) {
        for (int i = 0; i < std::min(matrix->cols, matrix->rows) - 1; ++i) {
            clear_col(matrix, inverse, i, i, true);
        }
        for (int i = std::min(matrix->cols, matrix->rows) - 1; i > 0; --i) {
            clear_col(matrix, inverse, i, i, false);
        }
    }

    bool inverse_matrix(Matrix &matrix) {
        if (!check_square(&matrix)) {
            return false;
        }

        Matrix inverse = create_identity(matrix.rows, matrix.cols);
        clear_diagonal(&matrix, &inverse);

        for (int i = 0; i < matrix.cols; ++i) {
            multiply_row(&inverse, i, 1 / matrix.matrix[i][i]);
        }

        matrix = inverse;
        return true;
    }
}