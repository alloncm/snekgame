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
#include<fstream>
#include<string>

using namespace std::chrono;

Game::Game(MainWindow& wnd) :
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	snek(Location{ Board::Width / 2,Board::Height / 2 }),
	delta({ 1,0 }),
	snekCounter(0),
	isGameOver(false),
	snekMovePeriod(0.2),
	obs(),
	addObs(0),
	ft(),
	speedObs(brd),
	goals(nGoals,rng,brd)
{
	int width = 0;
	int height = 0;
	int tile = 0;
	float Speed = 0;
	int pAmount = 0;
	int fAmount = 0;
	std::ifstream in("configuration.txt");
	std::string str;
	char c = 0;
	while (in >> c)
	{
		if (c == '[')
		{
			std::getline(in, str, ']');
			if (!str.compare("Board Size"))
			{
				in >> width >> height;
			}
			else if (!str.compare("Tile Size"))
			{
				in >> tile;
			}
			else if (!str.compare("Speedup Rate"))
			{
				in >> Speed;
			}
			else if (!str.compare("Poision Amount"))
			{
				in >> pAmount;
			}
			else if (!str.compare("Food Amount"))
			{
				in >> fAmount;
			}
		}
	}

}

void Game::Go()
{
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gfx.BeginFrame();
		UpdateModel();
		ComposeFrame();
		gfx.EndFrame();
	}
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


		Location next = snek.GetNextLocation(delta);	//getting the next location of the snek by the keys been pressed
		
		snekCounter += ft.Mark();

		//checks if the numbers of frames that passed is enough to move the snek
		if (snekCounter >= snekMovePeriod)
		{
			snekCounter = 0;		//init the counter
		
			//checks for game over
			isGameOver = CheckForGameOver(next);
			
			
			if(!isGameOver)
			{
				bool eating = next == goals[0].GetLoc();
				int index = 0;
				for (int i = 1; i < nGoals &&eating==false; i++)
				{
					eating = next == goals[i].GetLoc();
					index = i;
					//checks for eating the goal
				}
				if (eating)
				{
					snek.Grow(delta, brd);		//increase the segments by one and moves the snek
					//if the move period is not the max decrease 1
				}
				else
				{
					snek.MoveBy(delta, brd);
				}
				if (eating)
				{
					goals[index].Respawn(rng, brd);//respawn the goal
					//checks if the goal respawn on an existing obstacle
					/*
					while (brd.IsTileEmpty(goal.GetLoc()))
					{
						goal.Respawn(rng, brd, snek);
					}
					*/
					addObs++;
				}
				if (addObs >= obsRate)
				{
					obs.Add(brd);
					addObs = 0;
				}
				if (speedObs.IsTaken(next))
				{
					speedObs.Remove(next);
					snekMovePeriod *= 0.95;
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
	speedObs.Draw(brd);
	brd.ReformatBoard();
	snek.Draw(brd);
	goals.Draw(brd);
	brd.DrawBorder();
	obs.Draw(brd);
	
}
