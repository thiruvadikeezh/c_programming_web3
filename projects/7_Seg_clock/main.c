#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

// lib for crawing vector graphics
#include "raylib.h"

//includes
#include "segment.h"

// definign the windows 
#define WIDTH  1000
#define HEIGHT 1000

int main(int argc, char *argv[])
{
	time_t current_time = time(NULL);
	char *time_string = ctime(&current_time);


	printf("the current time is : %s\n", time_string);
    InitWindow(WIDTH, HEIGHT, "7-Seg-Clock");


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        draw_segment(&hours[0], 0);
        draw_segment(&hours[1], 1);

        draw_segment(&minutes[0], 2);
        draw_segment(&minutes[1], 3);

        draw_segment(&seconds[0], 4);
        draw_segment(&seconds[1], 5);

        EndDrawing();
    }

	return 0;
}
