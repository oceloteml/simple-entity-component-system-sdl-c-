#pragma once

#include <SDL3/SDL.h>
#include <Vector2/vector2.h>


class Entity{
    public:
        Entity(SDL_Texture *texture, Vector2I position = Vector2I(), Vector2 scale = Vector2(1,1));
        void Update(double delta);
        void Draw(SDL_Renderer *renderer);

        void setVelocity(Vector2 velocity);
        
        Vector2 getPosition();

        ~Entity();

    protected:
        SDL_Texture *texture = NULL;
        Vector2 position = Vector2();
        Vector2 velocity = Vector2(0,0);
        Vector2 scale = Vector2(1,1);
        
};