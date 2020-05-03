#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include <cmath>

#include "matrix.h"

using namespace Mtrx;

const double EPS = 1e-7;

TEST_CASE("Matrix::create", "[Matrix]") {
    Matrix *matrix = new Matrix;

    SECTION("input_0.txt") {
        matrix->read("./inputs/input_0.txt");
        REQUIRE(matrix->getCols() == 3);
        REQUIRE(matrix->getRows() == 3);
    }
    matrix->clear();

    SECTION("input_1.txt") {
        matrix->read("./inputs/input_1.txt");
        REQUIRE(matrix->getCols() == 3);
        REQUIRE(matrix->getRows() == 2);
    }
    matrix->clear();

    SECTION("input_2.txt") {
        matrix->read("./inputs/input_2.txt");
        REQUIRE(matrix->getCols() == 3);
        REQUIRE(matrix->getRows() == 3);
    }
    matrix->clear();

    SECTION("input_3.txt") {
        matrix->read("./inputs/input_3.txt");
        REQUIRE(matrix->getCols() == 3);
        REQUIRE(matrix->getRows() == 3);
    }
    matrix->clear();

    SECTION("input_hard.txt") {
        matrix->read("./inputs/input_hard.txt");
        REQUIRE(matrix->getCols() == 5);
        REQUIRE(matrix->getRows() == 5);
    }
    matrix->clear();
}

TEST_CASE("Matrix::inverse", "[Matrix]") {
    SECTION("input_0.txt") {
        Matrix *matrix = new Matrix, *inverse = new Matrix;
        matrix->read("./inputs/input_0.txt");
        int status = matrix->inverse(inverse);

        REQUIRE(status == 1);

        double expectation[3][3] = {{0,  1. / 2,  -1. / 2},
                                    {2,  -1. / 4, -5. / 4},
                                    {-1, 0,       1}};
        bool noError = true;

        REQUIRE(inverse->getCols() == 3);
        REQUIRE(inverse->getRows() == 3);

        for (int i = 0; i < inverse->getRows() && noError; ++i) {
            for (int j = 0; j < inverse->getCols() && noError; ++j) {
                if (std::abs(inverse->getEl(i, j) - expectation[i][j]) > EPS) {
                    noError = false;
                }
            }
        }

        REQUIRE(noError);
    }

    SECTION("input_1.txt") {
        Matrix *matrix = new Matrix, *inverse = new Matrix;
        matrix->read("./inputs/input_1.txt");
        int status = matrix->inverse(inverse);

        REQUIRE(status == -1);
    }

    SECTION("input_2.txt") {
        Matrix *matrix = new Matrix, *inverse = new Matrix;
        matrix->read("./inputs/input_2.txt");
        int status = matrix->inverse(inverse);

        REQUIRE(status == 0);
    }

    SECTION("input_3.txt") {
        Matrix *matrix = new Matrix, *inverse = new Matrix;
        matrix->read("./inputs/input_3.txt");
        int status = matrix->inverse(inverse);

        REQUIRE(status == 0);
    }

    SECTION("input_hard.txt") {
        Matrix *matrix = new Matrix, *inverse = new Matrix;
        matrix->read("./inputs/input_hard.txt");
        int status = matrix->inverse(inverse);

        REQUIRE(status == 1);

        double expectation[5][5] = {{(-459377.)/43374293, (-616773.)/43374293, 422137./43374293, 3542941./43374293, (-1227648.)/43374293},
                                    {1582155./43374293, 1609754./43374293, (-926372.)/43374293, (-4350593.)/43374293, (-241086.)/43374293},
                                    {585703./43374293, 1860313./43374293, (-723946.)/43374293, (-4238313.)/43374293, 530214./43374293},
                                    {(-3442248.)/43374293, (-4982441.)/43374293, 3748034./43374293, 10697391./43374293, 697483./43374293},
                                    {2557937./43374293, 3055832./43374293, (-2838064.)/43374293, (-7264839.)/43374293, 260201./43374293}};
        bool noError = true;

        REQUIRE(inverse->getCols() == 5);
        REQUIRE(inverse->getRows() == 5);

        for (int i = 0; i < inverse->getRows() && noError; ++i) {
            for (int j = 0; j < inverse->getCols() && noError; ++j) {
                if (std::abs(inverse->getEl(i, j) - expectation[i][j]) > EPS) {
                    noError = false;
                }
            }
        }

        REQUIRE(noError);
    }
}