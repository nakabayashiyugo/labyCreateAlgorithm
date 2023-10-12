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

void WallStretch::Expansion(int _stdX, int _stdY)
{
	if (laby[_stdX][_stdY].isWall != 1)
	{
		laby[_stdX][_stdY].isWall = 1;
		laby[_stdX][_stdY].isExpanding = true;
	}
	else
	{
		Investigation();
		return;
	}

	bool dircheck[4] = { false, false, false, false };
	while (dircheck[0] != true && dircheck[1] != true &&
		dircheck[2] != true && dircheck[3] != true)
	{
		int dir = (rand() % 4) + 1;
		switch (dir)
		{
			dircheck[dir - 1] = true;
		case 1:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX][_stdY + 1].isWall == 0 &&
					laby[_stdX][_stdY + 2].isExpanding == false)
				{
					if (laby[_stdX][_stdY + 2].isWall == 1)
					{
						laby[_stdX][_stdY + 1].isWall = 1;
						Investigation();
						return;
					}
					else
					{
						Expansion(_stdX, _stdY + 1);
					}
				}
			}
			break;
		case 2:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX + 1][_stdY].isWall == 0 &&
					laby[_stdX + 2][_stdY].isExpanding == false)
				{
					if (laby[_stdX + 2][_stdY].isWall == 1)
					{
						laby[_stdX + 1][_stdY].isWall = 1;
						Investigation();
						return;
					}
					else
					{
						Expansion(_stdX + 1, _stdY);
					}
				}
			}
			break;
		case 3:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX][_stdY - 1].isWall == 0 &&
					laby[_stdX][_stdY - 2].isExpanding == false)
				{
					if (laby[_stdX][_stdY - 2].isWall == 1)
					{
						laby[_stdX][_stdY - 1].isWall = 1;
						Investigation();
						return;
					}
					else
					{
						Expansion(_stdX, _stdY - 1);
					}
				}
			}
			break;
		case 4:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX - 1][_stdY].isWall == 0 &&
					laby[_stdX - 2][_stdY].isExpanding == false)
				{
					if (laby[_stdX - 2][_stdY].isWall == 1)
					{
						laby[_stdX - 1][_stdY].isWall = 1;
						Investigation();
						return;
					}
					else
					{
						Expansion(_stdX - 1, _stdY);
					}
				}
			}
			break;
		}
	}
}

void WallStretch::Investigation()
{
	curStdNum_ = 0;
	for (int x = 0; x < massNum; x++)
	{
		for (int y = 0; y < massNum; y++)
		{
			if (laby[x][y].isStdWall == true && laby[x][y].isWall == 1)
			{
				curStdNum_++;
			}
			laby[x][y].isExpanding = false;
		}
	}
	if (curStdNum_ != stdNum_)
	{
		Expansion(((rand() % ((massNum / 2) - 1)) + 1) * 2, ((rand() % ((massNum / 2) - 1)) + 1) * 2);
	}
}

void WallStretch::PrintLaby()
{
}
