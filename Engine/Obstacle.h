#pragma once
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
class Obstacles
{
private:
	struct Obstacle
	{
		Location loc;
		Color c;
	};
private:
	static constexpr int obsSize = 50;
	Obstacle obs[obsSize];
	Color c = Colors::Gray;
	int size;
public:
	Obstacles();
	void Add(Snake snek, Goal g);
	bool IsInTile(Location& loc);
	void Draw(Board brd);
};