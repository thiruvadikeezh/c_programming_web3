#include <raylib.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 1920
#define HEIGHT 1080

#define BG BLACK

#define BORDER_COLOR WHITE
#define SMALL_COLOR RED

#define BORDER_SIZE (HEIGHT/2)

#define GRID_COUNT 4

#define CELL_SIZE (BORDER_SIZE/GRID_COUNT)

#define BORDER_X ((WIDTH - BORDER_SIZE) / 2 )
#define BORDER_Y ((HEIGHT - BORDER_SIZE) / 2 )

typedef struct
{
	int grid_x;
	int grid_y;
} grid;

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
}

void border_square_init(Vector2 *border_size, Vector2 *border_pos)
{
	*border_size = (Vector2){BORDER_SIZE, BORDER_SIZE};

	*border_pos = (Vector2){
		BORDER_X,
		BORDER_Y
	};
}

void small_square_init(
	const grid grid,
	Vector2 *small_size,
	Vector2 *small_pos
)
{

	*small_size = (Vector2) { CELL_SIZE, CELL_SIZE};

	*small_pos = (Vector2 ) { 
		BORDER_X + grid.grid_x * CELL_SIZE,
		BORDER_Y + grid.grid_y * CELL_SIZE,
	};
}

void calculate_position(int grid_x, int grid_y, Vector2 *small_pos)
{
	*small_pos = (Vector2){
		BORDER_X + grid_x * CELL_SIZE,
		BORDER_Y + grid_y * CELL_SIZE
	};
}

int empty(int board [][4])
{
	int empty_count = 0;

	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j< 4; j++)
		{
			if( board[i][j] == 0)
			{
				empty_count++;
			}
		}
	}

	return empty_count;
}

void spawn_tile(int board[][4])
{
    int empty_count = empty(board);

    if (empty_count == 0)
        return;

    int random_index = GetRandomValue(0, empty_count - 1);
    int seen = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                if (seen == random_index)
                {
                    board[i][j] = 2;
                    return;
                }

                seen++;
            }
        }
    }
}

void update_position(int board[][4])
{
	int before[4][4];
	memcpy(before, board, sizeof(before));

    if (IsKeyPressed(KEY_RIGHT))
	{
		move_right(board);
	}

    else if (IsKeyPressed(KEY_LEFT))
	{
		move_left(board);
	}

    else if (IsKeyPressed(KEY_UP))
	{
		move_up(board);
	}

    else if (IsKeyPressed(KEY_DOWN))
	{
		move_down(board);
	}

	if( memcmp(before, board, sizeof(before)) != 0)
		spawn_tile(board);
}


int main(void)
{
	grid grid = {1, 1};

	Vector2 border_size = {0};
	Vector2 border_pos = {0};

	Vector2 small_size = {0};
	Vector2 small_pos = {0};

	int board[GRID_COUNT][GRID_COUNT] = {0};
	
	border_square_init(&border_size, &border_pos);
	small_square_init(grid, &small_size, &small_pos);

	InitWindow(WIDTH, HEIGHT, "2048");

	spawn_tile(board);
	spawn_tile(board);

	while(!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(BG);
		
		DrawRectangleV(border_pos, border_size, BORDER_COLOR);

		update_position(board);

		for(int i = 0; i<4;i++)
		{
			for(int j = 0 ; j<4; j++)
			{
				if(board[i][j] != 0)
				{
					calculate_position(j, i, &small_pos);
					DrawRectangleV(small_pos, small_size, SMALL_COLOR);
					char text[12];
					snprintf(text, sizeof(text), "%d", board[i][j]);
					DrawText(text, (int)small_pos.x, (int)small_pos.y, 30, GREEN);
				}
			}
		}
		

		/*
		DrawRectangleV(small_pos, small_size, SMALL_COLOR);
		*/

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
