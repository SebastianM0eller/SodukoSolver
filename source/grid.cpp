//
// Created by sebastian on 12/31/25.
//

#include "grid.h"

#include <iostream>
#include <ostream>

/**
 * @brief Constructs a new Grid object and initializes all tiles in the grid.
 *
 * This constructor sets up the grid by initializing all tiles to a default state,
 * where each tile's state is set to TileState::EMPTY, and it is marked as not given.
 */
Grid::Grid()
{
  m_tiles.fill(Tile{TileState::EMPTY, false});
}

/**
 * @brief Changes the state of a tile at the specified location.
 *
 * This method updates the state of the tile located at the given index
 * within the grid, provided the index is valid.
 *
 * @param location The index of the tile to update. Must be between 0 and 80 (inclusive).
 * @param newState The new state to assign to the tile.
 */
void Grid::ChangeState(const int location, const TileState newState)
{
  if (location >= 0 && location < 81)
  {
    m_tiles[location].state = newState;
  }
}

/**
 * @brief Retrieves the state of a tile at a specified location in the grid.
 *
 * This method returns the state of the tile at the given location. If the location
 * is invalid (outside the range of 0 to 80), it returns TileState::EMPTY.
 *
 * @param location The index of the tile (0-based) for which the state is to be retrieved.
 * @return The state of the tile if the location is valid, or TileState::EMPTY if the location is invalid.
 */
TileState Grid::GetState(const int location)
{
  if (location < 0 || location > 80)
  {
    return TileState::EMPTY;
  }
  return m_tiles[location].state;
}

bool Grid::IsGiven(const int location)
{
  if (location < 0 || location > 80)
  {
    return false;
  }
  return m_tiles[location].Given;
}

/**
 * @brief Checks if changing the state of a tile at the specified location is allowed.
 *
 * This method determines whether a tile's state can be changed, based on the given
 * location being valid and whether the tile is marked as "Given".
 *
 * @param location The location of the tile to check, should be in the range [0, 80].
 * @return True if the change is allowed, false otherwise.
 */
bool Grid::IsChangeAllowed(int location)
{
  if (location < 0 || location > 80)
  {
    return false;
  }
  if (m_tiles[location].Given)
  {
    return false;
  }

  return true;
}

/**
 * @brief Determines if a move at the specified location with the given state
 *        results in a losing condition.
 *
 * This method checks whether changing the tile at the provided location to the
 * specified state would create a losing condition by violating Sudoku rules
 * either vertically, horizontally, or within a 3x3 sub-grid area. If the change
 * is not allowed (e.g., the tile is marked as "Given" or the location is invalid),
 * the method will return false.
 *
 * @param location The index of the tile to be changed (0-80).
 * @param newState The new state to assign to the specified tile.
 * @return True if the move results in a losing condition; false otherwise.
 */
bool Grid::IsMoveLoosing(int location, TileState newState)
{
  if (!IsChangeAllowed(location)) return true;

  m_tiles[location].state = newState;

  if (IsLoosingVertical(location, newState) ||
      IsLoosingHorizontal(location, newState) ||
      IsLoosingArea(location, newState))
  {
    return true;
  }
  return false;
}

/**
 * @brief Checks if placing a tile in the specified location results in a losing condition
 *        in the vertical column.
 *
 * This method evaluates whether placing a tile with the given state at a specific location
 * causes multiple tiles of the same state to appear in the same vertical column, leading
 * to a violation of the game rules.
 *
 * @param location The index of the tile location (0 to 80) in the grid.
 * @param newState The state to be placed at the specified location.
 * @return True if placing the tile results in a losing condition in the column, otherwise false.
 */
bool Grid::IsLoosingVertical(const int location, const TileState newState) const
{
  const int column = location % 9;
  int count = 0;
  for (int i = 0; i < 9; i++)
  {
    if (m_tiles[i * 9 + column].state == newState)
    {
      count += 1;
    }
  }
  return count > 1;
}

/**
 * @brief Checks if the placement of a new tile state at the given location causes a horizontal losing condition.
 *
 * This function evaluates whether placing the specified tile state at the given grid location results in
 * more than one occurrence of the same state within the corresponding row, which would result in a horizontal losing condition.
 *
 * @param location The index in the grid where the new tile state is placed. Should be between 0 and 80.
 * @param newState The new tile state to place at the specified location.
 * @return True if the placement causes a horizontal losing condition, otherwise false.
 */
bool Grid::IsLoosingHorizontal(const int location, const TileState newState) const
{
  const int row = location / 9;
  int count = 0;
  for (int i = 0; i < 9; i++)
  {
    if (m_tiles[i + row * 9].state == newState)
    {
      count += 1;
    }
  }
  return count > 1;
}

/**
 * @brief Determines if changing a tile's state causes a losing condition within its 3x3 area.
 *
 * This function checks if changing the state of a tile at the given location
 * to the specified state creates a conflict within the 3x3 sub-grid area to which the tile belongs.
 * A conflict occurs if the new state is found more than once in the area.
 *
 * @param location The index of the tile to be checked, ranging from 0 to 80.
 * @param newState The new state to assign to the tile, represented as a TileState.
 * @return True if the state change results in a losing condition within the 3x3 area, otherwise false.
 */
bool Grid::IsLoosingArea(const int location, const TileState newState) const
{
  const int rowNumber = location / 9;
  const int columnNumber = location % 9;

  const int verticalAreaStart = columnNumber / 3 * 3;
  const int horizontalAreaStart = rowNumber / 3 * 3;

  int count = 0;
  for (int column = verticalAreaStart; column < verticalAreaStart + 3; column++)
  {
    for (int row = horizontalAreaStart; row < horizontalAreaStart + 3; row++)
    {
      std::cout << row << " " << column << std::endl;
      if (m_tiles[(row) * 9 + (column)].state == newState)
      {
        count += 1;
      }
    }
  }
  return count > 1;
}
