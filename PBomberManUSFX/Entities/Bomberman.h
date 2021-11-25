#pragma once
#include <iostream>
#include "GamePawn.h"
#include "Sprite.h"

using namespace std;

class Bomberman : public GamePawn
{
private:

public:
	//Constructor
	Bomberman(std::shared_ptr<SDL_Texture> _texture, SDL_Renderer* _renderer);

	void render(SDL_Rect& _camara);
	void update(const unsigned int delta);
};

