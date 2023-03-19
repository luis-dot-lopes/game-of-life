#include <stdlib.h>

#include "../engine/Headers/engine.h"
#include "../engine/Headers/input.h"
#include "../engine/Headers/image.h"
#include "../engine/Headers/clock.h"
#include "../engine/Headers/shapes.h"
#include "../engine/Headers/color.h"

#define CELL_SIZE 20
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define GRID_WIDTH WINDOW_WIDTH / CELL_SIZE
#define GRID_HEIGHT WINDOW_HEIGHT / CELL_SIZE
#define GRID_SIZE GRID_WIDTH * GRID_HEIGHT

//read char as byte
char grid[GRID_SIZE] = {0}; 
char other_grid[GRID_SIZE] = {0};

char get_grid_cell(size_t row, size_t col) {
    if(row >= 0 && row < GRID_HEIGHT && col >= 0 && col < GRID_WIDTH) {
        return grid[GRID_WIDTH * row + col];
    }
    return 0;
}

void set_grid_cell(size_t row, size_t col, char value) {
    grid[GRID_WIDTH * row + col] = value;
}

int count_cell_neighbours(size_t row, size_t col) {
    int sum = 0;
    for(int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if(i == 0 && j == 0) continue;
            sum += get_grid_cell(row + i, col + j);
        }
    }
    return sum;
}

void render_game(GE_GameInstance *game) {

    GE_setColor(game, GE_BLACK);    
    GE_clearScreen(game);

    GE_setColor(game, GE_WHITE);
    for(size_t i = 0; i < GRID_HEIGHT; ++i) {
        for(size_t j = 0; j < GRID_WIDTH; ++j) {
            if(get_grid_cell(i, j)) {
                GE_Rect square = {
                    .x = j * CELL_SIZE + 1,
                    .y = i * CELL_SIZE + 1,
                    .width = CELL_SIZE - 1,
                    .height = CELL_SIZE - 1,
                };

                GE_Rect_fill(game, square);
            }
        }
    }

    GE_renderScreen(game);
}

void update_game() {
    for(size_t i = 0; i < GRID_HEIGHT; ++i) {
        for(size_t j = 0; j < GRID_WIDTH; ++j) {
            int neighbours = count_cell_neighbours(i, j);
            if(neighbours == 3) {
                other_grid[i * GRID_WIDTH + j] = 1;
            } else if (neighbours == 2) {
                other_grid[i * GRID_WIDTH + j] = get_grid_cell(i, j);
            }
        }
    }
    memcpy(grid, other_grid, GRID_SIZE);
    memset(other_grid, 0, GRID_SIZE);
}

int main(void) {

    //Loading game
    GE_GameInstance *game = GE_newGameInstance(WINDOW_WIDTH, WINDOW_HEIGHT);

    GE_InputState *in = GE_initInput();

    GE_Clock clock = GE_newClock(60);

    bool quit = false;
    bool paused = false;

    set_grid_cell(11, 4, 1);
    set_grid_cell(11, 5, 1);
    set_grid_cell(11, 6, 1);

    while(!quit) {

        GE_clockInitTick(&clock);

        GE_updateInputState(in);

        if(in->quit) {
            quit = true;
            continue;
        }

        if(in->keysJustPressed[GE_K_SPACE]) {
            paused = !paused;
        }

        if(in->mouseButton == GE_MOUSE_LEFT && in->mouseJustPressed) {
            int row = in->mouseY / CELL_SIZE;
            int col = in->mouseX / CELL_SIZE;

            set_grid_cell(row, col, !get_grid_cell(row, col));
        }

        render_game(game);

        if(in->keysJustPressed[GE_K_N]) {
            update_game();
            GE_clockEndTick(&clock);
            continue;
        }

        if(paused) {
            GE_clockEndTick(&clock);
            continue;
        }
        
        if(clock.ticks % 20 == 0) {
            update_game();
        }

        GE_clockEndTick(&clock);
    }

    return 0;
}

