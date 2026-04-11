#ifndef SEGMENT_H
#define SEGMENT_H

#include <stdint.h>

#include "raylib.h"


extern uint8_t digits[];
extern Vector2 hours[];
extern Vector2 minutes[];
extern Vector2 seconds[];



void draw_horizontal(Vector2 center, int on);

void draw_vertical(Vector2 center, int on);

void draw_segment(Vector2 *center, int digit);

#endif
