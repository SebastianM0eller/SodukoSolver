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

  void ChangeState(int location, int newState);
  int GetState(int location);

private:
  std::array<Tile, 81> tiles;
};