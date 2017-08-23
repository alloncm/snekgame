#include "Obstacle.h"
#include <ctime>
Obstacles::Obstacles():
	size(0)
{
}
void Obstacles::Add(Snake snek, Goal g)
{
	std::mt19937 gen(static_cast<std::mt19937::result_type>(std::time(nullptr)));
	std::uniform_int_distribution<int> xdist(0, Board::Width - 1);		//initialize the random
	std::uniform_int_distribution<int> ydist(0, Board::Height - 1);

	Location newloc;		//the new location to respwan

	//checks for aviavlibe place to respawn
	do
	{
		newloc.x = xdist(gen);
		newloc.y = ydist(gen);
	} while (snek.isInTile(newloc)||IsInTile(newloc)||(newloc==g.GetLoc()));				//change those IsIntile functions to the new form
	obs[size].loc = newloc;
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

void Obstacles::Draw(Board brd)
{
	for (int i = 0; i < size; i++)
	{
		brd.DrawCell(obs[i].loc, c);
		brd.TileIsFull(obs[i].loc);
	}
}
