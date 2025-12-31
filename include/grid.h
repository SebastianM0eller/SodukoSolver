//
// Created by sebastian on 12/31/25.
//

#pragma once
#include <array>

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
  ~Grid() = default;

  void ChangeState(int location, TileState newState);
  bool IsChangeAllowed(int location);
  bool IsMoveLoosing(int location, TileState newState);
  TileState GetState(int location);

private:
  std::array<Tile, 81> m_tiles{};

  bool IsLoosingVertical(int location, TileState newState) const;
  bool IsLoosingHorizontal(int location, TileState newState) const;
  bool IsLoosingArea(int location, TileState newState) const;
};