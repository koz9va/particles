#pragma once
#include <random>
#include <map>
#include <chrono>
static std::mt19937_64 gen{
	static_cast<unsigned long long>(
				std::chrono::system_clock::now().time_since_epoch().count()) 
};



//void setc(Game* g, int a, int b) {
//	std::uniform_int_distribution<int> com(a, b);
//	for (int i = 0; i < Am; i++)g->particles[i].x = com(gen);
//}