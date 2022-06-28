#include "../Headers/color.h"

//Representation of some colors
const GE_Color GE_WHITE   = { 0xFF, 0xFF, 0xFF, 0xFF };
const GE_Color GE_BLACK   = { 0x00, 0x00, 0x00, 0xFF };
const GE_Color GE_GREY    = { 0x80, 0x80, 0x80, 0xFF };

const GE_Color GE_RED     = { 0xFF, 0x00, 0x00, 0xFF };
const GE_Color GE_GREEN   = { 0x00, 0xFF, 0x00, 0xFF };
const GE_Color GE_BLUE    = { 0x00, 0x00, 0xFF, 0xFF };

const GE_Color GE_YELLOW  = { 0xFF, 0xFF, 0x00, 0xFF };
const GE_Color GE_CYAN    = { 0x00, 0xFF, 0xFF, 0xFF };
const GE_Color GE_MAGENTA = { 0xFF, 0x00, 0xFF, 0xFF };

const GE_Color GE_BROWN   = { 0x8B, 0x45, 0x13, 0xFF };
const GE_Color GE_ORANGE  = { 0xFF, 0x8C, 0x00, 0xFF };
const GE_Color GE_PINK    = { 0xFF, 0xC0, 0xCB, 0xFF };

void GE_setColor(GE_GameInstance *game, GE_Color color) {
    GE_changeColor(game, color.r, color.g, color.b, color.a);
}

GE_Color GE_lightenColor(GE_Color color, float percent) {
    int d_red = (255 - color.r) * percent;
    int d_green = (255 - color.g) * percent;
    int d_blue = (255 - color.b) * percent;

    return (GE_Color) { color.r + d_red, color.g + d_green, color.b + d_blue, color.a };
}

GE_Color GE_darkenColor(GE_Color color, float percent) {

    return (GE_Color) { color.r * (1 - percent),
                        color.g * (1 - percent),
                        color.b * (1 - percent),
                        color.a };
}
