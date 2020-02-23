#include <iostream>
#include "matrix.h"
#include <fstream>

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix = create("./input.txt");
    print(&matrix);

    switch (inverse_matrix(matrix)) {
        case 0:
            print(&matrix);
            break;
        case 1:
            cout << "Matrix is not square";
            break;
        case 2:
            cout << "Matrix's determinant is null";
    }

    clear(&matrix);

    return 0;
}