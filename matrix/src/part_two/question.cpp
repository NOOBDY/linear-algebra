#include "questions.h"

#include <iostream>

#include "matrix.h"

namespace PartTwo {
void Question() {
    std::cout << "5\n"   //
              << (T ^ 5) //
              << "\n";

    std::cout << "10\n"   //
              << (T ^ 10) //
              << "\n";

    std::cout << "20\n"   //
              << (T ^ 20) //
              << "\n";

    std::cout << "30\n"   //
              << (T ^ 30) //
              << "\n";
}
} // namespace PartTwo