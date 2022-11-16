#include "questions.h"

#include <iostream>

#include "matrix.h"

namespace PartOne {
void QuestionC() {
    Matrix<3, 2, double> P;
    Matrix<3, 2, double> Q;

    P = Transpose(C) * Transpose(B);
    Q = Transpose(B * C);

    std::cout << "P\n" //
              << P     //
              << "\n";

    std::cout << "Q\n" //
              << Q     //
              << "\n";
}
} // namespace PartOne