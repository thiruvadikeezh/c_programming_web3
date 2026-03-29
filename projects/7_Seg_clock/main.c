#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "raylib.h"


#define WIDTH  1000
#define HEIGHT 1000


float segment_width = 100;
float segment_height = 20;
float segment_thickness = 20;

void DrawSegment(Vector2 center, bool horizontal)
{
        int count = 6;

        Vector2 a, b, c, d, e, f;

        if (horizontal)
        {
            a = (Vector2){center.x - segment_width/2 - segment_thickness/2, center.y};
            b = (Vector2){center.x - segment_width/2, center.y + segment_height/2};
            c = (Vector2){center.x - segment_width/2, center.y - segment_height/2};
            d = (Vector2){center.x + segment_width/2, center.y + segment_height/2};
            e = (Vector2){center.x + segment_width/2, center.y - segment_height/2};
            f = (Vector2){center.x + segment_width/2 + segment_thickness/2, center.y};
        }

        else
        {

            a = (Vector2){center.x - segment_width/2 - segment_thickness/2, center.y};
            b = (Vector2){center.x - segment_width/2 - segment_thickness, center.y + segment_height/2};
            c = (Vector2){center.x - segment_width/2 , center.y + segment_height/2};
            d = (Vector2){center.x - segment_width/2 - segment_thickness, center.y + segment_width - segment_thickness/2};
            e = (Vector2){center.x - segment_width/2 , center.y + segment_width - segment_thickness/2};
            f = (Vector2){center.x - segment_width/2 - segment_thickness/2, center.y + segment_width};
        }



        Vector2 seg[] = {a, b, c, d, e, f};
        DrawTriangleStrip(seg, count, RAYWHITE);

}

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
        Vector2 center = {WIDTH/2, HEIGHT/2};
        DrawSegment(center, 0);
        DrawSegment(center, 1);
        EndDrawing();
    }

	return 0;
}

