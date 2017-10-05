#include"RectI.h"
RectI::RectI(int tlx, int tly, int brx, int bry)
	:
	tLeft({ tlx,tly }),
	bRight({ brx,bry })
{
}

RectI::RectI(Location tLeft, Location bRight)
	:
	tLeft(tLeft),
	bRight(bRight)
{
}

RectI::RectI()
	:
	tLeft({0,0}),
	bRight({0,0})
{
}

RectI::RectI(RectI & r)
	:
	tLeft(r.tLeft),
	bRight(r.bRight)
{
}

RectI::RectI(int width, int height, Location center)
	:
	tLeft({ center.x - width / 2,center.y - height / 2 }),
	bRight({ center.x + width / 2,center.y + height / 2 })
{
}

RectI & RectI::operator=(RectI & r)
{
	this->tLeft = r.tLeft;
	this->bRight = r.bRight;
	return *this;
}

int RectI::GetWidth() const
{
	return bRight.x - tLeft.x;
}

int RectI::GetHeight() const
{
	return bRight.y - tLeft.y;
}

const Location & RectI::GetTopLeft() const
{
	return this->tLeft;
}

const Location & RectI::GetBotoomRight() const
{
	return this->bRight;
}

bool RectI::IsInside(const Location & l) const
{
	if ((l.x > tLeft.x&&l.x < bRight.x) && (l.y > tLeft.y&&l.y < bRight.y))
	{
		return true;
	}
	return false;
}

