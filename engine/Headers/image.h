#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include "engine.h"
#include <stdio.h>

#ifdef __linux__
    #include <SDL2/SDL.h>
#endif

#ifdef _WIN32
    #include <SDL.h>
#endif

typedef struct {
    SDL_Texture* texture;
    int width;
    int height;
} GE_Image;

typedef struct {
    GE_Image* image;
    int sprite_width;
    int quantity;
} GE_Sprites;

//Loading images from a path
GE_Image* GE_loadImage(GE_GameInstance *game, const char* path);

//Loads an array of images from a single file
GE_Sprites* GE_loadSprites(GE_GameInstance *game, const char* path, int width);

//Drawing a specific image from sprites object
void GE_drawSprite(GE_GameInstance *game, int x, int y, GE_Sprites *sprites, int index);

//Drawing images to the game screen
void GE_drawImage(GE_GameInstance *game, int x, int y, GE_Image* img);

void GE_freeImage(GE_Image *img);

void GE_freeSprites(GE_Sprites *sprites);

#endif // IMAGE_H_INCLUDED
