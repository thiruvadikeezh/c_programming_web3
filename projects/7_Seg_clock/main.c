#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "raylib.h"

// definign the windows 
#define WIDTH  1000
#define HEIGHT 1000

// defining the segment led sizes
#define segment_width  50
#define segment_height 10
#define segment_thickness  10

float hor_off = segment_width;

// defining the hours offset
Vector2 hours []={
    (Vector2){100, 400},
    (Vector2){250, 400}
};

// function for horizontal Segment which is top block 
void HorizontalSegment(Vector2 center)
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
        DrawTriangleStrip(seg, count, RAYWHITE);

}

// function for vertical block which has left and rigth segment
void VerticalSegment(Vector2 center)
{
    int count = 6;
    Vector2 a, b, c, d, e, f;

    float rig_seg = segment_width + segment_thickness;
    for (int i =0; i <2; i++)
    {

        a = (Vector2){(center.x - segment_width/2 - segment_thickness/2)+i * rig_seg, center.y};
        b = (Vector2){(center.x - segment_width/2 - segment_thickness)+i* rig_seg, center.y + segment_height/2};
        c = (Vector2){(center.x - segment_width/2)+i* rig_seg, center.y + segment_height/2};
        d = (Vector2){(center.x - segment_width/2 - segment_thickness)+i* rig_seg, center.y + segment_width - segment_thickness/2};
        e = (Vector2){(center.x - segment_width/2)+i* rig_seg, center.y + segment_width - segment_thickness/2};
        f = (Vector2){(center.x - segment_width/2 - segment_thickness/2)+i* rig_seg, center.y + segment_width};

        Vector2 seg[] = {a, b, c, d, e, f};
        DrawTriangleStrip(seg, count, RAYWHITE);
    }
            
}
//drawing the horizontal lines
void DrawHorizontal(Vector2 *off_array, int off_level)
{
    Vector2 base = off_array[off_level];

    for(int i = 0; i < 3; i++)
    {
        Vector2 center = {
            base.x,
            base.y + i * hor_off
            };
        HorizontalSegment(center);
    }
}

void DrawVertical(Vector2 *off_array, int off_level)
{
    Vector2 base = off_array[off_level];

    for(int i = 0; i < 2; i++)
    {
        Vector2 center = {
            base.x,
            base.y + i * hor_off
        };
        VerticalSegment(center);
    }
}

void DrawSegment(Vector2 *center)
{
    for(int i = 0; i < 2; i++)
    {
        DrawHorizontal(center, i);
        DrawVertical(center, i);
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

        DrawSegment(hours);

        EndDrawing();
    }

	return 0;
}
