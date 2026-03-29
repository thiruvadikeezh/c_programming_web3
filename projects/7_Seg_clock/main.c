#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "raylib.h"


#define WIDTH  1000
#define HEIGHT 1000

Vector2 hours []={
    (Vector2){100, 100},
    (Vector2){225, 100}
};


float segment_width = 100;
float segment_height = 20;
float segment_thickness = 20;

void DrawSegment(Vector2 center, bool horizontal)
{
        int count = 6;

        Vector2 a, b, c, d, e, f;
        
        float left_edge_hori = center.x - segment_width/2 - segment_thickness/2;
        float right_edge_hori = center.x + segment_width/2 + segment_thickness/2;

        if (horizontal)
        {
            a = (Vector2){left_edge_hori, center.y};
            b = (Vector2){center.x - segment_width/2, center.y + segment_height/2};
            c = (Vector2){center.x - segment_width/2, center.y - segment_height/2};
            d = (Vector2){center.x + segment_width/2, center.y + segment_height/2};
            e = (Vector2){center.x + segment_width/2, center.y - segment_height/2};
            f = (Vector2){right_edge_hori, center.y};
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

void DrawHorizontal(Vector2 *off_array, int off_level)
{
    Vector2 base = off_array[off_level];

    for(int i = 0; i < 3; i++)
    {
        Vector2 center = {
            base.x,
            base.y + i * 100
        };
        DrawSegment(center, true);
    }
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

        // DrawSegment(center, 0);
        // DrawSegment(center, 1);
        DrawHorizontal(hours, 0);
        EndDrawing();
    }

	return 0;
}

