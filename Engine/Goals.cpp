#include "Goals.h"

Goals::Goals(int num, std::mt19937 rng, Board& brd)
	:
	goals(num),
	size(num)
{
	for (int i = 0; i < num; i++)
	{
		goals [i] = Goal(rng, brd);
	}
}

Goal & Goals::operator[](int i)
{
	return goals[i];
}

void Goals::Draw(Board & brd)
{
	for (int i = 0; i < size; i++)
	{
		goals[i].Draw(brd);
	}
}

int Goals::Size()
{
	return size;
}

Goals::~Goals()
{
}
