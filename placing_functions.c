#include "header.h"

bool tankPlacing(int field[][FIELD_X], TANK * tank, int y, int x, int tankNation, int direction){

	switch (direction)
	{
	case TOP:{
		if (colissionDetection(field, y, x))
		{
			tank->Nation = tankNation;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
			tank->Status = ALIVE;
			field[y][x] = tankNation;
			field[y - 1][x] = tankNation;
			field[y][x - 1] = tankNation;
			field[y][x + 1] = tankNation;
			field[y + 1][x - 1] = tankNation;
			field[y + 1][x + 1] = tankNation;

			return true;
		}
		return false;
	}
	case RIGHT:
	{
		if (colissionDetection(field, y, x))
		{
			tank->Nation = tankNation;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
			tank->Status = ALIVE;
			field[y][x] = tankNation;
			field[y][x + 1] = tankNation;
			field[y - 1][x] = tankNation;
			field[y - 1][x - 1] = tankNation;
			field[y + 1][x] = tankNation;
			field[y + 1][x - 1] = tankNation;

			return true;
		}
		return false;
	}
	case DOWN:
	{
		if (colissionDetection(field, y, x))
		{
			tank->Nation = tankNation;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
			tank->Status = ALIVE;
			field[y][x] = tankNation;
			field[y + 1][x] = tankNation;
			field[y][x - 1] = tankNation;
			field[y][x + 1] = tankNation;
			field[y - 1][x - 1] = tankNation;
			field[y - 1][x + 1] = tankNation;

			return true;
		}
		return false;
	}
	case LEFT:
	{
		if (colissionDetection(field, y, x))
		{
			tank->Nation = tankNation;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
			tank->Status = ALIVE;
			field[y][x] = tankNation;
			field[y][x - 1] = tankNation;
			field[y - 1][x] = tankNation;
			field[y + 1][x] = tankNation;
			field[y - 1][x + 1] = tankNation;
			field[y + 1][x + 1] = tankNation;

			return true;
		}
		return false;
	}
	}
	return false;
}
//*******************************************

void autoPlacing(int field[][FIELD_X], TANK * tank,int nation){
	static int chooseDir = 1;
	int y = rand() % 20;
	int x = rand() % 40;
	int direction = chooseDir == 1 ? TOP : LEFT;
	while (tankPlacing(field, tank, y, x,nation,direction) == false){
		 y = rand() % 20;
		 x = rand() % 40;
	}
	chooseDir++;

}

//-----------------------------------------------

bool colissionDetection(int field[][FIELD_X], int y, int x){

	if (y < 1 || y > (FIELD_Y-2) || x < 1 || x > (FIELD_X-2))
		return false;
	else if (field[y][x] != NOBODY)
		return false;
	else if (field[y][x - 1] != NOBODY)
		return false;
	else if (field[y - 1][x - 1] != NOBODY)
		return false;
	else if (field[y - 1][x] != NOBODY)
		return false;
	else if (field[y - 1][x + 1] != NOBODY)
		return false;
	else if (field[y][x + 1] != NOBODY)
		return false;
	else if (field[y + 1][x + 1] != NOBODY)
		return false;
	else if (field[y + 1][x] != NOBODY)
		return false;
	else if (field[y + 1][x - 1] != NOBODY)
		return false;
	else
		return true;
}