#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <windows.h>


int main() {

	Game game;
	int i = 0;
	while (game.run) {
		std::vector<line> ln = game.update();
		
		std::cout << i << '/b';

		if (std::getchar() == 'e') game.run = false;
		Sleep(1000);
	}

	return 0;
}
