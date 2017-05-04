#include "header.h"

int turnLeft(int field[][FIELD_X], TANK * tank,int currentDir){
	int newDir;
	int y = tank->pointOnField.y;
	int x = tank->pointOnField.x;
	switch (currentDir)
	{
	case TOP:
	{
		field[y][x - 1] = tank->Nation;
		field[y - 1][x] = tank->Nation;
		field[y + 1][x] = tank->Nation;
		field[y - 1][x + 1] = tank->Nation;
		field[y + 1][x + 1] = tank->Nation;
		field[y + 1][x - 1] = NOBODY;
		field[y][x + 1] = NOBODY;
		newDir = LEFT;
		break;	
	}
	case RIGHT:
	{
		field[y - 1][x] = tank->Nation;
		field[y][x - 1] = tank->Nation;
		field[y][x + 1] = tank->Nation;
		field[y + 1][x - 1] = tank->Nation;
		field[y + 1][x + 1] = tank->Nation;
		field[y - 1][x - 1] = NOBODY;
		field[y + 1][x] = NOBODY;
		newDir = TOP;
		break;
	}
	case DOWN:
	{
		field[y][x + 1] = tank->Nation;
		field[y - 1][x] = tank->Nation;
		field[y - 1][x - 1] = tank->Nation;
		field[y + 1][x] = tank->Nation;
		field[y + 1][x - 1] = tank->Nation;
		field[y - 1][x + 1] = NOBODY;
		field[y][x - 1] = NOBODY;
		newDir = RIGHT;
		break;
	}
	case LEFT:
	{
		field[y + 1][x] = tank->Nation;
		field[y][x - 1] = tank->Nation;
		field[y][x + 1] = tank->Nation;
		field[y - 1][x - 1] = tank->Nation;
		field[y - 1][x + 1] = tank->Nation;
		field[y - 1][x] = NOBODY;
		field[y + 1][x + 1] = NOBODY;
		newDir = DOWN;
		break;
	 }
	
	}
	return newDir;
}

//*******************************

int turRight(int field[][FIELD_X], TANK * tank, int currentDir){

	int newDir;
	int y = tank->pointOnField.y;
	int x = tank->pointOnField.x;
	switch (currentDir)
	{
	case TOP:
	{
		field[y][x + 1] = tank->Nation;
		field[y - 1][x] = tank->Nation;
		field[y - 1][x - 1] = tank->Nation;
		field[y + 1][x] = tank->Nation;
		field[y + 1][x - 1] = tank->Nation;
		field[y][x - 1] = NOBODY;
		field[y + 1][x + 1] = NOBODY;
		newDir = RIGHT;
		break;
	}
	case RIGHT:
	{
		field[y + 1][x] = tank->Nation;
		field[y][x - 1] = tank->Nation;
		field[y][x + 1] = tank->Nation;
		field[y - 1][x - 1] = tank->Nation;
		field[y - 1][x + 1] = tank->Nation;
		field[y + 1][x - 1] = NOBODY;
		field[y - 1][x] = NOBODY;
		newDir = DOWN;
		break;
	}
	case DOWN:
	{
		field[y][x - 1] = tank->Nation;
		field[y - 1][x] = tank->Nation;
		field[y + 1][x] = tank->Nation;
		field[y - 1][x + 1] = tank->Nation;
		field[y + 1][x + 1] = tank->Nation;
		field[y - 1][x - 1] = NOBODY;
		field[y][x + 1] = NOBODY;
		newDir = LEFT;
		break;
	}
	case LEFT:
	{

		field[y - 1][x] = tank->Nation;
		field[y][x - 1] = tank->Nation;
		field[y][x + 1] = tank->Nation;
		field[y + 1][x - 1] = tank->Nation;
		field[y + 1][x + 1] = tank->Nation;
		field[y + 1][x] = NOBODY;
		field[y - 1][x + 1] = NOBODY;
		newDir = TOP;
		break;
	}
  }
	return newDir;
}

//*****************************************

