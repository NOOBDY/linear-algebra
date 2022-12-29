#ifndef QUESTION_H
#define QUESTION_H

#include "matrix.h"

const Matrix<2, 2, double> A({
    {-1, 2},
    {0, 2},
});

const Matrix<2, 2, double> B({
    {1, 6},
    {5, 2},
});

const Matrix<2, 2, double> C({
    {1, 2},
    {2, 4},
});

const Matrix<2, 2, double> V({
    {7, 2},
    {-4, 1},
});

const Matrix<2, 2, double> W({
    {3, 1},
    {-1, 1},
});

const Matrix<2, 2, double> X({
    {1, 2},
    {3, 4},
});

const Matrix<2, 2, double> Z({
    {0, 0},
    {0, 0},
});

void QuestionOne();
void QuestionTwo();

#endif