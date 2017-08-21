#include "Board.h"
#include <assert.h>

Board::Board(Graphics & g) :
	gfx(g)
{
	ReformatBoard();
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < Board::Width);
	assert(loc.y >= 0);
	assert(loc.y < Board::Height);
	gfx.DrawSmallRect(loc.x*Dimension+startx, loc.y*Dimension+starty, Dimension, Dimension, c);		//draw the cube in the tile
}

void Board::DrawBorder()
{
	//checks if ints full screen and if not draw the borders
	if (startx > 0)
	{
		for (int i = starty; i < starty + Dimension*Height; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(startx - 1, i, c);
		}
	}
	if (starty > 0)
	{
		for (int i = startx; i < startx + Dimension*Width; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(i, starty-1, c);
		}
	}
	if (startx + Dimension*Width < Graphics::ScreenWidth - 1)
	{
		for (int i = starty; i < starty + Dimension*Height; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(startx + Dimension*Width, i, c);
		}
	}
	if (starty + Dimension*Height < Graphics::ScreenHeight - 1)
	{
		for (int i = startx; i < startx + Dimension*Width; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(i , starty+Dimension*Height, c);
		}
	}
}

bool Board::IsInBounds(Location & l) const
{
	return l.x >= 0 && l.x < Width&&l.y >= 0 && l.y < Height;
}

void Board::ReformatBoard()
{
	for (int i = 0; i < Width*Height - 1; i++)
	{
		this->isEmptyTile[i] = true;
	}
}

bool Board::IsTileEmpty(const Location & loc) const
{
	return isEmptyTile[loc.y*Width + loc.x];
}

void Board::TileIsFull(const Location & loc)
{
	this->isEmptyTile[loc.y*Width + loc.x] = false;
}
