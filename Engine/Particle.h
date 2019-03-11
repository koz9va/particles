#pragma once
#include "Colors.h"
#include "rng.h"

constexpr double PIR = 3.14159265358979323846 / 180;

class Particle {
private:
	double angle;
	int speed;
	Color color = Colors::White;
	float dx;
	float dy;
	void border() {
		if (x >= 800 ||x <= 0) dx *= -1;
		if (y >= 600 || y <= 0)dy *= -1;
	}
public:
	int x;
	int y;
	void update() {
		border();
		x += dx;
		y += dy;
	}
	Particle() {
		std::uniform_int_distribution<int> ang(0, 360);
		std::uniform_int_distribution<int> posx(0, 800);
		std::uniform_int_distribution<int> posy(0, 600);
		std::uniform_int_distribution<int> sp(0, 3);
		x = posx(gen);
		y = posy(gen);
		angle = ang(gen)*PIR;
		speed = sp(gen);
		dx = cos(angle)*speed;
		dy = sin(angle)*speed;
	}
	~Particle();
};