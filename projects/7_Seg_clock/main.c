#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// lib for crawing vector graphics
#include "raylib.h"

// definign the windows 
#define WIDTH  1000
#define HEIGHT 1000

// defining the segment led sizes
#define segment_width 200 
#define segment_height 50
#define segment_thickness 50

// defining the hours offset
Vector2 hours []={
    (Vector2){500, 500}
};

// function for horizontal Segment which is top block 
void draw_horizontal(Vector2 center)
{
        int count = 6;

        Vector2 a, b, c, d, e, f;
 
        float left_edge_hori = center.x - segment_width/2 - segment_thickness/2;
        float right_edge_hori = center.x + segment_width/2 + segment_thickness/2;

        a = (Vector2){left_edge_hori, center.y};
        b = (Vector2){center.x - segment_width/2, center.y + segment_height/2};
        c = (Vector2){center.x - segment_width/2, center.y - segment_height/2};
        d = (Vector2){center.x + segment_width/2, center.y + segment_height/2};
        e = (Vector2){center.x + segment_width/2, center.y - segment_height/2};
        f = (Vector2){right_edge_hori, center.y};


        Vector2 seg[] = {a, b, c, d, e, f};
        DrawTriangleStrip(seg, count, LIME);

}

// function for vertical block which has left and rigth segment
void draw_vertical(Vector2 center)
{

    int count = 6;

    Vector2 a, b, c, d, e, f;

    a = (Vector2){(center.x - segment_width/2 - segment_thickness/2), center.y};
    b = (Vector2){(center.x - segment_width/2 - segment_thickness), center.y + segment_height/2};
    c = (Vector2){(center.x - segment_width/2), center.y + segment_height/2};
    d = (Vector2){(center.x - segment_width/2 - segment_thickness), center.y + segment_width - segment_thickness/2};
    e = (Vector2){(center.x - segment_width/2), center.y + segment_width - segment_thickness/2};
    f = (Vector2){(center.x - segment_width/2 - segment_thickness/2), center.y + segment_width};

    Vector2 seg[] = {a, b, c, d, e, f};
    DrawTriangleStrip(seg, count, SKYBLUE);
                
}


void DrawSegment(Vector2 *center)
{
    draw_horizontal(* center);
    draw_vertical(* center);
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

        DrawSegment(hours);

        EndDrawing();
    }

	return 0;
}
