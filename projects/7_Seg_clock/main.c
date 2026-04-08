#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// lib for crawing vector graphics
#include "raylib.h"

// definign the windows 
#define WIDTH  1000
#define HEIGHT 1000

// defining the segment led sizes
#define segment_width 60
#define segment_height 30
#define segment_thickness 30

// defining the hours offset
Vector2 hours []={
    (Vector2){500, 500},
    (Vector2){700, 500}
};

typedef struct segment{
    Vector2 A, B, C, D, E, F, G;
} segment;

// function for horizontal Segment which is top block 
void draw_horizontal(Vector2 center, int on)
{
        Color color = on ? RED : DARKGRAY;

        int count = 6;

        Vector2 a, b, c, d, e, f;

        float half_wid = segment_width/2;

        float half_thick = segment_thickness/2;

        float edge = half_wid + half_thick;

        a = (Vector2){center.x - edge, center.y};
        b = (Vector2){center.x - half_wid, center.y + half_thick};
        c = (Vector2){center.x - half_wid, center.y - half_thick};
        d = (Vector2){center.x + half_wid, center.y + half_thick};
        e = (Vector2){center.x + half_wid, center.y - half_thick};
        f = (Vector2){center.x + edge, center.y};


        Vector2 seg[] = {a, b, c, d, e, f};
        DrawTriangleStrip(seg, count, color);

}

// function for vertical block which has left and rigth segment
void draw_vertical(Vector2 center, int on)
{

    Color color = on ? RED : DARKGRAY;
    int count = 6;

    Vector2 a, b, c, d, e, f;

    float half_wid = segment_width/2;

    float half_thick = segment_thickness/2;

    float edge = half_wid + half_thick;

    a = (Vector2){(center.x), center.y - edge};
    b = (Vector2){(center.x -half_thick), center.y - half_wid};
    c = (Vector2){(center.x + half_thick), center.y - half_wid};
    d = (Vector2){(center.x - half_thick), center.y + half_wid};
    e = (Vector2){(center.x + half_thick), center.y + half_wid};
    f = (Vector2){(center.x), center.y + edge};

    Vector2 seg[] = {a, b, c, d, e, f};
    DrawTriangleStrip(seg, count, color);
                
}


void DrawSegment(Vector2 *center)
{
    segment val;

    float half_wid = segment_width/2;

    float half_thick = segment_thickness/2;

    float edge = half_wid + half_thick;

    val.A = (Vector2){center->x, center->y};
    val.B = (Vector2){center->x + edge, center->y+edge};
    val.C = (Vector2){center->x + edge, center->y+edge*3};
    val.D = (Vector2){center->x, center->y + edge*2};
    val.E = (Vector2){center->x - edge, center->y+edge*3};
    val.F = (Vector2){center->x - edge, center->y+edge};
    val.G = (Vector2){center->x, center->y+edge*4};

    draw_horizontal(val.A, 1);
    draw_horizontal(val.D, 1);
    draw_horizontal(val.G, 1);

    draw_vertical(val.B, 1);
    draw_vertical(val.C, 1);

    draw_vertical(val.E, 0);
    draw_vertical(val.F, 0);
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

        DrawSegment(&hours[0]);
        DrawSegment(&hours[1]);

        EndDrawing();
    }

	return 0;
}
