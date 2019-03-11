/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once
#include "Keyboard.h"
#include "Mouse.h"
#include "Transformer.h"
#include "Graphics.h"
#include "rng.h"

constexpr int radius = 7;
constexpr double PIR = 3.14159265358979323846 / 180;
constexpr int pam = 100;
class Particle {
private:
	double angle;
	int speed;
	Color color = Colors::White;
	double dx;
	double dy;
	void border() {
		//if (x+radius >= 700 || x-radius <= 100) dx *= -1;
		if (x + radius >= Graphics::ScreenWidth) {
			x -= radius;
			dx *= -1;
		}
		if (x - radius <= 0) {
			x += radius;
			dx *= -1;
		}
		//if (y+radius >= 550 || y-radius <= 100) dy *= -1;
		if (y + radius >= Graphics::ScreenHeight) {
			y -= radius;
			dy *= -1;
		}
		if (y - radius <= 0) {
			y += radius;
			dy *= -1;
		}

		//if (x+radius >= 720 || x-radius <= 90) x = 300;
		//if (y+radius >= 570 || y-radius <= 90) y = 300;
	}
public:
	
	int x;
	int y;
	void update() {
		x += dx;
		y += dy;
		border();
	}
	Particle() {
		std::uniform_int_distribution<int> ang(7, 360);
		std::uniform_int_distribution<int> posx(0+radius, Graphics::ScreenWidth-radius);
		std::uniform_int_distribution<int> posy(0 + radius, Graphics::ScreenHeight - radius);
		x = posx(gen);
		y = posy(gen);
		angle = ang(gen)*PIR;
		speed = 2;
		dx = cos(angle)*speed;
		dy = sin(angle)*speed;
	}
};
class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
public:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Particle parts[pam];
	Transformer ct;
};