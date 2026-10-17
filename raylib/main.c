#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1920

#define HEIGHT 1080

int main( int argc, char *argv[])
{
	if( argc < 2)
	{

		printf(" no argument passed \n");
		return -1;
	}

	int n = atoi(argv[1]);


	InitWindow(WIDTH, HEIGHT, "Strobe");

	double startime = GetTime();
	double half = 1.0 / (2.0 * n);
	double nextSwitch = startime + half;

	bool isblack =true;

	while(!WindowShouldClose())
	{
		double currenttime=GetTime();

		if( currenttime >= nextSwitch)
		{
			isblack = !isblack;
			nextSwitch += half;
		}
		
		Color bg = isblack ? BLACK : WHITE;
		BeginDrawing();
		ClearBackground(bg);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}

