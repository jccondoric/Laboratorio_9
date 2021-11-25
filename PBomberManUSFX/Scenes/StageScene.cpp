#include <string>

#include "../GameManager.h"
#include "../Scenes/LevelScene.h"
#include "../Scenes/MenuScene.h"
#include "../Scenes/StageScene.h"

StageScene::StageScene(GameManager* _gameManager, const unsigned int level, const unsigned int _score)
    : Scene(_gameManager), stage(level), score(_score)
{
    // stage text
    auto text = std::make_shared<Text>(gameManager->getAssetManager()->getFont(), gameManager->getRenderer(),
                                        "ETAPA " + std::to_string(level));
    text->setSize(static_cast<int>(gameManager->getWindowWidth() / 3.0f),
                    static_cast<int>(gameManager->getWindowHeight() / 20.0f));
    text->setPosition(static_cast<int>(gameManager->getWindowWidth() / 2.0f - text->getWidth() / 2.0f),
                        static_cast<int>(gameManager->getWindowHeight() / 2.0f - text->getHeight() / 2.0f));
    addObject(text);
}

void StageScene::update(const unsigned int delta)
{
    untilNextSceneTimer += delta;
    if(untilNextSceneTimer >= sceneTimer)
    {
        untilNextSceneTimer = 0;
        gameManager->getSceneManager()->addScene("level", std::make_shared<LevelScene>(gameManager, stage, score));
        gameManager->getSceneManager()->activateScene("level");
        gameManager->getSceneManager()->removeScene("stage");
    }
}
