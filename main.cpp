#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix{};
    matrix = create("./inputs/input_0.txt");
    print(&matrix);
    print(inverse_matrix(matrix), &matrix);
    clear(&matrix);

    matrix = create("./inputs/input_1.txt");
    print(&matrix);
    print(inverse_matrix(matrix), &matrix);
    clear(&matrix);

    matrix = create("./inputs/input_2.txt");
    print(&matrix);
    print(inverse_matrix(matrix), &matrix);
    clear(&matrix);

    matrix = create("./inputs/input_hard.txt");
    print(&matrix);
    print(inverse_matrix(matrix), &matrix);
    clear(&matrix);

    return 0;
}