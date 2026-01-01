//
// Created by sebastian on 12/31/25.
//

#pragma once
#include "grid.h"

struct SolverStruct
{
  Grid Soduko;
  bool solved;
};

SolverStruct Solve(Grid SodukoBoard, int tileNumber);