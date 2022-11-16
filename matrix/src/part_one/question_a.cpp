#include "questions.h"

#include <iostream>

#include "matrix.h"

namespace PartOne {
void QuestionA() {
    std::cout << "(a)\n";

    std::cout << "A + 2B\n" //
              << A + 2 * B  //
              << "\n";

    std::cout << "C - B * E^T\n"      //
              << C - B * Transpose(E) //
              << "\n";

    std::cout << "A^T\n"      //
              << Transpose(A) //
              << "\n";
}
} // namespace PartOne