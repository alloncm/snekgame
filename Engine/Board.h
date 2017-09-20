#pragma once
#include "Graphics.h"
#include "Location.h"
#include <vector>
class Board
{
public:
	Board(Graphics& g,int w,int h,int d);
	void DrawCell(const Location& loc, Color c);
	void DrawBorder();
	bool IsInBounds(Location& l)const;
	void ReformatBoard();
	bool IsTileEmpty(const Location& loc)const;
	void TileIsFull(const Location& loc);
	int GetWidth()const;
	int GetHeight()const;
public:
	static constexpr int startx = 0;
	static constexpr int starty = 0;
	

private:
	Graphics& gfx;
	std::vector<bool> isEmptyTile;
	int height;
	int width;
	int dim;
};