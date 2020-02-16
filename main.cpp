#include <iostream>
#include "matrix.h"

using std::cout;
using std::cin;
using namespace Mtrx;


int main() {
    Matrix matrix = create(5,5);
    fill(&matrix);
    print(&matrix);
    clear(&matrix);

    return 0;
}