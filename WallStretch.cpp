#include "WallStretch.h"

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
	PrintLaby();
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

	bool dircheck[4] = { false, false, false, false };
	bool wallHit = false;
	while (dircheck[0] == false || dircheck[1] == false ||
		dircheck[2] == false || dircheck[3] == false)
	{
		if (wallHit != false)
		{
			break;
		}
		int dir = (rand() % 4) + 1;
		switch (dir)
		{
		case 1:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX][_stdY + 1].isWall == 0 &&
					laby[_stdX][_stdY + 2].isExpanding == false &&
					laby[_stdX + 1][_stdY + 1].isWall == false && //‰E
					laby[_stdX - 1][_stdY + 1].isWall == false && //¶
					laby[_stdX + 1][_stdY + 2].isExpanding == false && //‰E‰º
					laby[_stdX - 1][_stdY + 2].isExpanding == false)  //¶‰º
				{
					if (laby[_stdX][_stdY + 2].isWall == 1)
					{
						laby[_stdX][_stdY + 1].isWall = 1;
						Investigation();
						wallHit = true;
						return;
					}
					else
					{
						Expansion(_stdX, _stdY + 1);
					}
				}
				dircheck[0] = true;
			}
			break;
		case 2:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX + 1][_stdY].isWall == 0 &&
					laby[_stdX + 2][_stdY].isExpanding == false &&
					laby[_stdX + 1][_stdY + 1].isWall == false &&
					laby[_stdX + 1][_stdY - 1].isWall == false &&
					laby[_stdX + 2][_stdY + 1].isExpanding == false &&
					laby[_stdX + 2][_stdY - 1].isExpanding == false)
				{
					if (laby[_stdX + 2][_stdY].isWall == 1)
					{
						laby[_stdX + 1][_stdY].isWall = 1;
						Investigation();
						wallHit = true;
						return;
					}
					else
					{
						Expansion(_stdX + 1, _stdY);
					}
				}
				dircheck[1] = true;
			}
			break;
		case 3:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX][_stdY - 1].isWall == 0 &&
					laby[_stdX][_stdY - 2].isExpanding == false &&
					laby[_stdX + 1][_stdY - 1].isWall == false &&
					laby[_stdX - 1][_stdY - 1].isWall == false &&
					laby[_stdX + 1][_stdY - 2].isExpanding == false &&
					laby[_stdX - 1][_stdY - 2].isExpanding == false)
				{
					if (laby[_stdX][_stdY - 2].isWall == 1)
					{
						laby[_stdX][_stdY - 1].isWall = 1;
						Investigation();
						wallHit = true;
						return;
					}
					else
					{
						Expansion(_stdX, _stdY - 1);
					}
				}
				dircheck[2] = true;
			}
			break;
		case 4:
			if (dircheck[dir - 1] == false)
			{
				if (laby[_stdX - 1][_stdY].isWall == 0 &&
					laby[_stdX - 2][_stdY].isExpanding == false &&
					laby[_stdX - 1][_stdY + 1].isWall == false &&
					laby[_stdX - 1][_stdY - 1].isWall == false &&
					laby[_stdX - 2][_stdY + 1].isExpanding == false &&
					laby[_stdX - 2][_stdY - 1].isExpanding == false)
				{
					if (laby[_stdX - 2][_stdY].isWall == 1)
					{
						laby[_stdX - 1][_stdY].isWall = 1;
						Investigation();
						wallHit = true;
						return;
					}
					else
					{
						Expansion(_stdX - 1, _stdY);
					}
				}
				dircheck[3] = true;
			}
			break;
		}
	}
	int i = 0;
	if (wallHit != true)
	{
		while (i < 5)
		{
			switch (i)
			{
			case 0:
				if (laby[_stdX][_stdY + 1].isExpanding == true)
				{
					Expansion(_stdX, _stdY + 1);
				}
				break;
			case 1:
				if (laby[_stdX + 1][_stdY].isExpanding == true)
				{
					Expansion(_stdX + 1, _stdY);
				}
				break;
			case 2:
				if (laby[_stdX][_stdY - 1].isExpanding == true)
				{
					Expansion(_stdX, _stdY - 1);
				}
				break;
			case 3:
				if (laby[_stdX - 1][_stdY].isExpanding == true)
				{
					Expansion(_stdX - 1, _stdY);
				}
				break;
			default:
				Investigation();
			}
			i++;
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
				std::cout << "¡";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
