#pragma once
#include "Board.h"

class Obstacles
{
private:
	struct Obstacle
	{
		Location loc;
		Color c;
	public:
		Obstacle(Location& loc, Color c);
	};
private:
	std::vector<Obstacle> obs;
	Color c = Colors::White;
	int size;
public:
	Obstacles();
	void Add(Board& b);
	bool IsInTile(const Location& loc) const;
	void Draw(Board& brd);
};