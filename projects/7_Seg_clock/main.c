#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

// lib for crawing vector graphics
#include "raylib.h"

//includes
#include "segment.h"

// definign the windows 
#define WIDTH  1920
#define HEIGHT 1080

int main(int argc, char *argv[])
{
    InitWindow(WIDTH, HEIGHT, "7-Seg-Clock");

    while (!WindowShouldClose())
    {
        
        time_t current_time = time(NULL);
        struct tm *local = localtime(&current_time);
        
        int hrs = local->tm_hour;
        int min = local->tm_min;
        int sec = local->tm_sec;

        int h1 = hrs / 10;
        int h2 = hrs % 10;

        int m1 = min / 10;
        int m2 = min % 10;

        int s1 = sec / 10;
        int s2 = sec % 10;

        BeginDrawing();
        ClearBackground(WHITE);

        draw_segment(&hours[0], h1);
        draw_segment(&hours[1], h2);

        draw_segment(&minutes[0], m1);
        draw_segment(&minutes[1], m2);

        draw_segment(&seconds[0], s1);
        draw_segment(&seconds[1], s2);

        EndDrawing();
    }

	return 0;
}
