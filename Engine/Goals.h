#pragma once
#include"Goal.h"

class Goals
{
public:
	Goals(int num, std::mt19937 rng, Board& brd);
	Goals(Goals& g) = delete;
	Goals operator=(Goals& g) = delete;
	Goal& operator[](int i);
	void Draw(Board& brd);
	int Size();
	~Goals();
private:
	Goal* goals;
	int size;
};