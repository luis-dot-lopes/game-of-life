#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include "../Headers/engine.h"

//A struct representing red, green, blue and alpha values
typedef struct {
    int r, g, b, a;
} GE_Color;

//Declaration of some colors constants
extern const GE_Color GE_WHITE;
extern const GE_Color GE_BLACK;
extern const GE_Color GE_GREY;

extern const GE_Color GE_RED;
extern const GE_Color GE_GREEN;
extern const GE_Color GE_BLUE;

extern const GE_Color GE_YELLOW;
extern const GE_Color GE_CYAN;
extern const GE_Color GE_MAGENTA;

extern const GE_Color GE_BROWN;
extern const GE_Color GE_ORANGE;
extern const GE_Color GE_PINK;

//Changes color based on color struct value
void GE_setColor(GE_GameInstance *game, GE_Color color);

//Makes the color brighter by given percentage
GE_Color GE_lightenColor(GE_Color color, float percent);

//Makes the color darker by given percentage
GE_Color GE_darkenColor(GE_Color color, float percent);

#endif // COLOR_H_INCLUDED
