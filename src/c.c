#include "genetic_behaviour.h"

void genetic_behaviour(char event, int* movement){ //caracteristica genetica
	if (event == 'a')
	{
		movement[0] = 2;
		movement[1] = 1;
		movement[2] = 0;
		movement[3] = 0;
	}
	else if (event == 'b')
	{
		movement[0] = 0;
		movement[1] = 0;
		movement[2] = 2;
		movement[3] = 0;
	}
	else if (event == 'c')
	{
		movement[0] = 2;
		movement[1] = 0;
		movement[2] = 1;
		movement[3] = 1;
	}
	else if (event == 'd')
	{
		movement[0] = 0;
		movement[1] = 0;
		movement[2] = 1;
		movement[3] = 1;
	}
	else if (event == 'e')
	{
		movement[0] = 1;
		movement[1] = 1;
		movement[2] = 0;
		movement[3] = 0;
	}
}