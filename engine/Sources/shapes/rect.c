#include "../../Headers/shapes.h"

bool GE_Rect_intersect(GE_Rect rect1, GE_Rect rect2) {
    return rect1.x <= rect2.x + rect2.width  &&
           rect1.x + rect1.width  >= rect2.x &&
           rect1.y <= rect2.y + rect2.height &&
           rect1.y + rect1.height >= rect2.y;
}

GE_Rect GE_Rect_intersection(GE_Rect rect1, GE_Rect rect2) {

    if(GE_Rect_intersect(rect1, rect2)) {
        double maxY = rect1.y > rect2.y ? rect1.y : rect2.y;
        double minXcorner = rect1.x > rect2.x ? rect2.x + rect2.width : rect1.x + rect1.width;
        double maxX = rect1.x > rect2.x ? rect1.x : rect2.x;
        double minYcorner = rect1.y > rect2.y ? rect2.y + rect2.height : rect1.y + rect1.height;
        return (GE_Rect) { maxX, maxY, fabs(minXcorner - maxX), fabs(minYcorner - maxY) };
    } else {
        return (GE_Rect) { 0, 0, 0, 0 };
    }
}

void GE_Rect_draw(GE_GameInstance *game, GE_Rect rect) {
    SDL_Rect sdl_rect = { (int)rect.x, (int)rect.y, (int)rect.width, (int)rect.height };
    SDL_RenderDrawRect(game->renderer, &sdl_rect);
}

void GE_Rect_fill(GE_GameInstance *game, GE_Rect rect) {
    SDL_Rect sdl_rect = { (int)rect.x, (int)rect.y, (int)rect.width, (int)rect.height };
    SDL_RenderFillRect(game->renderer, &sdl_rect);
}
