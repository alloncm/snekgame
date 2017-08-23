#pragma once
#include "Board.h"

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
	void Add(Board& b);
	bool IsInTile(const Location& loc) const;
	void Draw(Board& brd);
};