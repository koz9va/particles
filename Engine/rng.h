#pragma once
#include <random>
#include <map>
#include <chrono>
static std::mt19937_64 gen{
	static_cast<unsigned long long>(
				std::chrono::system_clock::now().time_since_epoch().count())
};

