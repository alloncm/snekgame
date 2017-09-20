#pragma once
#include"Board.h"


class SpeedObstacles
{
	struct Obstacle
	{
		Location loc;
		Color c;
		bool eaten;

		Obstacle();
		Obstacle(Location& loc, Color c);
	};
public:

private:
	std::vector<Obstacle> Obstacles;
	Color color = Colors::Magenta;

public:
	SpeedObstacles(Board& b,int obsNum);
	void Draw(Board& b);
	void Remove(const Board& b,Location & loc);
	bool IsTaken(const Board& b,Location & loc);
	~SpeedObstacles();
};