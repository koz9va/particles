#include "v2.h"
#include <cmath>
double v2::getlen() {
	double l = 0.0;
	l = sqrt(pow((x1 - x0), 2) + pow((y1 - y0), 2));
	return l;
}

v2::v2(int x01, int y01, int x11, int y11) {
	x0 = x01;
	y0 = y01;
	x1 = x11;
	y1 = y11;
	len = getlen();
}


v2::~v2()
{
}
