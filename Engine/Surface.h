#pragma once
#include"Colors.h"
#include<string>
#include"ChiliWin.h"
#include<fstream>
class Surface
{
public:
	Surface(int w, int h);
	Surface(const Surface& s);
	Surface(const std::string& filename);
	Surface& operator=(const Surface& s);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y) const;
	int GetWidht()const;	
	int GetHeight()const;
	~Surface();
private:
	Color* pPixels = nullptr;
	int width;
	int height;
};