void toGo(int field[][FIELD_X], TANK * tank,int currentDir){
	

	switch (currentDir)
	{
	case TOP:
	{
		if (permissionToGo(field, tank, TOP)){
			int y = (tank->pointOnField.y)-1;
			int x = tank->pointOnField.x;
			field[y][x] = tank->Nation;
			field[y - 1][x] = tank->Nation;
			field[y][x - 1] = tank->Nation;
			field[y][x + 1] = tank->Nation;
			field[y + 1][x - 1] = tank->Nation;
			field[y + 1][x + 1] = tank->Nation;
			field[y + 1][x] = NOBODY;
			field[y + 2][x - 1] = NOBODY;
			field[y + 2][x + 1] = NOBODY;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
		}
		break;
	}
	case RIGHT:
	{
		if (permissionToGo(field, tank, RIGHT)){
			int y = tank->pointOnField.y;
			int x = (tank->pointOnField.x) + 1;
			field[y][x] = tank->Nation;
			field[y][x + 1] = tank->Nation;
			field[y - 1][x] = tank->Nation;
			field[y - 1][x - 1] = tank->Nation;
			field[y + 1][x] = tank->Nation;
			field[y + 1][x - 1] = tank->Nation;
			field[y][x - 1] = NOBODY;
			field[y - 1][x - 2] = NOBODY;
			field[y + 1][x - 2] = NOBODY;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
		}
		break;
	}
	case DOWN:
	{
		if (permissionToGo(field, tank, DOWN)){
			int y = (tank->pointOnField.y) + 1;
			int x = tank->pointOnField.x;
			field[y][x] = tank->Nation;
			field[y + 1][x] = tank->Nation;
			field[y][x - 1] = tank->Nation;
			field[y][x + 1] = tank->Nation;
			field[y - 1][x - 1] = tank->Nation;
			field[y - 1][x + 1] = tank->Nation;
			field[y - 1][x] = NOBODY;
			field[y - 2][x - 1] = NOBODY;
			field[y - 2][x + 1] = NOBODY;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
		}
		break;
	}
	case LEFT:
	{
		if (permissionToGo(field, tank, LEFT)){
			int y = tank->pointOnField.y;
			int x = (tank->pointOnField.x) - 1;
			field[y][x] = tank->Nation;
			field[y][x - 1] = tank->Nation;
			field[y - 1][x] = tank->Nation;
			field[y + 1][x] = tank->Nation;
			field[y - 1][x + 1] = tank->Nation;
			field[y + 1][x + 1] = tank->Nation;
			field[y][x + 1] = NOBODY;
			field[y - 1][x + 2] = NOBODY;
			field[y + 1][x + 2] = NOBODY;
			tank->pointOnField.y = y;
			tank->pointOnField.x = x;
		}
		break;
	}
	}

}

//********************************

bool fire(int field[][FIELD_X], TANK * tank, int direction){
	int y = tank->pointOnField.y;
	int x = tank->pointOnField.x;
	
	switch (direction)
	{
	case TOP:
	{
		y  = y - 2;
		
		while (y >= 0 ){
				
				if (field[y][x] == ENEMY_TANK)
				{
					return true;
				}
				field[y][x] = BULLET;
				displayGame(field,0);
				field[y][x] = NOBODY;
				y--;
			}
		break;
	}
	case RIGHT:
	{
		x = x + 2;

		while (x < FIELD_X){

			if (field[y][x] == ENEMY_TANK)
			{
				return true;
			}
			field[y][x] = BULLET;
			displayGame(field,0);
			field[y][x] = NOBODY;
			x++;
		}
		break;
	}
	case DOWN:
	{
		y = y + 2;

		while (y < FIELD_Y){

			if (field[y][x] == ENEMY_TANK)
			{
				return true;
			}
			field[y][x] = BULLET;
			displayGame(field,0);
			field[y][x] = NOBODY;
			y++;
		}
		break;
	}
	case LEFT:
	{
		x = x - 2;

		while (x >= 0 ){

			if (field[y][x] == ENEMY_TANK)
			{
				return true;
			}
			field[y][x] = BULLET;
			displayGame(field,0);
			field[y][x] = NOBODY;
			x--;
		}
		break;
	}
	}
	return false;
}

//*****************************************************

void changeTankStatus(int field[][FIELD_X], TANK * tank){

	int y = tank->pointOnField.y;
	int x = tank->pointOnField.x;
	tank->Status = DEATH;

	field[y][x] = NOBODY;
	field[y + 1][x] = NOBODY;
	field[y - 1][x] = NOBODY;
	field[y][x - 1] = NOBODY;
	field[y][x + 1] = NOBODY;
	field[y + 1][x - 1] = NOBODY;
	field[y - 1][x - 1] = NOBODY;
	field[y + 1][x + 1] = NOBODY;
	field[y - 1][x + 1] = NOBODY;
		 
}
///-------------------------------------

bool permissionToGo(int field[][FIELD_X], TANK * tank, int direction){
	int y = tank->pointOnField.y;
	int x = tank->pointOnField.x;
	switch (direction)
	{
	case TOP:
	{
		if ((y - 2) < 0)
			return false;
		else if (field[y - 2][x] != NOBODY)
			return false;
		else if (field[y - 2][x - 1] != NOBODY)
			return false;
		else if (field[y - 2][x + 1] != NOBODY)
			return false;
		break;
	}
	case RIGHT:
	{
		if ((x + 2) > 49)
			return false;
		else if (field[y][x + 2] != NOBODY)
			return false;
		else if (field[y + 1][x + 2] != NOBODY)
			return false;
		else if (field[y - 1][x + 2] != NOBODY)
			return false;
		break;
	}
	case DOWN:
	{
		if ((y + 2) > 25)
			return false;
		else if (field[y + 2][x] != NOBODY)
			return false;
		else if (field[y + 2][x - 1] != NOBODY)
			return false;
		else if (field[y + 2][x + 1] != NOBODY)
			return false;
		break;
	}
	case LEFT:
	{
		if ((x - 2) < 0)
			return false;
		else if (field[y][x - 2] != NOBODY)
			return false;
		else if (field[y - 1][x - 2] != NOBODY)
			return false;
		else if (field[y + 1][x - 2] != NOBODY)
			return false;
		break;
	}
	}
	return true;
}
