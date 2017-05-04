#include "header.h"

int readKeyboard(void){

	HANDLE Console = GetStdHandle(STD_INPUT_HANDLE);
	DWORD EventCount = 0;
	DWORD EventRead = 0;
	int keyPressed = 0;

	GetNumberOfConsoleInputEvents(Console, &EventCount);
	if (EventCount != 0)
	{
		INPUT_RECORD * eventBuffer = (INPUT_RECORD*)malloc((EventCount * sizeof(INPUT_RECORD)));

		ReadConsoleInput(Console, eventBuffer, EventCount, &EventRead);

		for (DWORD i = 0; i < EventRead; ++i)
		{
			if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown)
			{
				keyPressed = eventBuffer[i].Event.KeyEvent.wVirtualKeyCode;
			}
		}

		free(eventBuffer);
	}

	return keyPressed;
}
