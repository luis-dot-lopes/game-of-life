#include "../Headers/input.h"

GE_InputState* GE_initInput() {
    GE_InputState *inputSingleton = malloc(sizeof(GE_InputState));

    inputSingleton->quit = false;

    inputSingleton->mouseButton = GE_MOUSE_NONE;
    inputSingleton->mouseJustPressed = false;

    return inputSingleton;
}

void GE_updateInputState(GE_InputState *inputSingleton) {
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0) {
        if(e.type == SDL_QUIT) {
            inputSingleton->quit = true;
        }
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    const int NUM_OF_KEYS = 242;
    for(int i = 0; i < NUM_OF_KEYS; i++) {
        if(currentKeyStates[i]) {
            inputSingleton->keysJustPressed[i] = !inputSingleton->keysPressed[i];
            inputSingleton->keysPressed[i] = true;
            inputSingleton->keysReleased[i] = false;
        } else {
            inputSingleton->keysReleased[i] = true;
            inputSingleton->keysPressed[i] = false;
            inputSingleton->keysJustPressed[i] = false;
        }
    }

    Uint32 button = SDL_GetMouseState(&inputSingleton->mouseX, &inputSingleton->mouseY);
    if(button != GE_MOUSE_NONE) {
        inputSingleton->mouseJustPressed = inputSingleton->mouseButton == GE_MOUSE_NONE;
        inputSingleton->mouseButton = button;
    } else {
        inputSingleton->mouseJustPressed = false; 
        inputSingleton->mouseButton = GE_MOUSE_NONE;
    }
}

void GE_freeInputState(GE_InputState *inputSingleton) {
    free(inputSingleton);
}
