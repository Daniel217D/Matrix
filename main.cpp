#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix{}, inverse{};
    int status;

    matrix.create("./inputs/input_0.txt");
    matrix.print(1);

    status = matrix.inverse_matrix(inverse);
    inverse.print(status);

    matrix.clear();
    if(status != 1) {
        inverse.clear();
    }

    cout << "----------------------\n";

    matrix.create("./inputs/input_1.txt");
    matrix.print(1);

    status = matrix.inverse_matrix(inverse);
    inverse.print(status);

    matrix.clear();
    if(status != 1) {
        inverse.clear();
    }

    cout << "----------------------\n";

    matrix.create("./inputs/input_2.txt");
    matrix.print(1);

    status = matrix.inverse_matrix(inverse);
    inverse.print(status);

    matrix.clear();
    if(status != 1) {
        inverse.clear();
    }

    cout << "----------------------\n";

    matrix.create("./inputs/input_3.txt");
    matrix.print(1);

    status = matrix.inverse_matrix(inverse);
    inverse.print(status);

    matrix.clear();
    if(status != 1) {
        inverse.clear();
    }

    cout << "----------------------\n";

    matrix.create("./inputs/input_hard.txt");
    matrix.print(1);

    status = matrix.inverse_matrix(inverse);
    inverse.print(status);

    matrix.clear();
    if(status != 1) {
        inverse.clear();
    }

    cout << "----------------------\n";

    return 0;
}