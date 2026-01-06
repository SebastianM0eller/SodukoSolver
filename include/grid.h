//
// Created by sebastian on 12/31/25.
//

#pragma once
#include <array>
#include <string>

enum class TileState
{
  EMPTY,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE,
};

struct Tile
{
  TileState state;
  bool Given;
};

class Grid
{
public:
  Grid();
  Grid(const std::string& BoardString);
  ~Grid() = default;

  void ChangeState(int location, TileState newState);
  bool IsChangeAllowed(int location) const;
  bool IsMoveLoosing(int location, TileState newState);
  bool IsGiven(int location) const;
  TileState GetState(int location) const;

private:
  std::array<Tile, 81> m_tiles{};

  bool IsLosingVertical(int location, TileState newState) const;
  bool IsLosingHorizontal(int location, TileState newState) const;
  bool IsLosingArea(int location, TileState newState) const;
};