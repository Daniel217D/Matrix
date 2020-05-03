#include <iostream>
#include <fstream>
#include "matrix.h"

namespace Mtrx {
    int Matrix::getRows() {
        return rows;
    }

    int Matrix::getCols() {
        return cols;
    }

    double Matrix::getEl(int row, int col) {
        return matrix[row][col];
    }

    void Matrix::setEl(int row, int col, double val) {
        matrix[row][col] = val;
    }

    Matrix::Matrix() : rows(0), cols(0) {}

    Matrix::Matrix(int r, int c) {
        rows = r;
        cols = c;
        matrix = new double *[getRows()];

        for (int i = 0; i < getRows(); ++i)
            matrix[i] = new double[getCols()];
    }

    Matrix::Matrix(const std::string &path) {
        read(path);
    }

    Matrix::~Matrix() {
        clear();
    }

    void Matrix::read(const std::string &path) {
        std::ifstream in(path);

        if (!in.is_open()) {
            std::cout << "file isn't found";
            return;
        }

        double temp;
        int count_symbols = 0, count_space = 0;
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

        clear();

        cols = count_space + 1;//число столбцов на единицу больше числа пробелов
        rows = count_symbols / cols;//число строк
        matrix = new double *[rows];

        for (int i = 0; i < rows; ++i) {
            matrix[i] = new double[cols];
            for (int j = 0; j < cols; ++j) {
                in >> matrix[i][j];
            }
        }
    }

    int Matrix::inverse(Matrix *&inverse) {
        int status;

        Matrix *matrix_copy = copy(this);

        if (matrix_copy->getRows() != matrix_copy->getCols()) {
            return -1;
        }

        inverse->clear();

        inverse = create_identity(matrix_copy->getRows(), matrix_copy->getCols());
        status = clear_diagonal(matrix_copy, inverse);
        if (status != 1) {
            return status;
        }

        for (int i = 0; i < matrix_copy->getCols(); ++i) {
            if (matrix_copy->getEl(i, i) == 0) {
                return 0;
            }
            multiply_row(inverse, i, 1 / matrix_copy->getEl(i, i));
        }

        return 1;
    }

    void Matrix::print_file(const std::string &path) {
        std::ofstream fout;
        fout.open(path);
        for (int i = 0; i < getRows(); ++i) {
            for (int j = 0; j < getCols(); ++j) {
                fout << matrix[i][j] << " ";
            }
            fout << "\n";
        }
        fout.close();
    }

    void Matrix::clear() {
        if (getCols() == 0 && getRows() == 0)
            return;

        for (int i = 0; i < getRows(); ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;

        rows = 0;
        cols = 0;
    }

    Matrix* create_identity(int rows, int cols) {
        Matrix *matrix = new Matrix(rows, cols);

        for (int i = 0; i < matrix->getCols(); ++i) {
            for (int j = 0; j < matrix->getRows(); ++j) {
                matrix->setEl(i, j, i == j ? 1 : 0);
            }
        }

        return matrix;
    }

    Matrix *copy(Matrix *matrix) {
        Matrix *copy = new Matrix(matrix->getRows(), matrix->getCols());

        for (int i = 0; i < matrix->getRows(); ++i) {
            for (int j = 0; j < matrix->getCols(); ++j)
                copy->setEl(i, j, matrix->getEl(i, j));
        }

        return copy;
    }

    void print_console(Matrix *matrix) {
        for (int i = 0; i < matrix->getRows(); ++i) {
            for (int j = 0; j < matrix->getCols(); ++j) {
                std::cout << matrix->getEl(i, j) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void status(int status) {
        switch (status) {
            case 1:
                std::cout << "No errors \n";
                break;
            case -1:
                std::cout << "Matrix is not square \n";
                break;
            case 0:
                std::cout << "Matrix's determinant is null \n";
                break;
            default:
                std:: cout << "Unknown status \n";
        }
    }

    void multiply_row(Matrix *matrix, int row, double num) {
        for (int i = 0; i < matrix->getCols(); ++i) {
            matrix->setEl(row, i, matrix->getEl(row, i) * num);
        }
    }

    int clear_col(Matrix *matrix, Matrix *inverse, int row, int col, bool isDown) {
        double factor = matrix->getEl(row, col);

        if (factor == 0) {
            int status = fix_zero_diagonal(matrix, inverse, row, col);
            if (status != 1)
                return status;

            factor = matrix->getEl(row, col);
        }

        if (isDown) {
            for (int i = row + 1; i < matrix->getRows(); ++i) {
                double devider = matrix->getEl(i, col);
                multiply_row(matrix, i, factor);
                multiply_row(inverse, i, factor);

                for (int j = 0; j < matrix->getCols(); ++j) {
                    matrix->setEl(i, j, matrix->getEl(i, j) - devider * matrix->getEl(row, j));
                    inverse->setEl(i, j, inverse->getEl(i, j) - devider * inverse->getEl(row, j));
                }
            }
        } else {
            for (int i = row - 1; i >= 0; --i) {
                double devider = matrix->getEl(i, col);
                multiply_row(matrix, i, factor);
                multiply_row(inverse, i, factor);

                for (int j = matrix->getCols() - 1; j >= 0; --j) {
                    matrix->setEl(i, j, matrix->getEl(i, j) - devider * matrix->getEl(row, j));
                    inverse->setEl(i, j, inverse->getEl(i, j) - devider * inverse->getEl(row, j));
                }
            }
        }

        return 1;
    }

    int clear_diagonal(Matrix *matrix, Matrix *inverse) {
        int status;
        for (int i = 0; i < std::min(matrix->getCols(), matrix->getRows()) - 1; ++i) {
            status = clear_col(matrix, inverse, i, i, true);
            if (status != 1) {
                return status;
            }
        }
        for (int i = std::min(matrix->getCols(), matrix->getRows()) - 1; i > 0; --i) {
            status = clear_col(matrix, inverse, i, i, false);
            if (status != 1) {
                return status;
            }
        }
        return 1;
    }

    int fix_zero_diagonal(Matrix *matrix, Matrix *inverse, int row, int col) {
        int row_not_zero = -1;

        for (int i = 0; i < matrix->getRows() && row_not_zero == -1; ++i) {
            if (matrix->getEl(i, col) != 0) {
                row_not_zero = i;
            }
        }

        if (row_not_zero == -1) {
            return 0;
        }

        for (int i = 0; i < matrix->getCols(); ++i) {
            matrix->setEl(row, i, matrix->getEl(row, i) + matrix->getEl(row_not_zero, i));
            inverse->setEl(row, i, inverse->getEl(row, i) + inverse->getEl(row_not_zero, i));
        }

        return 1;
    }
}