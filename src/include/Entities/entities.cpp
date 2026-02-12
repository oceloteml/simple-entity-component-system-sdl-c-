#include "Entities/entities.h"


Entity :: Entity(SDL_Texture *texture, Vector2I position, Vector2 scale){
    
    this->texture = texture;
    this->position = Vector2((float)position.x, (float)position.y);
    this->scale = scale;
}

Entity :: ~Entity(){
}

void Entity :: setVelocity(Vector2 newVelocity){
    this->velocity = newVelocity;
}

Vector2 Entity :: getPosition(){
    return this->position;
}


void Entity :: Update(double delta){

    position.x += velocity.x * delta;
    position.y += velocity.y * delta;

    if (!velocity.x && !velocity.y){
        position.x = float((int)position.x);
        position.y = float((int)position.y);
    }
}

void Entity :: Draw(SDL_Renderer *renderer){

    Vector2 scl_pixels = Vector2(float( texture->w * (float)scale.x ), float( texture->h * (float)scale.y ));

    SDL_FRect *src_frect = {NULL};
    SDL_FRect *dst_frect = new SDL_FRect {position.x - scl_pixels.x/2, 
                                          position.y - scl_pixels.y/2, 
                                          scl_pixels.x, 
                                          scl_pixels.y};

    SDL_RenderTexture(renderer, texture, src_frect, dst_frect);

    delete src_frect;
    delete dst_frect;
}