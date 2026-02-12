#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "game.h"


SDL_Window *window;
SDL_Renderer *renderer;


double delta = 1/MAXFPS;
Uint64 time_last_frame;

int main(int argc, char *argv[]){

    if (!SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS)){
        SDL_Log("Couldn't init SDL. ERROR: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("cat", 660, 720, SDL_WINDOW_RESIZABLE);
    if (!window){
        SDL_Log("Could't create window. ERROR: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer){
        SDL_Log("Could't create renderer. ERROR: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    SDL_SetRenderVSync(renderer, 1);

    init(window, renderer);

    bool running = true;
    while (running){
        // UPDATE
        SDL_Event *event;
        SDL_PollEvent(event);

        if (event->type == SDL_EVENT_QUIT){
            running = false;
        }

        delta = (SDL_GetTicks() - time_last_frame)/1000.;

        if (1./delta <= MAXFPS){
            time_last_frame = SDL_GetTicks();
            update(window, renderer, event);

        //DRAW
        draw(window, renderer);
        SDL_RenderPresent(renderer);
        }
    }

    quit();

    SDL_Quit();
}