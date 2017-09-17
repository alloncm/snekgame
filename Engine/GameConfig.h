#pragma once
#include<fstream>
#include<string>
class GameConfig
{
public:
	GameConfig();
	int GetWidth();
	int GetHeight();
	int GetDim();
	float GetSpeed();
	int GetpAmount();
	int GetfAmount();
private:
	int width;
	int height;
	int dim;
	float Speedup;
	int pAmount;
	int fAmount;
};