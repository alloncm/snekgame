#include "SpeedObstacles.h"
#include<ctime>
#include<random>

SpeedObstacles::SpeedObstacles(Board& b,int numObs)
	:
	Obstacles(b.GetHeight()*b.GetWidth())
{
	std::mt19937 gen(static_cast<std::mt19937::result_type>(std::time(nullptr)));
	std::uniform_int_distribution<int> xdist(0, b.GetWidth() - 1);		//initialize the random
	std::uniform_int_distribution<int> ydist(0, b.GetHeight() - 1);

	Location newloc;
	for (int i = 0; i < numObs; i++)
	{
		do
		{
			newloc.x = xdist(gen);
			newloc.y = ydist(gen);
		} while (!b.IsTileEmpty(newloc) || IsTaken(b,newloc));
		Obstacles[newloc.y*b.GetWidth() + newloc.x] = Obstacle(newloc, color);
	}
	

}

void SpeedObstacles::Draw(Board & b)
{
	for (int i = 0; i < b.GetHeight()*b.GetWidth(); i++)
	{
		if (Obstacles[i].eaten == false)
		{
			b.DrawCell(Obstacles[i].loc, Obstacles[i].c);
		}
	}
}

void SpeedObstacles::Remove(const Board& b,Location & loc)
{
	Obstacles[loc.y*b.GetWidth()+ loc.x].eaten = true;
}

bool SpeedObstacles::IsTaken(const Board& b,Location & loc)
{
	if (Obstacles[loc.y*b.GetWidth() + loc.x].eaten==false)
	{
		return true;
	}
	return false;
}

SpeedObstacles::~SpeedObstacles()
{
}

SpeedObstacles::Obstacle::Obstacle()
{
	eaten = true;
	loc = { 0,0 };
	c = Colors::Black;
}

SpeedObstacles::Obstacle::Obstacle(Location& loc, Color c)
{
	this->loc.x = loc.x;
	this->loc.y = loc.y;
	this->c = c;
	eaten = false;
}