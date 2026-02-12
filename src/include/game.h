#pragma once

#include <SDL3/SDL.h>
#define MAXFPS 60

extern double delta;
extern Uint64 time_last_frame;

void init(SDL_Window *window, SDL_Renderer *renderer);

void update(SDL_Window *window, SDL_Renderer *renderer, SDL_Event *events);

void draw(SDL_Window *window, SDL_Renderer *renderer);

void quit();