#ifndef CPP_MATRIX_H
#define CPP_MATRIX_H
namespace Mtrx {
    struct Matrix {
        double **matrix;
        int rows;
        int cols;
    };

    Matrix create(std::string path);

    void print(Matrix *matrix);

    void clear(Matrix *matrix);

    bool check_square(Matrix *matrix);

    void multiply_row(Matrix* matrix, int row, double num);

    void clear_col(Matrix *matrix, int row, int col, bool isDpwn);

    void clear_diagonal(Matrix *matrix, bool isDown);

    //bool inverse_matrix(Matrix *matrix);
}
#endif //CPP_MATRIX_H
