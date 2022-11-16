#ifndef MATRIX_H
#define MATRIX_H

#include <ostream>
#include <string>
#include <array>

template <class E>
using IL_t = std::initializer_list<E>;
using std::size_t;

template <size_t M, size_t N, typename T>
class Matrix {
public:
    Matrix() {
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                m_Matrix[i][j] = 0;
    }

    Matrix(IL_t<IL_t<T>> &&initMat) {
        if (initMat.size() != M)
            throw std::string("Size Mismatch");

        size_t i = 0, j = 0;

        for (const auto &m : initMat) {
            if (m.size() != N)
                throw std::string("Size Mismatch");

            for (const auto &n : m)
                m_Matrix[i][j++] = n;

            ++i;
            j = 0;
        }
    }

    size_t GetHeight() const { return M; }
    size_t GetWidth() const { return N; }

    Matrix operator+(const Matrix &other) const {
        Matrix res;

        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                res[i][j] = m_Matrix[i][j] + other[i][j];

        return res;
    }

    Matrix &operator+=(const Matrix &other) {
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                m_Matrix[i][j] += other[i][j];

        return *this;
    }

    Matrix operator-(const Matrix &other) const {
        Matrix res;

        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                res[i][j] = m_Matrix[i][j] - other[i][j];

        return res;
    }

    Matrix &operator-=(const Matrix &other) {
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                m_Matrix[i][j] -= other[i][j];

        return *this;
    }

    Matrix operator*(const T scalar) const {
        Matrix res;

        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                res[i][j] = scalar * m_Matrix[i][j];

        return res;
    }

    friend Matrix operator*(const T scalar, const Matrix &mat) {
        Matrix res;

        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                res[i][j] = scalar * mat[i][j];

        return res;
    }

    Matrix &operator*=(const int scalar) {
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                m_Matrix[i][j] *= scalar;

        return *this;
    }

    template <size_t Y>
    Matrix<M, Y, T> operator*(const Matrix<N, Y, T> &other) const {
        Matrix<M, Y, T> res;

        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < Y; ++j)
                for (size_t k = 0; k < N; ++k)
                    res[i][j] += m_Matrix[i][k] * other[k][j];

        return res;
    }

    Matrix<M, M, T> operator^(const int scalar) const {
        Matrix<M, M, T> res({
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
        });

        for (int i = 0; i < scalar; ++i)
            res = res * *this;

        return res;
    }

    bool operator==(const Matrix &other) {
        for (size_t i = 0; i < M; ++i)
            for (size_t j = 0; j < N; ++j)
                if (m_Matrix[i][j] != other[i][j])
                    return false;

        return true;
    }

    bool operator!=(const Matrix &other) { return !(*this == other); }

    std::array<T, N> &operator[](size_t index) { return m_Matrix[index]; }
    const std::array<T, N> &operator[](size_t index) const {
        return m_Matrix[index];
    }

    friend std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j)
                out << mat[i][j] << " ";

            out << "\n";
        }

        return out;
    }

private:
    std::array<std::array<T, N>, M> m_Matrix;
};

template <size_t M, size_t N, typename T>
Matrix<N, M, T> Transpose(const Matrix<M, N, T> &mat) {
    Matrix<N, M, T> res;

    for (size_t i = 0; i < M; ++i)
        for (size_t j = 0; j < N; ++j)
            res[j][i] = mat[i][j];

    return res;
}

template <typename T>
Matrix<2, 2, T> Invert(const Matrix<2, 2, T> &mat) {
    Matrix<2, 2, T> res({
        {mat[1][1], -mat[0][1]},
        {-mat[1][0], mat[0][0]},
    });

    int det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    if (det == 0)
        throw std::string("Not invertible");

    return (1. / det) * res;
}

#endif