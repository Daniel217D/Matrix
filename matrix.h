#ifndef CPP_MATRIX_H
#define CPP_MATRIX_H
namespace Mtrx {
    struct Matrix {
        double **matrix;
        int rows;
        int cols;
    };

    Matrix create(std::string path);

    Matrix create(int rows, int cols);

    Matrix create_identity(int rows, int cols);

    void print(Matrix *matrix);

    void print(int status, Matrix *matrix);

    void clear(Matrix *matrix);

    void multiply_row(Matrix* matrix, int row, double num);

    void clear_col(Matrix *matrix, Matrix *inverse, int row, int col, bool isDpwn);

    void clear_diagonal(Matrix *matrix, Matrix *inverse);

    int inverse_matrix(Matrix &matrix_original, Matrix &inverse);
}
#endif //CPP_MATRIX_H
