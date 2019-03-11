#pragma once
#include <vector>
#include "v2.h"
#include "Graphics.h"
class Transformer {
public:
	Transformer(Graphics& gfx)
		:
		gfx( gfx )
	{}
	void drwLine(v2& v, Color c);

	double asp_ratio;

	void drwPath(std::vector<v2>* path, Color c);
	void drwCircle(int xc, int yc, int r, Color c);
	void plotCircle(int x, int y, int xc, int yc, Color c);
	void fillCircle(int x, int y, int r, Color c);
	v2 checkDist(int x0, int y0, int x1, int y1);
private:
	Graphics& gfx;
};