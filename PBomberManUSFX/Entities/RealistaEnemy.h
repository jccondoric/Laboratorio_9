#pragma once
#include "Enemy.h"
#include "../GameTextures.h"
class RealistaEnemy :
    public Enemy
{
public:
    RealistaEnemy(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer);
};

