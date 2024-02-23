#include "gamestate.h"

void GameState::initKeybinds()
{
    std::ifstream ifs("../../config/keybinds.ini");

    if(ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";
        while(ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initKeybinds();
}

GameState::~GameState()
{

}

void GameState::endState()
{
    std::cout << "Ending GameState!" << std::endl;
}

void GameState::updateInput(const float &dt)
{
    this->checkForQuit();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
        this->player.move(-1.f, 0.f, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
        this->player.move(1.f, 0.f, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
        this->player.move(0.f, -1.f, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
        this->player.move(0.f, 1.f, dt);
    }
}

void GameState::update(const float &dt)
{

    this->updateInput(dt);


    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    this->player.render(target);
}
