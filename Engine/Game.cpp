/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"


Game::Game(MainWindow& wnd) :
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	snek(Location{ Board::Width / 2,Board::Height / 2 }),
	delta({ 1,0 }),
	snekCounter(0),
	isGameOver(false),
	goal(rng, brd, snek),
	snekMovePeriod(8),
	obs(),
	addObs(0)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//checks for game over
	if (!isGameOver)
	{
		//moving the snek with the keyboard
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			delta = { 0,-1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta = { 0,1 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta = { 1,0 };
		}
		else if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta = { -1,0 };
		}


		snekCounter++;	//increasing the frames passed since last move
		Location next = snek.GetNextLocation(delta);	//getting the next location of the snek by the keys been pressed
		
		//checks if the numbers of frames that passed is enough to move the snek
		if (snekCounter >= snekMovePeriod)
		{
			snekCounter = 0;		//init the counter

			//checks for game over
			isGameOver = CheckForGameOver(next);
			
			
			if(!isGameOver)
			{
				const bool eating = next == goal.GetLoc();		//checks for eating the goal
				if (eating)
				{
					snek.Grow(delta);		//increase the segments by one and moves the snek
					//if the move period is not the max decrease 1
				}
				else
				{
					snek.MoveBy(delta);
				}
				if (eating)
				{
					goal.Respawn(rng, brd, snek);//respawn the goal
					//checks if the goal respawn on an existing obstacle
					while (obs.IsInTile(goal.GetLoc()))
					{
						goal.Respawn(rng, brd, snek);
					}
					addObs++;
				}
				if (addObs >= obsRate)
				{
					obs.Add(snek, goal);
					addObs = 0;
				}
			}
		}
	}
}
bool Game::CheckForGameOver(Location& nextloc)
{
	bool gameover = obs.IsInTile(nextloc)|| (!(brd.IsInBounds(nextloc)))|| snek.IsInTileExeptEnd(nextloc);
	return gameover;
}
void Game::ComposeFrame()
{
	//draw the fucking objects
	snek.Draw(brd);
	goal.Draw(brd);
	brd.DrawBorder();
	obs.Draw(brd);
}
