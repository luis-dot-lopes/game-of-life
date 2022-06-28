#include "../Headers/clock.h"

GE_Clock GE_newClock(int expected_tps) {
    GE_Clock new_clock;
    new_clock.expected_tps = expected_tps;
    new_clock.millis_now = -1;
    new_clock.millis_per_tick = 1000 / expected_tps;
    new_clock.ticks = 0;
    return new_clock;
}

void GE_clockInitTick(GE_Clock *clock) {
    if(clock->millis_now == -1)
        clock->millis_now = SDL_GetTicks();
    else
        printf("Clock already running tick\n");
}

void GE_clockEndTick(GE_Clock *clock) {
    if(clock->millis_now != -1) {
        clock->ticks++;
        int millis_ellapsed = SDL_GetTicks() - clock->millis_now;
        clock->millis_now = -1;
        if(millis_ellapsed < clock->millis_per_tick) {
            SDL_Delay(clock->millis_per_tick - millis_ellapsed);
        }
    } else {
        printf("Clock wasn't initialized for tick\n");
    }
}
