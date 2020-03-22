#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix{}, inverse{};
    int status;

    matrix.create("./inputs/input_0_0.txt");
    matrix.print(1);
    status = matrix.inverse_matrix(inverse);
    matrix.print(1);
    inverse.print(1);
//    status = inverse.inverse_matrix(reinverse);
//    reinverse.print(1);
    matrix.clear();
    inverse.clear();
//    reinverse.clear();

//    cout << "----------------------\n";

//    matrix.create("./inputs/input_1.txt");
//    matrix.print(1);
//    status = matrix.inverse_matrix(inverse);
//    inverse.print(status);
//    matrix.clear();
////    inverse.clear();
//    cout << "----------------------\n";
//
//    matrix.create("./inputs/input_2.txt");
//    matrix.print(1);
//    status = matrix.inverse_matrix(inverse);
//    inverse.print(status);
//    matrix.clear();
////    inverse.clear();
//    cout << "----------------------\n";
//
//    matrix.create("./inputs/input_hard.txt");
//    matrix.print(1);
//    status = matrix.inverse_matrix(inverse);
//    inverse.print(status);
//    matrix.clear();
////    inverse.clear();
//    cout << "----------------------\n";

    return 0;
}