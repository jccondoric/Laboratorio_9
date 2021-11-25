#include <string>

#include "SDL.h"

#include "GameManager.h"

int main(int /*argc*/, char** /*argv[]*/)
{
    // init game
    GameManager* game = nullptr;
    game = GameManager::getInstance(std::string("Bomberman USFX"), 800, 600);
    // game = new GameManager(std::string("Bomberman USFX"), 800, 600);
    // run game loop
    game->execute();

    return 0;
}
