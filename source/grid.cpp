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
    return m_tiles[location].state;
  }

  return TileState::EMPTY;
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

bool Grid::IsMoveLoosing(int location, TileState newState)
{
  if (!IsChangeAllowed(location)) return false;

  m_tiles[location].state = newState;

  if (IsLoosingVertical(location, newState) ||
      IsLoosingHorizontal(location, newState) ||
      IsLoosingArea(location, newState))
  {
    return true;
  }
  return false;
}

bool Grid::IsLoosingVertical(const int location, const TileState newState)
{
  const int column = location % 9;
  int count = 0;
  for (int i = 0; i < 9; i++)
  {
    if (m_tiles[i + column * 9].state == newState)
    {
      count += 1;
    }
  }
  return count > 1;
}

bool Grid::IsLoosingHorizontal(const int location, const TileState newState)
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

bool Grid::IsLoosingArea(const int location, const TileState newState)
{
  const int rowNumber = location / 9;
  const int columnNumber = location % 9;

  const int verticalAreaStart = columnNumber / 3 * 3;
  const int horizontalAreaStart = rowNumber / 3 * 3;

  int count = 0;
  for (int row = verticalAreaStart; row < verticalAreaStart + 3; row++)
  {
    for (int column = horizontalAreaStart; column < horizontalAreaStart + 3; column++)
    {
      if (m_tiles[(row) * 9 + (column)].state == newState)
      {
        count += 1;
      }
    }
  }
  return count > 1;
}
