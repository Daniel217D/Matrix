#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix = create("./input.txt");
    print(&matrix);

    print(inverse_matrix(matrix), &matrix);

    clear(&matrix);

    return 0;
}