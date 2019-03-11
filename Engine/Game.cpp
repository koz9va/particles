/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include <cmath>
#include "MainWindow.h"
#include "Game.h"
#include "v2.h"



Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ct( gfx )
{
	for (int i = 0; i < pam; i++) {
		parts[i] = Particle();
	}
}

Color rgba(int r, int g, int b, float a) {
	r = ((1 - a)*0)+(a)*r;
	g = ((1 - a) * 0) + (a)*g;
	b = ((1 - a) * 0) + (a)*b;
	return Color(r, g, b);

}
void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel() {
	for (int i = 0; i < pam; i++) {
		parts[i].update();
	}
}

void Game::ComposeFrame() {
	v2 line(200,200, 100,100);
	std::vector<v2>* psq = new std::vector<v2>;
	psq->push_back(v2(200, 200, 300, 200));
	psq->push_back(v2(300, 200, 300, 100));
	psq->push_back(v2(300, 100, 200, 100));
	psq->push_back(v2(200, 100, 200, 200));
	ct.drwLine(line, Colors::Red);
	ct.drwPath(psq, Colors::White);
	ct.fillCircle(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2, 10, Colors::White); // just tests of methods



	for (int i = 0; i < pam; i++) {
		ct.fillCircle(parts[i].x, parts[i].y, radius, Colors::White);
		for (int j = i + 1; j < pam; j++) {
			double l = 0.0;
			l = sqrt(pow((parts[j].x - parts[i].x), 2) + pow((parts[j].y - parts[i].y), 2));
			if (l < 150) {
				v2* tv = new v2(parts[i].x, parts[i].y, parts[j].x, parts[j].y);
				ct.drwLine(*tv, rgba(0, 255, 0, 1-(l/150)));
				delete tv;
			}
		}
	}
}
