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

Goals& Goals::operator=(Goals & g)
{
	this->goals.clear();
	this->size = g.size;
	for (int i = 0; i < size; i++)
	{
		this->goals.emplace_back(g.goals[i]);
	}
	return *this;
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
