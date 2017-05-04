#include "header.h"

void displayGame(int field[][FIELD_X],int steps){

	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { 0, 0 };
	SetConsoleCursorPosition(Console, Position);
	SetConsoleTextAttribute(Console, FOREGROUND_GREEN|FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	puts("\n         World Of Tanks (console version)\n");
	SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	
	for (int i = 0; i < FIELD_Y; i++){
		printf("     ");
		for (int j = 0; j < FIELD_X; j++){
			if (field[i][j] == NOBODY)
			{
				SetConsoleTextAttribute(Console, BACKGROUND_BLUE);
				printf(" ");
				SetConsoleTextAttribute(Console, 1);
			}
				
			else if (field[i][j] == MAIN_TANK)
			{
				SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				printf("%c", 'M');
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else if (field[i][j] == BULLET)
			{
				SetConsoleTextAttribute(Console, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				printf("%c", '0');
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
			else{
				SetConsoleTextAttribute(Console, FOREGROUND_RED | FOREGROUND_INTENSITY);
				printf("%c", 'E');
				SetConsoleTextAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			}
		
		}
		putchar('\n');
		
	}
	SetConsoleTextAttribute(Console, FOREGROUND_RED );
	printf("\n\n  STEPS : = %d  ", steps);
}
//********************************************

