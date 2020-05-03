#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix *matrix = new Matrix("./inputs/input_0.txt"); //Переменная для основной матрицы
    Matrix *inverse = new Matrix; //Переменная для обратной матрицы
    int st; //Переменная для статуса инвертирования

    //matrix->read("./inputs/input_0.txt"); // Считывание матрицы из файла - в данном случае не требуется, так как функция запускается в конструкторе
    //print_console(&matrix); //Вывод матрицы из файла в консоль

    //На основе считанной матрицы, создается обратная матрица.
    //Она помещается в переменную inverse, а результатом функции является статус инвертирования
    st = matrix->inverse(inverse);


    if(st == 1) { //Если инвертирование успешно...
        inverse->print_file("./outputs/output_0.txt"); //Вывод обратной матрицы в файл
        // print_console(inverse); //Печать обратной матрицы в консоль
    } else {
        status(st); //Расшифровка и вывод статуса в консоль
    }

    //Очистка выделенной памяти
    matrix->clear();
    inverse->clear();
    //Возможно удаление через оператор delete
    //delete matrix;
    //delete inverse;

    //file 1

    matrix->read("./inputs/input_1.txt");
    st = matrix->inverse(inverse);


    if(st == 1) {
        inverse->print_file("./outputs/output_1.txt");
    } else {
        status(st);
    }

    matrix->clear();
    inverse->clear();

    //file 2

    matrix->read("./inputs/input_2.txt");
    st = matrix->inverse(inverse);


    if(st == 1) {
        inverse->print_file("./outputs/output_2.txt");
    } else {
        status(st);
    }

    matrix->clear();
    inverse->clear();

    //file 3

    matrix->read("./inputs/input_3.txt");
    st = matrix->inverse(inverse);


    if(st == 1) {
        inverse->print_file("./outputs/output_3.txt");
    } else {
        status(st);
    }

    matrix->clear();
    inverse->clear();

    //file hard

    matrix->read("./inputs/input_hard.txt");
    st = matrix->inverse(inverse);


    if(st == 1) {
        inverse->print_file("./outputs/output_hard.txt");
    } else {
        status(st);
    }

    delete matrix;
    delete inverse;

    return 0;
}