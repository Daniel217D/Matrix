#include <iostream>
#include "matrix.h"
#include <fstream>

using std::cout;
using std::cin;

using namespace Mtrx;


int main() {
    Matrix matrix = create();
    print(&matrix);
    clear_diagonal(&matrix, true);
    print(&matrix);
    clear_diagonal(&matrix, false);
    print(&matrix);

    clear(&matrix);

    return 0;
}