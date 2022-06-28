#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#ifdef __linux__
    #include <SDL2/SDL.h>
#endif

#ifdef _WIN32
    #include <SDL.h>
#endif

//Game Instance
typedef struct {
    int screenWidth;
    int screenHeight;
    SDL_Window* win;
    SDL_Renderer* renderer;
    SDL_Surface* screenSurface;
} GE_GameInstance;

//Initializes the SDL library
GE_GameInstance* GE_newGameInstance(int screen_width, int screen_height);

//Loading functions (_ indicates internal use only)
SDL_Surface* _GE_loadSurface(GE_GameInstance *game, const char* path);

//intended function for texture loading
SDL_Texture* _GE_loadTexture(GE_GameInstance *game, const char* path);

//Changes the color of the renderer
void GE_changeColor(GE_GameInstance *game, int r, int g, int b, int a);

//Clears the renderer
void GE_clearScreen(GE_GameInstance *game);

//Draws the screen
void GE_renderScreen(GE_GameInstance *game);

//Free the game instance
void GE_freeGameInstance(GE_GameInstance *game);

#endif // ENGINE_H_INCLUDED
