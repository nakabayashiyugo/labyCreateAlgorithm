#pragma once
#include "labyCreate.h"
class WallStretch :
	public labyCreate
{
	struct labyElem
	{
		int isWall;
		bool isStdWall;
		bool isExpanding;
	}laby[massNum][massNum];
	int stdNum_;
	int curStdNum_;
public:
	void Initialize() override;
	void Expansion(int _stdX, int _stdY);
	void Investigation();
	void PrintLaby() override;
};

