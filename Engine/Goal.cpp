#include "Goal.h"
#include<ctime>

Goal::Goal(std::mt19937 rng,  Board & brd)
{
	Respawn(rng, brd);		//respawn the snek
}

void Goal::Respawn(std::mt19937 rng, Board & brd)
{
	std::mt19937 gen(static_cast<std::mt19937::result_type>(std::time(nullptr)));
	std::uniform_int_distribution<int> xdist(0, brd.GetWidth() - 1);		//initialize the random
	std::uniform_int_distribution<int> ydist(0, brd.GetHeight() - 1);

	Location newloc;		//the new location to respwan

	//checks for aviavlibe place to respawn
	do
	{
		newloc.x = xdist(gen);
		newloc.y = ydist(gen);	
	} while (!brd.IsTileEmpty(newloc));
	loc = newloc;
	brd.TileIsFull(loc);
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
	brd.TileIsFull(loc);
}

const Location & Goal::GetLoc() const
{
	return loc;
}
