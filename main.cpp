#include <iostream>
#include "matrix.h"

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
            break;
    }

    clear(&matrix);

    return 0;
}