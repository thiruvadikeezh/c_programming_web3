#include <raylib.h>

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

void update_position(grid *grid, Vector2 *small_pos)
{
    if (IsKeyPressed(KEY_RIGHT) && grid->grid_x < GRID_COUNT - 1)
        grid->grid_x++;

    if (IsKeyPressed(KEY_LEFT) && grid->grid_x > 0)
        grid->grid_x--;

    if (IsKeyPressed(KEY_UP) && grid->grid_y > 0)
        grid->grid_y--;

    if (IsKeyPressed(KEY_DOWN) && grid->grid_y < GRID_COUNT - 1)
        grid->grid_y++;

    *small_pos = (Vector2){
        BORDER_X + grid->grid_x * CELL_SIZE,
        BORDER_Y + grid->grid_y * CELL_SIZE
    };
}
void move_left(int *board)
{


}
int main(void)
{
	grid grid = { 1, 1};

	Vector2 border_size = {0};
	Vector2 border_pos = {0};

	Vector2 small_size = {0};
	Vector2 small_pos = {0};


	int board[GRID_COUNT][GRID_COUNT] = {0};
	
	border_square_init(&border_size, &border_pos);
	small_square_init(grid, &small_size, &small_pos);

	InitWindow(WIDTH, HEIGHT, "2048");

	while(!WindowShouldClose())
	{

		BeginDrawing();
		ClearBackground(BG);
		update_position(&grid, &small_pos);

		DrawRectangleV(border_pos, border_size, BORDER_COLOR);
		DrawRectangleV(small_pos, small_size, SMALL_COLOR);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
