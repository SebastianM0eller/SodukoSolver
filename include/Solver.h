//
// Created by sebastian on 12/31/25.
//

#pragma once
#include "grid.h"

/**
 * @struct SolverStruct
 * @brief Represents the result of solving a Sudoku puzzle.
 *
 * This structure contains the state of a Sudoku grid along with
 * a flag indicating whether the puzzle has been successfully solved.
 *
 * @note The `Grid` class represents the Sudoku board and its state,
 * while the `solved` flag indicates whether the solving process
 * was successful.
 *
 * @see Grid
 */
struct SolverStruct
{
  Grid Soduko;
  bool solved;
};

SolverStruct Solve(Grid SodukoBoard, int tileNumber);