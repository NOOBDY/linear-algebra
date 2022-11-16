#ifndef PART_TWO_QUESTIONS_H
#define PART_TWO_QUESTIONS_H

#include "matrix.h"

namespace PartTwo {
const Matrix<3, 3, double> T({
    {1. / 6, 1. / 2, 1. / 3},
    {1. / 2, 1. / 4, 1. / 4},
    {1. / 3, 1. / 4, 5. / 12},
});

void Question();
} // namespace PartTwo

#endif