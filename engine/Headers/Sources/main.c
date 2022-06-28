#include <stdio.h>
#include <stdbool.h>
#include "../Headers/engine.h"
#include "../Headers/input.h"
#include "../Headers/image.h"
#include "../Headers/clock.h"
#include "../Headers/shapes.h"
#include "../Headers/color.h"

GE_Sprites* someImg = NULL;

int main(int argc, char* args[]) {

    //Loading game
    GE_GameInstance* game = GE_newGameInstance(640, 480);

    GE_InputState* in = GE_initInput();

    GE_Clock clock = GE_newClock(60);

    //Loading media
    someImg = GE_loadSprites(game, "img.bmp", 100);

    bool gameover = false;

    int x = 0, y = 0;

    while(!gameover) {
        GE_clockInitTick(&clock);

        GE_updateInputState(in);
        if(in->quit) {
            gameover = true;
            continue;
        }

        //render cycle
        GE_clearScreen(game);

        if(in->mouseButton == GE_MOUSE_RIGHT) {
            x = in->mouseX;
            y = in->mouseY;
        }

        GE_Line line1 = { 10, 10, 30, 30 };
        GE_Line line2 = { 50, 50, 80, 80 };

        GE_Color lineColor = GE_darkenColor(GE_RED, 0.5);

        GE_setColor(game, lineColor);

        GE_Line_draw(game, line1);

        GE_setColor(game, GE_RED);

        GE_Line_draw(game, line2);

        GE_setColor(game, GE_BLACK);

        printf("%d\n", GE_Line_intersect(line1, line2));

        GE_renderScreen(game);

        GE_clockEndTick(&clock);
    }

    //free resources
    GE_freeSprites(someImg);

    someImg = NULL;

    GE_freeInputState(in);

    in = NULL;

    GE_freeGameInstance(game);

    game = NULL;

    return 0;
}
