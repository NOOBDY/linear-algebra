#include "questions.h"

#include <iostream>

#include "matrix.h"

namespace PartOne {
void QuestionB() {
    std::cout << "(b)\n";

    Matrix<2, 2, double> M = A * B;
    Matrix<2, 2, double> N = B * A;

    std::cout << "A\n" //
              << M     //
              << "\n";

    std::cout << "B\n" //
              << N     //
              << "\n";

    std::cout << "M equals to N: "           //
              << (M == N ? "True" : "False") //
              << "\n\n";
}
} // namespace PartOne