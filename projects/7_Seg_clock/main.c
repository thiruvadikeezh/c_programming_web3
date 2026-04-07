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

typedef struct segment{
    int a, b, c, d, e, f, g;
} segment;

// function for horizontal Segment which is top block 
void draw_horizontal(Vector2 center)
{
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
        DrawTriangleStrip(seg, count, LIME);

}

// function for vertical block which has left and rigth segment
void draw_vertical(Vector2 center)
{

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

    printf("CENTER: (%f, %f)\n", center.x, center.y);

    printf("a: (%f, %f)\n", a.x, a.y);
    printf("b: (%f, %f)\n", b.x, b.y);
    printf("c: (%f, %f)\n", c.x, c.y);
    printf("d: (%f, %f)\n", d.x, d.y);
    printf("e: (%f, %f)\n", e.x, e.y);
    printf("f: (%f, %f)\n", f.x, f.y);

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
