#pragma once
#include "Transformer.h"

void Transformer::drwLine(v2& v, Color c) {
	bool yLonger = false;
	int incrementVal;
	int shortLen = v.y1 - v.y0;
	int longLen = v.x1 - v.x0;
	if (abs(shortLen) > abs(longLen)) {
		int swap = shortLen;
		shortLen = longLen;
		longLen = swap;
		yLonger = true;
	}
	if (longLen < 0) incrementVal = -1;
	else incrementVal = 1;

	double divDiff;
	if (shortLen == 0)divDiff = longLen;
	else divDiff = (double)longLen / (double)shortLen;
	if (yLonger) {
		for (int i = 0; i != longLen; i += incrementVal) {
			gfx.PutPixel(v.x0 + (int)((double)i / divDiff), v.y0 + i, c);
		}
	}
	else {
		for (int i = 0; i != longLen; i += incrementVal) {
			gfx.PutPixel(v.x0 + i, v.y0 + (int)((double)i / divDiff), c);
		}
	}
}

void Transformer::drwPath(std::vector<v2>* path, Color c) {
	for (auto& v : *path) {
		drwLine(v, c);
	}
}

void Transformer::drwCircle(int xc, int yc, int r, Color c) {
	int y, x, delta;
	asp_ratio = 1.0;
	y = r;
	delta = 3 - 2 * r;
	for (x = 0; x < y;) {
		plotCircle(x, y, xc, yc, c);
		if (delta < 0) {
			delta += 4 * x + 6;
		}
		else {
			delta += 4 * (x - y) + 10;
			y--;
		}
		x++;
	}
	x = y;
	if (y) plotCircle(x, y, xc, yc, c);
}

void Transformer::plotCircle(int x, int y, int xc, int yc, Color c) {
	int  x1, y1;
	int startx = x * asp_ratio;
	int starty = y * asp_ratio;
	int endy = (y + 1)*asp_ratio;
	int endx = (x + 1)*asp_ratio;
	for (x1 = startx; x1 < endx; ++x1) {
		gfx.PutPixel(x1 + xc, y + yc, c);
		gfx.PutPixel(x1 + xc, yc - y, c);
		gfx.PutPixel(xc - x1, y + yc, c);
		gfx.PutPixel(xc - x1, yc - y, c);
	}
	for (y1 = starty; y1 < endy; ++y1) {
		gfx.PutPixel(y1 + xc, x + yc, c);
		gfx.PutPixel(y1 + xc, yc - x, c);
		gfx.PutPixel(xc - y1, x + yc, c);
		gfx.PutPixel(xc - y1, yc - x, c);
	}
}
void Transformer::fillCircle(int x, int y, int r, Color c) {
	while (r) {
		drwCircle(x, y, r, c);
		r--;
	}
}
v2 Transformer::checkDist(int x0, int y0, int x1, int y1) {
	v2 dv(x0, y0, x1, y1);
	if (dv.len > 30) {
		dv.drw = true;
	}
	return dv;
}