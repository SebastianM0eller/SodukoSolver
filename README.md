# SodokuSolver

> A simple Sodoku solver, using a recursive backtracking algorithm.

## About
The aim of this project is to learn some C++ while having some fun.
* **Standard:** C++23
* **Build System:** CMake 3.30+

## How to build
* It's recommended to create a separate build folder and run cmake from there.
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### How to
* Run the executable.
* Enter the puzzle you want to solve. (As a single line of 81 characters)
  * Use numbers (1-9) for a given tile.
  * Use 0 (or any other character) for an empty tile.

### Example

**Input:**
```text
Enter a Sudoku board (9x9 numbers) as a continuous string:
530070000600195000098000060800060003400803001700020006060000280000419005000080079
```
**Output:**
```text
5 3 4 | 6 7 8 | 9 1 2
6 7 2 | 1 9 5 | 3 4 8
1 9 8 | 3 4 2 | 5 6 7
------+-------+------
8 5 9 | 7 6 1 | 4 2 3
4 2 6 | 8 5 3 | 7 9 1
7 1 3 | 9 2 4 | 8 5 6
------+-------+------
9 6 1 | 5 3 7 | 2 8 4
2 8 7 | 4 1 9 | 6 3 5
3 4 5 | 2 8 6 | 1 7 9

Solved!
```


## What I learned
* Recursive backtracking algorithm
