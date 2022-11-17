#include "questions.h"

#include <iostream>

#include "matrix.h"

namespace PartOne {
void QuestionD() {
    std::cout << "(d)\n";

    std::cout << "A^-1"    //
              << Invert(A) //
              << "\n";
}
} // namespace PartOne