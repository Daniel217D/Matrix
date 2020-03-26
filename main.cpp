#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix{}; //Переменная для основной матрицы
    Matrix inverse{}; //Переменная для обратной матрицы
    int st; //Переменная для статуса инвертирования

    matrix.create("./inputs/input_0.txt"); // Считывание матрицы из файла
    //print_console(&matrix); //Вывод матрицы из файла в консоль

    //На основе считанной матрицы, создается обратная матрица.
    //Она помещается в переменную inverse, а результатом функции является статус инвертирования
    st = matrix.inverse_matrix(inverse);


    if(st == 1) { //Если инвертирование успешно...
        inverse.print_file("./outputs/output_0.txt"); //Вывод обратной матрицы в файл
        //print_console(&inverse); //Печать обратной матрицы в консоль
    } else {
        status(st); //Расшифровка и вывод статуса в консоль
    }

    //Очистка выделенной памяти
    matrix.clear();
    inverse.clear();

    cout << "----------------------\n";

    matrix.create("./inputs/input_1.txt");
    print_console(&matrix);

    st = matrix.inverse_matrix(inverse);

    status(st);
    if(st == 1) {
        inverse.print_file("./outputs/output_1.txt");
        print_console(&inverse);
    }

    matrix.clear();
    inverse.clear();

    cout << "----------------------\n";


    matrix.create("./inputs/input_2.txt");
    print_console(&matrix);

    st = matrix.inverse_matrix(inverse);

    status(st);
    if(st == 1) {
        inverse.print_file("./outputs/output_2.txt");
        print_console(&inverse);
    }

    matrix.clear();
    inverse.clear();

    cout << "----------------------\n";


    matrix.create("./inputs/input_3.txt");
    print_console(&matrix);

    st = matrix.inverse_matrix(inverse);

    status(st);
    if(st == 1) {
        inverse.print_file("./outputs/output_3.txt");
        print_console(&inverse);
    }

    matrix.clear();
    inverse.clear();

    cout << "----------------------\n";

    matrix.create("./inputs/input_hard.txt");
    print_console(&matrix);

    st = matrix.inverse_matrix(inverse);

    status(st);
    if(st == 1) {
        inverse.print_file("./outputs/output_hard.txt");
        print_console(&inverse);
    }

    matrix.clear();
    inverse.clear();

    cout << "----------------------\n";

    return 0;
}