#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

#ifdef __linux__
    #include <SDL2/SDL.h>
#endif

#ifdef _WIN32
    #include <SDL.h>
#endif

#include <stdio.h>

/**
This clock is based on SDL_Delay.
It pauses the execution for the time needed to
achieve the expected tps.
It should be initialized at the beginning of the
update loop and ended at the end, after rendering.
*/

typedef struct {
    int millis_now;
    int expected_tps;
    int millis_per_tick;
    int ticks;
} GE_Clock;

//Creates a new clock with expected_tps set (stack allocated)
GE_Clock GE_newClock(int expected_tps);

//Starts measuring time on the start of the tick
void GE_clockInitTick(GE_Clock *clock);

//Waits adequate time to have expected_tps ticks per second
void GE_clockEndTick(GE_Clock *clock);

#endif // TIME_H_INCLUDED
