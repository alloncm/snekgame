#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
public:
	Board(Graphics& g);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	bool IsInBounds(Location& l)const;
private:
	Graphics& gfx;
public:
	static constexpr int Dimension = 20;
	static constexpr int Width = 40;
	static constexpr int Height = 30;
	static constexpr int startx = 0;
	static constexpr int starty = 0;
};