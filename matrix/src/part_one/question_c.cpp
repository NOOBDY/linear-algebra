#include "questions.h"

#include <iostream>

#include "matrix.h"

namespace PartOne {
void QuestionC() {
    std::cout << "(c)\n";

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

    std::cout << "P equals to Q: "           //
              << (P == Q ? "True" : "False") //
              << "\n\n";
}
} // namespace PartOne