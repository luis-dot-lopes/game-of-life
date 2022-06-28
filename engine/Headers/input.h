#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdbool.h>

#ifdef __linux__
    #include <SDL2/SDL.h>
#endif

#ifdef _WIN32
    #include <SDL.h>
#endif

//Exposes mouse buttons
typedef enum {
    GE_MOUSE_NONE = -1,
    GE_MOUSE_RIGHT = SDL_BUTTON(SDL_BUTTON_RIGHT),
    GE_MOUSE_MIDDLE = SDL_BUTTON(SDL_BUTTON_MIDDLE),
    GE_MOUSE_LEFT = SDL_BUTTON(SDL_BUTTON_LEFT),
} MouseButton;

typedef struct {
    bool keysPressed[242];
    bool keysReleased[242];
    bool keysJustPressed[242];
    bool quit;
    int mouseX;
    int mouseY;
    MouseButton mouseButton;
} GE_InputState;

//Exposes the main keys of the keyboard.
//To use any key that's not here, include SDL.
typedef enum {

    GE_K_UP = SDL_SCANCODE_UP,
    GE_K_DOWN = SDL_SCANCODE_DOWN,
    GE_K_LEFT = SDL_SCANCODE_LEFT,
    GE_K_RIGHT = SDL_SCANCODE_RIGHT,

    GE_K_A = SDL_SCANCODE_A,
    GE_K_B = SDL_SCANCODE_B,
    GE_K_C = SDL_SCANCODE_C,
    GE_K_D = SDL_SCANCODE_D,
    GE_K_E = SDL_SCANCODE_E,
    GE_K_F = SDL_SCANCODE_F,
    GE_K_G = SDL_SCANCODE_G,
    GE_K_H = SDL_SCANCODE_H,
    GE_K_I = SDL_SCANCODE_I,
    GE_K_J = SDL_SCANCODE_J,
    GE_K_K = SDL_SCANCODE_K,
    GE_K_L = SDL_SCANCODE_L,
    GE_K_M = SDL_SCANCODE_M,
    GE_K_N = SDL_SCANCODE_N,
    GE_K_O = SDL_SCANCODE_O,
    GE_K_P = SDL_SCANCODE_P,
    GE_K_Q = SDL_SCANCODE_Q,
    GE_K_R = SDL_SCANCODE_R,
    GE_K_S = SDL_SCANCODE_S,
    GE_K_T = SDL_SCANCODE_T,
    GE_K_U = SDL_SCANCODE_U,
    GE_K_V = SDL_SCANCODE_V,
    GE_K_W = SDL_SCANCODE_W,
    GE_K_X = SDL_SCANCODE_X,
    GE_K_Y = SDL_SCANCODE_Y,
    GE_K_Z = SDL_SCANCODE_Z,

    GE_K_0 = SDL_SCANCODE_0,
    GE_K_1 = SDL_SCANCODE_1,
    GE_K_2 = SDL_SCANCODE_2,
    GE_K_3 = SDL_SCANCODE_3,
    GE_K_4 = SDL_SCANCODE_4,
    GE_K_5 = SDL_SCANCODE_5,
    GE_K_6 = SDL_SCANCODE_6,
    GE_K_7 = SDL_SCANCODE_7,
    GE_K_8 = SDL_SCANCODE_8,
    GE_K_9 = SDL_SCANCODE_9,

    GE_K_SPACE = SDL_SCANCODE_SPACE,
    GE_K_TAB = SDL_SCANCODE_TAB,
    GE_K_RETURN = SDL_SCANCODE_RETURN,
    GE_K_ESCAPE = SDL_SCANCODE_ESCAPE,
    GE_K_BACKSPACE = SDL_SCANCODE_BACKSPACE,

} Keys;

//Initializes input state
GE_InputState* GE_initInput();

//Update input
void GE_updateInputState(GE_InputState *inputSingleton);

//Free input state
//For now, it just frees a pointer
void GE_freeInputState(GE_InputState *inputSingleton);

#endif // INPUT_H_INCLUDED
