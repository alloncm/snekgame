#pragma once
#include "Board.h"
class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& l);
		void InitBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta);
		void Draw(Board& brd);
		const Location& GetLoc()const;
	private:
		Location loc;
		Color c;

	};
public:
	Snake(Location& loc);
	void MoveBy(const Location& delta, Board& b);
	void Grow(const Location& delta,Board& b);
	void Draw(Board& brd);
	Location GetNextLocation(Location& delta);
	bool IsInTileExeptEnd(const Location& loc);
	bool isInTile(const Location& loc)const;
private:
	static constexpr int MaxSize = 100;
	Segment segments[MaxSize];
	int size;
	static constexpr Color HaedColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Green;
};