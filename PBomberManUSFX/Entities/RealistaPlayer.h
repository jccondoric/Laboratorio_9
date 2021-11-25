#pragma once
#include "Player.h"
#include "../GameTextures.h"
class RealistaPlayer :
    public Player
{
public:
    RealistaPlayer(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer);
};

