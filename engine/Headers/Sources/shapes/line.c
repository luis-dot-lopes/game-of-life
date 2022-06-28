#include "../../Headers/shapes.h"

void GE_Line_draw(GE_GameInstance *game, GE_Line line) {
    SDL_RenderDrawLine(game->renderer, (int) line.x1, (int) line.y1,
                                       (int) line.x2, (int) line.y2);
}

//helper function
static inline int sign(double x) {
    return (x > 0) - (x < 0);
}

bool GE_Line_intersect(GE_Line  line1, GE_Line line2) {

    double a1 = (line1.y2 - line1.y1) / (line1.x2 - line1.x1);
    double b1 = line1.y1 - line1.x1 * a1;

    double a2 = (line2.y2 - line2.y1) / (line2.x2 - line2.x1);
    double b2 = line2.y1 - line2.x1 * a2;

    return sign((line1.x1 * a2 + b2) - line1.y1) != sign((line1.x2 * a2 + b2) - line1.y2) &&
           sign((line2.x1 * a1 + b1) - line2.y1) != sign((line2.x2 * a1 + b1) - line2.y2);

}

GE_Point GE_Line_getIntersection(GE_Line line1, GE_Line line2) {

}
