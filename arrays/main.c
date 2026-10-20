#include "raylib.h"

#include <stdio.h>

void move_left(int grid[][4])
{
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

}

void move_right(int grid[][4])
{
	for(int i = 0; i<4; i++)
	{
		int k =3;
		for(int j= 3; j >-1;j--)
		{
			if( grid[i][j] != 0)
			{
				grid[i][k] = grid[i][j];
				k--;
			}
		}

		while(k >-1)
		{
			grid[i][k] =0;
			k--;
		}
	

		for(int j = 3; j >0; j--)
		{
			if( grid[i][j] !=0 && grid[i][j]==grid[i][j-1])
			{
				grid[i][j] *=2;
				grid[i][j-1]=0;
			};
		}
	}
	
	for(int i = 0; i<4; i++)
	{
		int k =3;
		for(int j= 3; j >-1;j--)
		{
			if( grid[i][j] != 0)
			{
				grid[i][k] = grid[i][j];
				k--;
			}
		}

		while(k >-1)
		{
			grid[i][k] =0;
			k--;
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
}

void move_up( int grid[][4])
{
	for (int i =0 ; i<4 ; i++)
	{
		int k =0;

		for(int j = 0; j < 4; j++)
		{
			
			if( grid[j][i] != 0)
			{
				grid[k][i] = grid[j][i];
				k++;
			}

		}
		while (k<4)
		{
			grid[k][i] =0;
			k++;
		}

		for(int j= 0; j<3; j++)
		{
			if ( grid[j][i] !=0 && grid[j][i] == grid[j+1][i])
			{
				grid[j][i] *=2;
				grid[j+1][i] =0;
			}

		}

	}

	for (int i =0 ; i<4 ; i++)
	{
		int k =0;

		for(int j = 0; j < 4; j++)
		{
			if( grid[j][i]!= 0)
			{
				grid[k][i] = grid[j][i];
				k++;
			}

		}
		while (k<4)
		{
			grid[k][i] =0;
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

}

void move_down(int grid[][4])
{
	for(int i = 0; i<4; i++)
	{
		int k =3;
		for(int j= 3; j >-1;j--)
		{
			if( grid[j][i] != 0)
			{
				grid[k][i] = grid[j][i];
				k--;
			}
		}

		while(k >-1)
		{
			grid[k][i] =0;
			k--;
		}
	

		for(int j = 3; j >0; j--)
		{
			if( grid[j][i] !=0 && grid[j][i]==grid[j-1][i])
			{
				grid[j][i] *=2;
				grid[j-1][i]=0;
			};
		}
	}
	
	for(int i = 0; i<4; i++)
	{
		int k =3;
		for(int j= 3; j >-1;j--)
		{
			if( grid[j][i] != 0)
			{
				grid[k][i] = grid[j][i];
				k--;
			}
		}

		while(k >-1)
		{
			grid[k][i] =0;
			k--;
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
}


int main(void)
{
	int grid[4][4] ={
		{0,2,0,4},
		{4,0,4,8},
		{8,8,0,16},
		{32,0,0,32}
	};

	move_left(grid);

	move_right(grid);

	move_down(grid);

	move_up(grid);

	return 0;
}
