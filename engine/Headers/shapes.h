#ifndef SHAPES_H_INCLUDED
#define SHAPES_H_INCLUDED

#include "engine.h"
#include <math.h>
#include <stdbool.h>

#ifdef __linux__
    #include <SDL2/SDL.h>
#endif

#ifdef _WIN32
    #include <SDL.h>
#endif

//Represents a point
typedef struct {
    double x, y;
} GE_Point;

//Represents a rectangle
typedef struct {
    double x, y, width, height;
} GE_Rect;

//Tests intersection between rects
bool GE_Rect_intersect(GE_Rect rect1, GE_Rect rect2);

//Gets a rect representing intersection between two other rects
GE_Rect GE_Rect_intersection(GE_Rect rect1, GE_Rect rect2);

//Draws a rect
void GE_Rect_draw(GE_GameInstance *game, GE_Rect rect);

//Fills a rect
void GE_Rect_fill(GE_GameInstance *game, GE_Rect rect);

//Represents a line
typedef struct {
    double x1, y1, x2, y2;
} GE_Line;

//Draws a line
void GE_Line_draw(GE_GameInstance *game, GE_Line line);

//Detects line intersection
bool GE_Line_intersect(GE_Line line1, GE_Line line2);

//Returns the intersection point between two lines
//If the lines don't intersect, returns (-1, -1)
GE_Point GE_Line_getIntersection(GE_Line line1, GE_Line line2);

#endif // SHAPES_H_INCLUDED
