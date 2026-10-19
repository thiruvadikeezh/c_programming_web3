#include "raylib.h"

#include <stdio.h>

int main(void)
{
	int grid[4][4] ={
		{0,2,0,4},
		{4,0,4,8},
		{8,8,0,16},
		{32,0,0,32}
	};

	for (int i =0 ; i<4 ; i++)
	{
		int k =0;

		for(int j = 0; j < 4; j++)
		{
			int a = grid[i][j];
			if( a != 0)
			{
				grid[i][k] = grid[i][j];
				k++;
			}

		}
		while (k<4)
		{
			grid[i][k] =0;
			k++;
		}

		for(int j= 0; j<3; j++)
		{
			if ( grid[i][j] !=0 && grid[i][j] == grid[i][j+1])
			{
				grid[i][j] *=2;
				grid[i][j+1] =0;
			}

		}

	}

	for (int i =0 ; i<4 ; i++)
	{
		int k =0;

		for(int j = 0; j < 4; j++)
		{
			int a = grid[i][j];
			if( a != 0)
			{
				grid[i][k] = grid[i][j];
				k++;
			}

		}
		while (k<4)
		{
			grid[i][k] =0;
			k++;
		}

	}

	for(int i = 0; i <4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("[%d]", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}
