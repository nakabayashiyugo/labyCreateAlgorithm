#include "WallStretch.h"

int dir[4] = { 0, 0, 0, 0 };

void WallStretch::Initialize()
{
	stdNum_ = 0;
	for (int x = 0; x < massNum; x++)
	{
		for (int y = 0; y < massNum; y++)
		{
			laby[x][y].isWall = 0;
			if (x == 0 || y == 0 || x == massNum - 1 || y == massNum - 1)
			{
				laby[x][y].isWall = 1;
			}
			if (x % 2 == 0 && y % 2 == 0)
			{
				laby[x][y].isStdWall = true;
				stdNum_++;
			}
			else
			{
				laby[x][y].isStdWall = false;
			}
			laby[x][y].isExpanding = false;
		}
	}
}

void WallStretch::Expansion(int _stdX, int _stdY)
{
	std::cout << _stdX << ", " << _stdY << std::endl;
	std::cout << std::endl;
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
	PrintLaby();
	int x = _stdX, y = _stdY;
	do
	{
		int random = (rand() % 4);
		
		dir[random] = 1;

		x += dir[0];
		x -= dir[1];
		y += dir[2];
		y -= dir[3];

		if (laby[x][y].isWall == 0)
		{
			dir[random] = 0;
			break;
		}

		dir[random] = 0;
	} while (true);
	Expansion(x, y);

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
		//srand(time(NULL));
		int randX, randY;
		do {
			randX = rand() % massNum;
			randY = rand() % massNum;
		} while (randX % 2 != 0 || randY % 2 != 0);
		Expansion(randX, randY);
	}
}

void WallStretch::PrintLaby()
{
	for (int x = 0; x < massNum; x++)
	{
		for (int z = 0; z < massNum; z++)
		{
			if (laby[x][z].isWall)
			{
				if (laby[x][z].isExpanding)
				{
					std::cout << "£";
				}
				else
				{
					std::cout << "¡";
				}
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
