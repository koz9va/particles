#pragma once
#include "math.h"
#include "Particle.h"
#include <vector>
struct line {
	float op;
	int sx;
	int sy;
	int sz;
	int ex;
	int ey;
	int ez;
};
class Game
{
private:
	int lmax;
public:
	bool run;
	Particle particles[Am];
	Game();
	void stop();
	std::vector<line> update();
	~Game();
};

