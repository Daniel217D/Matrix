#include <iostream>
#include "matrix.h"
#include <fstream>

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix = create("./input.txt");
    print(&matrix);

    if(inverse_matrix(matrix)) {
        print(&matrix);
    };

    clear(&matrix);

    return 0;
}