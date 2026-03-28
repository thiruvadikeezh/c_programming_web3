#include <stdio.h>
#include <time.h>
#include "raylib.h"


#define WIDTH  1000
#define HEIGHT 1000

int main(int argc, char *argv[])
{
	time_t current_time = time(NULL);
	char *time_string = ctime(&current_time);


	printf("the current time is : %s\n", time_string);
    InitWindow(WIDTH, HEIGHT, "digital Clock");


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(50, 50, 300, 20, RAYWHITE);

        int count = 4;

        Vector2 q, w, r, t;

        q = (Vector2){50, 50};
        w = (Vector2){100, 100};
        r = (Vector2){80, 20};
        t = (Vector2){200, 30};

        Vector2 points[] = {q, w, r, t};
        DrawTriangleStrip(points, count, SKYBLUE);

        count = 6;
        Vector2 center = {WIDTH/ 2, HEIGHT/ 2};
        float segment_width = 200;
        float segment_height = 50;
        float segment_thickness = 50;
        Vector2 a, b, c, d, e, f;

        a = (Vector2){center.x - segment_width/2 - segment_thickness , center.y};
        
        b = (Vector2){center.x - segment_width/2 , center.y + segment_height/2};
        c = (Vector2){center.x - segment_width/2 , center.y - segment_height/2};
        d = (Vector2){center.x + segment_width/2 , center.y + segment_height/2};
        e = (Vector2){center.x + segment_width/2 , center.y - segment_height/2};

        f = (Vector2){center.x + segment_width/2 + segment_thickness , center.y};

        Vector2 seg[] = {a, b, c, d, e, f};
        DrawTriangleStrip(seg, count, RAYWHITE);
        EndDrawing();
    }



	return 0;
}

