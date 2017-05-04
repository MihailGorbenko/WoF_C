#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <Windows.h>
#define FIELD_Y 20
#define FIELD_X 40
#define ALIVE 1
#define DEATH 0
#define BULLET 5

enum tanks {
	NOBODY = 0,
	MAIN_TANK = 1,
	ENEMY_TANK = 2,
};

enum directions {
	TOP =38,
	RIGHT = 39,
	DOWN = 40,
	LEFT = 37,
	SPACE = 32
};

typedef struct  POINT_ON_FIELD{
	int y;
	int x;
}PoF;

typedef struct TANK
{
	PoF pointOnField;
	int Status;
	int Nation;
} TANK;



int turnLeft(int field[][FIELD_X], TANK * tank,int currentDir);

int turRight(int field[][FIELD_X], TANK * tank,int currentDir);

int readKeyboard(void);

void toGo(int field[][FIELD_X], TANK * tank,int currentDir);

void displayGame(int field[][FIELD_X],int steps);

void changeTankStatus(int field[][FIELD_X], TANK * tank);

void autoPlacing(int field[][FIELD_X], TANK * tank,int nation);

bool fire(int field[][FIELD_X], TANK * tank, int direction);

bool tankPlacing(int field[][FIELD_X], TANK * tank,int direction);

bool colissionDetection(int field[][FIELD_X], int y, int x);

bool permissionToGo(int field[][FIELD_X], TANK * tank, int direction);