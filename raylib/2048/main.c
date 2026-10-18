#include <raylib.h>

#define WIDTH 1920

#define HEIGHT 1080

#define BG BLACK

int main(void)
{
	InitWindow(WIDTH, HEIGHT, "2048");
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BG);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
