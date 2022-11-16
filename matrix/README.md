# Linear Algebra Programming Assignment #2

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

The compiled binary will be `bin/matrix`

> Tested on `clang-14`

## Documentation

### Project Structure

The project entry point is in the `src/main.cpp` file. And the two parts of the homework is divided into two namespaces `PartOne` and `PartTwo`, each individual question will be in their respective folder.

To test the answers separately, simply comment out the unwanted question function calls in the `main` function.