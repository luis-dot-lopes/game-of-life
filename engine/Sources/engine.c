#include "../Headers/engine.h"
#include <stdio.h>

GE_GameInstance* GE_newGameInstance(int screen_width, int screen_height) {

    GE_GameInstance* game = malloc(sizeof(GE_GameInstance));
    if(game == NULL) {
        printf("Failed to allocate game object\n");
        return NULL;
    }

    if(SDL_Init(SDL_INIT_VIDEO < 0)) {
        printf("SDL couldn't initialize. Error: %s\n", SDL_GetError());
        return NULL;
    }

    game->screenWidth = screen_width;
    game->screenHeight = screen_height;

    game->win = SDL_CreateWindow("SDL Game", 50, 50,
                                    screen_width, screen_height, SDL_WINDOW_SHOWN);
    if(game->win == NULL) {
        printf("Couldn't create window. Error: %s\n", SDL_GetError());
        return NULL;
    }

    game->renderer = SDL_CreateRenderer(game->win, -1, SDL_RENDERER_ACCELERATED);
    if(game->renderer == NULL) {
        printf("Couldn't create renderer. Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_SetRenderDrawColor(game->renderer, 0x00, 0x00, 0x00, 0x00);

    game->screenSurface = SDL_GetWindowSurface(game->win);

    return game;

}

SDL_Surface* _GE_loadSurface(GE_GameInstance *game, const char* path) {
    SDL_Surface* optimizedSurface = NULL;

    SDL_Surface* loadedSurface = SDL_LoadBMP( path );
    if(loadedSurface == NULL) {

        printf("Unable to load image %s. Error: %s\n", path, SDL_GetError());

    } else {

        optimizedSurface = SDL_ConvertSurface( loadedSurface, game->screenSurface->format, 0 );
        if(optimizedSurface == NULL) {
            printf("Unable to convert surface %s. Error: %s\n", path, SDL_GetError());
        }

        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

SDL_Texture* _GE_loadTexture(GE_GameInstance *game, const char* path) {
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = _GE_loadSurface(game, path );
    if( loadedSurface == NULL ) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, SDL_GetError() );
    } else {

        Uint32 colorKey = SDL_MapRGB(loadedSurface->format, 255, 0, 255);
        SDL_SetColorKey(loadedSurface, SDL_TRUE, colorKey);

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( game->renderer, loadedSurface );
        if( newTexture == NULL ) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

void GE_changeColor(GE_GameInstance *game, int r, int g, int b, int a) {
    SDL_SetRenderDrawColor(game->renderer, r, g, b, a);
}

void GE_clearScreen(GE_GameInstance *game) {
    SDL_RenderClear(game->renderer);
}

void GE_renderScreen(GE_GameInstance *game) {
    SDL_RenderPresent(game->renderer);
}

void GE_freeGameInstance(GE_GameInstance *game) {

    SDL_FreeSurface(game->screenSurface);

    game->screenSurface = NULL;

    SDL_DestroyRenderer(game->renderer);

    game->renderer = NULL;

    SDL_DestroyWindow(game->win);

    game->win = NULL;

    free(game);

}
