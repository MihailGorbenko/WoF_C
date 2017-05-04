#include "header.h"


int main()
{
	int field[FIELD_Y][FIELD_X] = { 0 }; //BATTLE FIELD
	srand(time(NULL));
	int score = 10;
	int killed = 0;
	int curDir = TOP;
	int ACTION;
	///// TANKS_____________________
	TANK mTank;
	TANK * mainTank = &mTank;
	
	TANK * EnemyTanks = (TANK *)malloc(10 * sizeof(TANK));
	//------------------------------
	tankPlacing(field, mainTank, 10, 19, MAIN_TANK, curDir); // NAIN  TANK
	while (score != 0){
		bool hit = false;
		int stepsCount = 8;
		autoPlacing(field,&EnemyTanks[score-1], ENEMY_TANK);   // ENEMY  TANK
		displayGame(field,stepsCount);
		
		printf("\n\n  SCORE : = %d  ", score);
		while ( !hit  ){

			ACTION = readKeyboard();
			if (ACTION != 0){
				switch (ACTION)
				{
				case TOP:
				{
					stepsCount--;
					toGo(field, mainTank, curDir);
					displayGame(field, stepsCount);
					
					break;

				}
				case LEFT:
				{
					curDir = turnLeft(field, mainTank, curDir);
					displayGame(field, stepsCount);
					stepsCount--;
					break;
				}
				case RIGHT:
				{
					curDir = turRight(field, mainTank, curDir);
					displayGame(field, stepsCount);
					stepsCount--;
					break;
				}
				case SPACE:
				{
					hit = fire(field, mainTank, curDir);
					if (hit){
						changeTankStatus(field, &EnemyTanks[score - 1]);
						score--;
						killed++;
					}
					displayGame(field, stepsCount);
					break;
				}
			   }
			 }
			if (stepsCount <= 0){
				changeTankStatus(field, &EnemyTanks[score - 1]);
				score--;
				break;
			}	 
		}
	}
	printf("\n                    GAME OVER\n\n");
	printf("\n                     KILLED == %d\n\n",killed);
	free(EnemyTanks);
	return 0;
}