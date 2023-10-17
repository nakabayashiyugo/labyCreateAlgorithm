#include <iostream>
#include "RodKnock.h"
#include "WallStretch.h"

int main()
{
	srand(time(NULL));
	WallStretch rk;
	rk.Initialize();
	
	int randX, randY;
	do {
		randX = rand() % massNum;
		randY = rand() % massNum;
	} while (randX % 2 != 0 || randY % 2 != 0);
	rk.Expansion(randX, randY);
	rk.PrintLaby();
	
}