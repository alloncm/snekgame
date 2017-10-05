/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include "Snake.h"
#include "Goals.h"
#include "Obstacle.h"
#include "FrameTime.h"
#include "SpeedObstacles.h"
#include"GameConfig.h"
#include"Surface.h"
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	bool CheckForGameOver(Location& nextloc);
	void ReInitGame();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables */
	GameConfig gc;						//contains cofiguration for the game to read from a file 
	FrameTimer ft;						//frame timer to count up the time for a move
	Snake snek;							//snek object
	Board brd;							//board object	
	Location delta;						//location object to move by
	std::mt19937 rng;					//random object to respawn goals
	std::random_device rd;				//ranon object
	Goals goals;						//goal object
	float snekMovePeriod;				//the period of frames the snek moves by	
	float snekCounter;					//counts the frames passed from last move
	bool isGameOver;					//checks for game over
	Obstacles obs;						//obstackes object
	int addObs;							//counter to check if the snak ate enough targets to add obs
	static constexpr int obsRate = 1;	//obstacle spawn rate
	SpeedObstacles speedObs;			//the speed obstacles object
	bool isStarted;						//checks for game srated
	Surface preGame;					//screen for the pregame
	Surface postGame;					//screen for game over
	/********************************/
};