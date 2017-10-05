#pragma once

#include"Location.h"

class RectI
{
private:
	Location tLeft;
	Location bRight;

public:
	RectI(int tlx, int xly, int brx, int bry);
	RectI(Location tLeft, Location bRight);
	RectI();
	RectI(RectI& r);
	RectI(int width, int height, Location center);
	RectI& operator=(RectI& r);
	int GetWidth()const;
	int GetHeight()const;
	const Location& GetTopLeft()const;
	const Location& GetBotoomRight()const;
	bool IsInside(const Location& l)const;

};
