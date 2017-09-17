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
	void ReformatBoard();
	bool IsTileEmpty(const Location& loc)const;
	void TileIsFull(const Location& loc);

public:
	static constexpr int Dimension = 20;
	static constexpr int Width = 40;
	static constexpr int Height = 30;
	static constexpr int startx = 0;
	static constexpr int starty = 0;
	

private:
	Graphics& gfx;
	bool isEmptyTile[Width*Height] = { true };
};