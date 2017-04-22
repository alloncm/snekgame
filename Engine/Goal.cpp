#include "Goal.h"


Goal::Goal(std::mt19937 rng, const Board & brd, const Snake & snek)
{
	Respawn(rng, brd, snek);		//respawn the snek
}

void Goal::Respawn(std::mt19937 rng, const Board & brd, const Snake & snek)
{
	
	std::uniform_int_distribution<int> xdist(0, Board::Width - 1);		//initialize the random
	std::uniform_int_distribution<int> ydist(0, Board::Height - 1);

	Location newloc;		//the new location to respwan

	//checks for aviavlibe place to respawn
	do
	{
		newloc.x = xdist(rng);
		newloc.y = ydist(rng);	
	} while (snek.isInTile(newloc));
	loc = newloc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Goal::GetLoc() const
{
	return loc;
}
