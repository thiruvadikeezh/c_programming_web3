#include "segment.h"

// defining the segment led sizes
#define segment_width 50
#define segment_height 30
#define segment_thickness 20

#define circle_radius 10

uint8_t digits[10] = {
    0b0111111, // 0
    0b0000110, // 1
    0b1011011, // 2
    0b1001111, // 3
    0b1100110, // 4
    0b1101101, // 5
    0b1111101, // 6
    0b0000111, // 7
    0b1111111, // 8
    0b1101111  // 9
};

// defining the hours offset
Vector2 hours[] = {
    (Vector2){180, 480},
    (Vector2){290, 480}
};

Vector2 minutes[] = {
    (Vector2){460, 480},
    (Vector2){570, 480}
};

Vector2 seconds[] = {
    (Vector2){740, 480},
    (Vector2){850, 480}
};

Vector2 colons[] = {
    (Vector2){100, 100},
    (Vector2){100, 500}
};

typedef struct segment{
    Vector2 A, B, C, D, E, F, G;
} segment;

Color my_gray = (Color){80, 80, 80, 60};
Color my_black = (Color){0, 0, 0, 255};

// function for hiorizontal Segment which is top block 
void draw_horizontal(Vector2 center, int on)
{

    Color color = on ? my_black : my_gray;

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

    Color color = on ? my_black : my_gray;

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

void draw_colon(Vector2 center, bool on)
{
    Color color = on ? my_black : my_gray;

    DrawCircle(center.x, center.y, circle_radius, color);

    DrawCircle(center.x, center.y+100, circle_radius, color);

}


void draw_segment(Vector2 *center, int digit)
{
    uint8_t pattern = digits[digit];

    segment val;

    float half_wid = segment_width/2;

    float half_thick = segment_thickness/2;

    float edge = half_wid + half_thick;

    val.A = (Vector2){center->x, center->y};
    val.B = (Vector2){center->x + edge, center->y+edge};
    val.C = (Vector2){center->x + edge, center->y+edge*3};
    val.G = (Vector2){center->x, center->y + edge*2};
    val.E = (Vector2){center->x - edge, center->y+edge*3};
    val.F = (Vector2){center->x - edge, center->y+edge};
    val.D = (Vector2){center->x, center->y+edge*4};


    draw_horizontal(val.A, (pattern >> 0) & 1);
    draw_vertical(val.B,   (pattern >> 1) & 1);
    draw_vertical(val.C,   (pattern >> 2) & 1);
    draw_horizontal(val.D, (pattern >> 3) & 1);
    draw_vertical(val.E,   (pattern >> 4) & 1);
    draw_vertical(val.F,   (pattern >> 5) & 1);
    draw_horizontal(val.G, (pattern >> 6) & 1);
}
