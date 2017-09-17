#include "Obstacle.h"
#include <ctime>
#include<random>
Obstacles::Obstacles():
	size(0)
{
}
void Obstacles::Add(Board& b)
{
	std::mt19937 gen(static_cast<std::mt19937::result_type>(std::time(nullptr)));
	std::uniform_int_distribution<int> xdist(0, b.GetWidth() - 1);		//initialize the random
	std::uniform_int_distribution<int> ydist(0, b.GetHeight() - 1);

	Location newloc;		//the new location to respwan

	//checks for aviavlibe place to respawn
	do
	{
		newloc.x = xdist(gen);
		newloc.y = ydist(gen);
	} while (!b.IsTileEmpty(newloc));				//change those IsIntile functions to the new form
	obs[size].loc = newloc;
	b.TileIsFull(obs[size].loc);
	size++;
}

bool Obstacles::IsInTile(const Location& l)const
{
	for (int i = 0; i < size; i++)
	{
		if (obs[i].loc == l)
		{
			return true;
		}
	}
	return false;
}

void Obstacles::Draw(Board & brd)
{
	for (int i = 0; i < size; i++)
	{
		brd.DrawCell(obs[i].loc, c);
		brd.TileIsFull(obs[i].loc);
	}
}
