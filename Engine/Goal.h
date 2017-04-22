#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Goal
{
private:
	Location loc;
	static constexpr Color c = Colors::Red;
public:
	Goal(std::mt19937 rng, const Board& brd, const Snake& Snek);
	void Respawn(std::mt19937 rng, const Board& brd, const Snake& Snek);
	void Draw(Board& brd)const;
	const Location& GetLoc()const;
};