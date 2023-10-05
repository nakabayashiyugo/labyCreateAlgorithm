#include "WallStretch.h"

void WallStretch::Initialize()
{
	for (int x = 0; x < massNum; x++)
	{
		for (int y = 0; y < massNum; y++)
		{
			if (x == 0 || y == 0 || x == massNum - 1 || y == massNum)
			{
				laby[x][y].isWall = 1;
			}
			if (x % 2 == 0 && y % 2 == 0)
			{
				laby[x][y].isStdWall = true;
				stdNum_++;
			}
		}
	}
}

void WallStretch::Expansion()
{
	int stdX = ((rand() % ((massNum / 2) - 1)) + 1) * 2;
	int stdZ = ((rand() % ((massNum / 2) - 1)) + 1) * 2;

	if (laby[stdX][stdZ].isWall != 1)
	{
		laby[stdX][stdZ].isWall = 1;
	}
	else
	{
		Investigation();
		return;
	}
}

void WallStretch::Investigation()
{
	for (int x = 0; x < massNum; x++)
	{
		for (int y = 0; y < massNum; y++)
		{
			if (laby[x][y].isStdWall == true && laby[x][y].isWall == 1)
			{
				curStdNum_++;
			}
		}
	}
	if (curStdNum_ != stdNum_)
	{
		Expansion();
	}
}

void WallStretch::PrintLaby()
{
}
