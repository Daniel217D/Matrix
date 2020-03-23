#ifndef CPP_MATRIX_H
#define CPP_MATRIX_H
namespace Mtrx {
    struct Matrix {
        /*! Количество строк */
        int rows;
        /*! Количество столбцов */
        int cols;
        /*! Матрица */
        double **matrix;

        /*!
         * @brief Считывание матрицы из файла
         * @param[in] path - путь до файла
         */
        void create(std::string path);

        /*!
         * @brief Инвертирование матрицы и ее передача через переменную inverse
         * @param[out] inverse переменная для инвертированной матрицы
         * @return статус выполнения функции (0 - определитель равен нулю, -1 - матрица неквадратная, 1 - успех)
         */
        int inverse_matrix(Matrix &inverse);

        /*!
         * @brief Печать матрицы в консоль или вывод сообщения об ошибке
         * @param status[in]
         */
        void print(int status);

        /*!
         * @brief Очистка памяти от динамической матрицы
         */
        void clear();
    };

    /*!
     * @bried Создаение пустой матрицы с заданным размером
     * @param rows[in]
     * @param cols[in]
     * @return
     */
    Matrix create_empty(int rows, int cols);

    /*!
     * @brief Создание единичной матрицы с заданным размером
     * @param rows[in]
     * @param cols[in]
     * @return
     */
    Matrix create_identity(int rows, int cols);

    /*!
     * @brief Копирование матрицы
     * @param matrix[in] - указатель на матрицу для копирования
     * @return копия матрицы
     */
    Matrix copy(Matrix *matrix);

    /*!
     * @brief Вывод матрицы в консоль
     * @param matrix[in]
     */
    void print_console(Matrix *matrix);

    /*!
     * @brief Умножение строки матрицы на число
     * @param matrix[in]
     * @param row[in] номер строки
     * @param num[in] число для умножения
     */
    void multiply_row(Matrix *matrix, int row, double num);

    /*!
     * @brief Функция для очистки столбца - под выбранным элементом все элементы матрицы будут равны нулю
     * @param matrix[in] основная матрица
     * @param inverse[in] матрица для инвертирования
     * @param row[in] номер строки элемента
     * @param col[in] номер столбца элемента
     * @param isDown[in] true - очишать столбце под элементом, false - над элементом
     * @return статус
     */
    int clear_col(Matrix *matrix, Matrix *inverse, int row, int col, bool isDown);

    /*!
     * @brief Очистка всех строк матрицы по главной диагонали
     * @param matrix[in]
     * @param inverse[in]
     * @return статус
     */
    int clear_diagonal(Matrix *matrix, Matrix *inverse);
    /*!
     * @brief Сложение строки с нулевым диагональным элементом с другой строки для замены нулевого элемента на ненулевой
     * @param matrix[in/out]
     * @param inverse[out]
     * @param row[in] строка с нулевым диагональным элементом
     * @param col[in] столбец с нулевым диагональным элементом
     * @return статус
     */
    int fix_zero_diagonal(Matrix *matrix, Matrix *inverse, int row, int col);
}
#endif //CPP_MATRIX_H
