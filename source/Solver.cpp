//
// Created by sebastian on 12/31/25.
//

#include "grid.h"
#include "Solver.h"
#include <iostream>

/**
 * Solves a Sudoku puzzle recursively by attempting to fill all tiles with valid values.
 *
 * @param SodukoBoard The current state of the Sudoku board to solve.
 * @param tileNumber The index of the tile being processed (0-80).
 * @return A SolverStruct containing the solved Sudoku board and a boolean indicating whether the board was successfully solved.
 */
SolverStruct Solve(Grid SodukoBoard, const int tileNumber)
{
  // If we have reached the end, the soduko must be solved
  if (tileNumber >= 81)
    return {SodukoBoard, true};

  // If the square is given, we continue without altering it.
  if (SodukoBoard.IsGiven(tileNumber))
  {
    return Solve(SodukoBoard, tileNumber + 1);
  }

  constexpr std::array<TileState, 9> States =
    {TileState::ONE, TileState::TWO, TileState::THREE,
    TileState::FOUR, TileState::FIVE, TileState::SIX,
    TileState::SEVEN, TileState::EIGHT, TileState::NINE};

  // Iterate through all our possibilities.
  for (const TileState state : States)
  {

    // We check if it's an instant loss.
    if (!SodukoBoard.IsMoveLoosing(tileNumber, state))
    {

      // If it's not, we check if it's a win, if we continue.
      SodukoBoard.ChangeState(tileNumber, state);
      SolverStruct result = Solve(SodukoBoard, tileNumber + 1);
      if (result.solved)
      {
        return result;
      }
    }
  }

  // If none of the results result in a correct result, we return the state we got, with the false solved flag.
  return {SodukoBoard, false};
}
