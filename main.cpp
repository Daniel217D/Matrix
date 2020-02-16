#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;
using namespace Mtrx;


int main() {
    Matrix* matrix = create(5,5);
    fill(matrix);
    print(matrix);
    test_function(matrix);
    clear_col(matrix, 0, 0);
    print(matrix);

    clear(matrix);
    cout << "!";
    return 0;
}