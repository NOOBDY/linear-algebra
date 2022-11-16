#ifndef PART_ONE_QUESTIONS_H
#define PART_ONE_QUESTIONS_H

#include <cmath>

#include "matrix.h"

namespace PartOne {
const Matrix<2, 2, double> A({
    {2, -2},
    {3, -5},
});
const Matrix<2, 2, double> B({
    {-2, 0},
    {4, 2},
});
const Matrix<2, 3, double> C({
    {-1, 2, 0},
    {2, 0, 3},
});
const Matrix<3, 2, double> E({
    {2, -1},
    {std::acos(-1), std::log10(2)},
    {-2, 3},
});
const Matrix<3, 3, double> F({
    {1, 2, 3},
    {2, 3, 4},
    {3, 5, 7},
});
const Matrix<3, 3, double> I({
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
});

void QuestionA();
void QuestionB();
void QuestionC();
void QuestionD();
} // namespace PartOne

#endif