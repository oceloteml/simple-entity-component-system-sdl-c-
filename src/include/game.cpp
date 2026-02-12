#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

#include "Entities/entities.h"
#include "game.h"


SDL_Texture *texture;
Entity *entities[255];
Vector2I pos = Vector2I();
Vector2 scl = Vector2(0.7, 0.7);


bool show_cat = true;

void init(SDL_Window *window, SDL_Renderer *renderer){
    texture = IMG_LoadTexture(renderer, "out/textures/cat.jpeg");

    if (!texture){
        SDL_Log("no loaded texture");
    }

    entities[0] = new Entity(texture, pos, scl);
    entities[0]->setVelocity(Vector2(100, 30));

    entities[1] = new Entity(texture, Vector2I(200, 200), Vector2(0.3,0.3));
    entities[1]->setVelocity(Vector2(10, 10));

    /*
        Use to delete the entity from array:
        delete entities[ index ];
    */
    
}

void update(SDL_Window *window, SDL_Renderer *renderer, SDL_Event *event){
    
    const bool *keys = SDL_GetKeyboardState(NULL);
    
    show_cat = not (keys[SDL_SCANCODE_SPACE]);
    
    for (Entity *entity : entities){
        if (entity){
            entity->Update(delta);
        }
    }
}

void draw(SDL_Window *window, SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    
    for (Entity *entity : entities){
        if (entity){
            entity->Draw(renderer);
        }
    }

    const char *fps = to_string(SDL_round(1./delta)).c_str();

    SDL_SetRenderDrawColor(renderer ,0,0,0, 255);
    SDL_RenderDebugText(renderer, 0,0, fps);
}

void quit(){
    
}