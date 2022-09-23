//P01: UtilRand.h
#pragma once
#include <iostream>
#include <ctime>
using namespace std;

static void initRandom() {
	srand(time(nullptr));
}

static int generateRandomInRange(int min, int max) {
	return rand() % (max - min + 1) + min;
}
