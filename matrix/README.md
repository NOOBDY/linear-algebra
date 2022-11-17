# Linear Algebra Programming Assignment #1

Basic Matrix Arithmetic Library Over-Engineered with C++ Templates

## Build and Execute Project

### Makefile
```bash
make
```

### CMake
```bash
cmake -B bin
cmake --build bin
```

The compiled binary would be `./bin/matrix`

> Tested on `clang-14` using C++11 standard

## Documentation

### Project Structure

The project entry point is in the `src/main.cpp` file. And the two parts of the homework is divided into two namespaces `PartOne` and `PartTwo`, each individual question will be in their respective folder.

To test the answers separately, simply comment out the unwanted question function calls in the `main` function and rebuild the project.

This project heavily utilizes C++ templates and thus the implementation has to be in the header file.

### API Manual

#### Constructor

To instantiate a `Matrix` obj, use
```cpp
Matrix<M, N, T> mat;
// or
Matrix<M, N, T> mat({
    {...},
    {...},
    ...
});
```
where `M` and `N` marks the dimensions of the matrix and `T` stands for the type of the matrix elements.

The default constructor allocates a $M*N$ matrix and sets every element to $0$.

The other constructor initializes the matrix using a 2D `std::initializer_list` and throws an exception if the list size doesn't match the matrix dimensions.

#### Output to Console

The `Matrix` class overloads the `<<` operator so outputting a matrix can be achieved by
```cpp
Matrix<2, 2, double> mat({{1,2},{3,4}});
std::cout << mat;
// expected output:
// 1 2
// 3 4
```

#### Arithmetic Operations

The `Matrix` class supports many operators as shown below

* Addition: This function supports both the `+` and `+=` operators. It adds the two corresponding elements together and returns the new matrix or does the operator in-place.

* Subtraction: This function supports both the `-` and `-=` operators. It subtracts the two corresponding elements together and returns the new matrix or does the operator in-place.

* Scalar-to-Matrix Multiplication: This function supports both the `*` and `*=` operators. It multiplies the each elements by the scalar and returns the new matrix or does the operator in-place.

* Matrix-to-Matrix Multiplication: This function supports matrix-to-matrix multiplications using the `*` operator. If the sizes of the two matrices doesn't match the project will fail to compile due to template type checks. Because of potential dimension differences, this function doesn't support the `*=` in-place operator.

* Power: This function supports the `^` operator for power operations. A integer must a be used with this operator as floating point powers are not supported.

#### Utility Functions

* Comparison: This function support both the `==` and `!=` equivalence operators. This checks every elements in the two matrices and returns the according result.

* Element Access: Accessing the $A_{ij}$ element can be achieved using `A[i][j]`, both setting and getting the value is supported.

* Dimension Access: Accessing the width and height of the matrix can be achieved using `A.GetWidth()` and `A.GetHeight()`.

* Transpose: Return a new transposed matrix by calling `Transpose(A)`
* Inverse: Return a new inverted matrix by calling `Invert(A)`, throws an exception if the matrix is not invertible.

> Side effects: Most functions are marked `const` and can't introduce side effects to the original matrix. However, operators such as `+=` and `-=` does the operation in-place and can change the passed in matrix.