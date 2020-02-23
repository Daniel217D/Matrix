#include <iostream>
#include <fstream>
#include <iostream>
#include "matrix.h"

namespace Mtrx {
    Matrix create(std::string path) {
        Matrix matrix{};
        std::ifstream in(path);

        if(!in.is_open()) {
            std::cout << "file isn't found";
            return matrix;
        }

        int temp, count_symbols = 0, count_space = 0;
        char symbol = ' ';

        while (!in.eof())
        {
            in >> temp;
            count_symbols++;
        }

        in.seekg(0, std::ios::beg);
        in.clear();

        while (!in.eof() && symbol != '\n')
        {
            in.get(symbol);
            if (symbol == ' ') count_space++;
        }

        in.seekg(0, std::ios::beg);
        in.clear();

        int cols = count_space + 1;//число столбцов на единицу больше числа пробелов
        int rows = count_symbols / (cols);//число строк

        matrix.rows = rows;
        matrix.cols = cols;
        matrix.matrix = new double *[matrix.rows];

        for (int i = 0; i < matrix.rows; ++i)
            matrix.matrix[i] = new double[matrix.cols];

        for (int i = 0; i < matrix.rows; ++i) {
            for (int j = 0; j < matrix.cols; ++j) {
                in >> matrix.matrix[i][j];
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

    void multiply_row(Matrix *matrix, int row, double num) {
        for (int i = 0; i < matrix->cols; ++i) {
            matrix->matrix[row][i] *= num;
        }
    }

    void clear_col(Matrix *matrix, int row, int col, bool isDown) {
        double factor = matrix->matrix[row][col];
        if (factor == 0)
            return;

        if(isDown) {
            for (int i = row + 1; i < matrix->rows; ++i) {
                double devider = matrix->matrix[i][col];
                multiply_row(matrix, i, factor);

                for (int j = 0; j < matrix->cols; ++j) {
                    matrix->matrix[i][j] -= devider * matrix->matrix[row][j];
                }
            }
        } else {
            for (int i = row - 1; i >= 0; --i) {
                double devider = matrix->matrix[i][col];
                multiply_row(matrix, i, factor);

                for (int j = matrix->cols; j >= 0 ; --j) {
                    matrix->matrix[i][j] -= devider * matrix->matrix[row][j];
                }
            }
        }
    }

    void clear_diagonal(Matrix *matrix, bool isDown) {
        if(isDown) {
            for (int i = 0; i < std::min(matrix->cols, matrix->rows) - 1; ++i) {
                clear_col(matrix, i, i, isDown);
            }
        } else {
            for (int i = std::min(matrix->cols, matrix->rows) - 1; i > 0; --i) {
                clear_col(matrix, i, i, isDown);
            }
        }
    }
}