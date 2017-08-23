#pragma once
#include"Board.h"

class SpeedObstacles
{
	struct Obstacle
	{
		Location loc;
		Color c;
		bool eaten;

		Obstacle(Location& loc, Color c);
	};
public:
	static const int numObs = (Board::Height*Board::Width) / 5;

private:
	Obstacle* Obstacles[Board::Height*Board::Width];
	Color color = Colors::Magenta;

public:
	SpeedObstacles(Board& b);
	void Draw(Board& b);
	void Remove(Location & loc);
	bool IsTaken(Location & loc);
	~SpeedObstacles();
};