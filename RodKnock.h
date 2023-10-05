#pragma once
#include "labyCreate.h"
class RodKnock:
	public labyCreate
{
	struct labyElem
	{
		int isWall;
		bool isStdWall;
	}laby[massNum][massNum];
public:
	void Initialize() override;
	void Expansion() override;
	void PrintLaby() override;
};

