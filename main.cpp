//
// Created by sebastian on 12/31/25.
//

#include <iostream>

#include "grid.h"
#include "Solver.h"

int main()
{
  std::string boardInput;

  std::cout << "Enter a Sudoku board (9x9 numbers) as a continuous string: ";
  std::cin >> boardInput;

  while (boardInput.size() != 81)
  {
    std::cout << "\nInvalid input. Please enter a 9x9 string: ";
    boardInput.clear();
    std::cin >> boardInput;
  }

  const Grid SodokuBoard{boardInput};
  SolverStruct solvedSodoku = Solve(SodokuBoard, 0);
  solvedSodoku.PrintBoard();
}
