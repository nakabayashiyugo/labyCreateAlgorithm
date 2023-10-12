#include <iostream>
#include "RodKnock.h"
#include "WallStretch.h"

int main()
{
	WallStretch rk;
	rk.Initialize();
	rk.Expansion(((rand() % ((massNum / 2) - 1)) + 1) * 2, ((rand() % ((massNum / 2) - 1)) + 1) * 2);
	rk.PrintLaby();
}