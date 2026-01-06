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

  Grid SodukoBoard{boardInput};
  SolverStruct solvedSoduko = Solve(SodukoBoard, 0);
  solvedSoduko.PrintBoard();
}
