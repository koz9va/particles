#include "Game.h"
#include "rng.h"
constexpr double PIR = 3.14159265358979323846/180;


Game::Game()
{
	run = true;
	lmax = 6;
	std::uniform_int_distribution<int> pos(0, wi);
	std::uniform_int_distribution<int> ang(0, 360);
	for (int i = 0; i < Am; i++) {
		particles[i].x = pos(gen);
		particles[i].y = pos(gen);
		particles[i].z = pos(gen);
		particles[i].ang[0] = PIR * ang(gen);
		particles[i].ang[1] = PIR * ang(gen);
	}
}

void Game::stop() {
	run = false;
}
std::vector<line> Game::update() {
	std::vector<line> lines;
	for (int i = 0; i < Am; i++) {
		particles[i].border();
		particles[i].process();
		for (int k = ++i; k < Am - i; k++) {
			double distance = sqrt(pow((particles[k].x - particles[i].x), 2) + pow((particles[k].y - particles[i].y), 2) + pow((particles[k].z - particles[i].z), 2));
			if (distance > 10) {
				line cl;
				cl.op = 1 - distance / lmax;
				cl.ex = particles[k].x;
				cl.sx = particles[i].x;
				cl.ey = particles[k].y;
				cl.sy = particles[i].y;
				cl.ez = particles[k].z;
				cl.sz = particles[i].z;
				lines.push_back(cl);
			}
		}
	}
	return lines;
}
Game::~Game()
{

}
