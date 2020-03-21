#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix{}, inverse{};

    matrix = create("./inputs/input_0.txt");
    print(&matrix);
    int status = inverse_matrix(matrix, inverse);
    print(status, &inverse);
    clear(&matrix);
    cout << "----------------------\n";

    matrix = create("./inputs/input_1.txt");
    print(&matrix);
    print(inverse_matrix(matrix, inverse), &inverse);
    clear(&matrix);
    cout << "----------------------\n";

    matrix = create("./inputs/input_2.txt");
    print(&matrix);
    print(inverse_matrix(matrix, inverse), &inverse);
    clear(&matrix);
    cout << "----------------------\n";

    matrix = create("./inputs/input_hard.txt");
    print(&matrix);
    print(inverse_matrix(matrix, inverse), &inverse);
    clear(&matrix);

    return 0;
}