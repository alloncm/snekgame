#pragma once
#include "Graphics.h"
#include "Location.h"
#include<random>
#include"Snake.h"

class Board
{
public:
	static constexpr int obsize = 50;
	static constexpr int Dimension = 20;
	static constexpr int Width = 40;
	static constexpr int Height = 30;
	static constexpr int startx = 0;
	static constexpr int starty = 0;
public:
	Board(Graphics& g);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	bool IsInBounds(Location& l)const;
	void AddObs(std::mt19937 rng, Snake& snek);
	bool IsInTile(const Location& l)const;
	void DrawObs();
private:
	Graphics& gfx;
	Location obsticles[obsize];
	Color obsColor = Colors::Gray;
	int sizeObs;
};