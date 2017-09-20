#include "Snake.h"

Snake::Snake(Location& loc,int size)
	:
	segments()
{
	Segment s;
	s.InitHead(loc);
	segments.push_back(s);
	this->size = 1;
}



void Snake::MoveBy(const Location & delta , Board& b)
{
	
	for (int i = size - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
		b.TileIsFull(segments[i].GetLoc());
	}
	segments[0].MoveBy(delta);
	b.TileIsFull(segments[0].GetLoc());
}

void Snake::Grow(const Location& delta, Board& brd)
{
	Segment s;
	s.InitBody();
	segments.push_back(s);
	size++;
	MoveBy(delta,brd);
}

void Snake::Draw(Board & brd)
{
	for (int i = 0; i < size; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextLocation(Location & delta)
{
	Location l (segments[0].GetLoc());
	l.add(delta);
	return l;
}

bool Snake::IsInTileExeptEnd(const Location& loc) 
{
	for (int i = 0; i < size-1; i++)
	{
		if (segments[i].GetLoc() == loc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInTile(const Location & loc)const
{
	for (int i = 0; i < size; i++)
	{
		if (segments[i].GetLoc() == loc)
		{
			return true;
		}
	}
	return false;
}

void Snake::Segment::InitHead(const Location & l)
{
	loc = l;
	c = Snake::HaedColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta)
{
	loc.add(delta);
}

void Snake::Segment::Draw(Board & brd)
{
	brd.DrawCell(loc, c);
	brd.TileIsFull(loc);
}

const Location& Snake::Segment::GetLoc()const
{
	return loc;
}
