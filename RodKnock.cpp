#include "RodKnock.h"

void RodKnock::Initialize()
{
	for (int x = 0; x < massNum; x++)
	{
		for (int y = 0; y < massNum; y++)
		{
			if (x == 0 || y == 0 || x == massNum - 1 || y == massNum)
			{
				laby[x][y].isWall = 1;
			}
		}
	}

	for (int x = 1; x < massNum - 1; x++)
	{
		for (int y = 1; y < massNum - 1; y++)
		{
			if (x % 2 == 0 && y % 2 == 0)
			{
				laby[x][y].isWall = 1;
				laby[x][y].isStdWall = true;
			}
			else
			{
				laby[x][y].isWall = 0;
			}
		}
	}
}

void RodKnock::Expansion()
{
	for (int x = 1; x < massNum - 1; x++)
	{
		for (int y = 1; y < massNum - 1; y++)
		{
			if (laby[x][y].isStdWall == true)
			{
				int dirMv = (rand() % 4) + 1;
				switch (dirMv)
				{
				case 1:laby[x][y + 1].isWall = 1; break;
				case 2:laby[x + 1][y].isWall = 1; break;
				case 3:laby[x][y - 1].isWall = 1; break;
				case 4:laby[x - 1][y].isWall = 1; break;
				}
			}
		}
	}
}

void RodKnock::PrintLaby()
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
