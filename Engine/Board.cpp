#include "Board.h"
#include <assert.h>

Board::Board(Graphics & g, int w, int h, int d) :
	gfx(g),
	width(w),
	height(h),
	dim(d),
	isEmptyTile(w*h)
{
	ReformatBoard();
}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawSmallRect(loc.x*dim+startx, loc.y*dim+starty, dim, dim, c);		//draw the cube in the tile
}

void Board::DrawBorder()
{
	//checks if ints full screen and if not draw the borders
	if (startx > 0)
	{
		for (int i = starty; i < starty + dim*height; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(startx - 1, i, c);
		}
	}
	if (starty > 0)
	{
		for (int i = startx; i < startx + dim*width; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(i, starty-1, c);
		}
	}
	if (startx + dim*width < Graphics::ScreenWidth - 1)
	{
		for (int i = starty; i < starty + dim*height; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(startx + dim*width, i, c);
		}
	}
	if (starty + dim*height < Graphics::ScreenHeight - 1)
	{
		for (int i = startx; i < startx + dim*width; i++)
		{
			Color c = Colors::Blue;
			gfx.PutPixel(i , starty+dim*height, c);
		}
	}
}

bool Board::IsInBounds(Location & l) const
{
	return l.x >= 0 && l.x < width&&l.y >= 0 && l.y < height;
}

void Board::ReformatBoard()
{
	for (int i = 0; i < width*height ; i++)
	{
		this->isEmptyTile[i] = true;
	}
}

bool Board::IsTileEmpty(const Location & loc) const
{
	return isEmptyTile[loc.y*width + loc.x];
}

void Board::TileIsFull(const Location & loc)
{
	this->isEmptyTile[loc.y*width + loc.x] = false;
}

int Board::GetWidth()const
{
	return width;
}

int Board::GetHeight()const
{
	return height;
}
