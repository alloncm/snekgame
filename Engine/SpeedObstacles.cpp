#include "SpeedObstacles.h"
#include<ctime>
#include<random>

SpeedObstacles::SpeedObstacles(Board& b)
{
	for (int i = 0; i < Board::Height*Board::Width; i++)
	{
		Obstacles[i] = nullptr;
	}
	std::mt19937 gen(static_cast<std::mt19937::result_type>(std::time(nullptr)));
	std::uniform_int_distribution<int> xdist(0, Board::Width - 1);		//initialize the random
	std::uniform_int_distribution<int> ydist(0, Board::Height - 1);

	Location newloc;
	for (int i = 0; i < numObs; i++)
	{
		do
		{
			newloc.x = xdist(gen);
			newloc.y = ydist(gen);
		} while (!b.IsTileEmpty(newloc) && IsTaken(newloc));
		Obstacles[newloc.y*Board::Width + newloc.x] = new Obstacle(newloc, color);
	}
	

}

void SpeedObstacles::Draw(Board & b)
{
	for (int i = 0; i < Board::Height*Board::Width; i++)
	{
		if (Obstacles[i] != nullptr && Obstacles[i]->eaten == false)
		{
			b.DrawCell(Obstacles[i]->loc, Obstacles[i]->c);
		}
	}
}

void SpeedObstacles::Remove(Location & loc)
{
	Obstacles[loc.y*Board::Width + loc.x]->eaten = true;
}

bool SpeedObstacles::IsTaken(Location & loc)
{
	if (Obstacles[loc.y*Board::Width + loc.x] != nullptr)
	{
		return true;
	}
	return false;
}

SpeedObstacles::~SpeedObstacles()
{
	for (int i = 0; i < Board::Height*Board::Width; i++)
	{
		if (Obstacles[i] != nullptr)
		{
			Obstacle* temp = Obstacles[i];
			delete temp;
			Obstacles[i] = nullptr;
		}
	}
}

SpeedObstacles::Obstacle::Obstacle(Location & l, Color c)
{
	this->loc.x = l.x;
	this->loc.y = l.y;
	this->c = c;
	eaten = false;
}
