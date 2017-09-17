#include "GameConfig.h"

GameConfig::GameConfig()
{
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
				in >> dim;
			}
			else if (!str.compare("Speedup Rate"))
			{
				in >> Speedup;
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

int GameConfig::GetWidth()
{
	return width;
}

int GameConfig::GetHeight()
{
	return height;
}

int GameConfig::GetDim()
{
	return dim;
}

float GameConfig::GetSpeed()
{
	return Speedup;
}

int GameConfig::GetpAmount()
{
	return pAmount;
}

int GameConfig::GetfAmount()
{
	return fAmount;
}
