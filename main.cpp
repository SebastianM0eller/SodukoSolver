//
// Created by sebastian on 12/31/25.
//

#include <iostream>

#include "grid.h"
#include "Solver.h"

int main()
{
  Grid SodukoBoard{};
  SolverStruct solvedSoduko = Solve(SodukoBoard, 0);
}
