#pragma once

const int Am = 60;
const int wi = 400;
const int he = 400;
const int l = 400;

class Particle
{
public:
	double ang[2];
	int dx = 1;
	int dy = 1;
	int dz = 1;
	double xAngle;
	double yAngle;
	double lAngle;

	double x;
	double y;
	double z;
	void border() {
		if (x >= wi - (y*xAngle) || x <= y * xAngle) {
			dx *= -1;
		}
		if (y >= he - (x * yAngle) || y <= x * yAngle) {
			dy *= -1;
		}
		if (z >= l - (y*xAngle) || z <= y * xAngle) {
			dz *= -1;
		}
	}
	void process() {
		x += dx * sin(ang[0])*cos(ang[1]);
		y += dy * sin(ang[0])*sin(ang[1]);
		z += dz * cos(ang[0]);
	}
	Particle() {

	};
};

