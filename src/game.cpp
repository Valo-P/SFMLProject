#include "game.h"

//Static functions

//Initializer functions
void Game::initVariables()
{
    this->window = nullptr;
    this->fullscreen = false;
    this->dt = 0.f;
    this->dtClock.restart();
}

void Game::initWindow()
{
    std::ifstream ifs("../../config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    std::string title = "None";
    // sf::VideoMode windowBounds(800,600);
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
    bool fullscreen = false;

    unsigned framerateLimit = 60;
    bool verticalSyncEnabled = false;
    unsigned antialiasingLevel = 0;

    if(ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> fullscreen;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
        ifs >> antialiasingLevel;
    }

    ifs.close();

    this->fullscreen = fullscreen;
    this->windowSettings.antialiasingLevel = antialiasingLevel;
    this->window = new sf::RenderWindow(windowBounds, title, (fullscreen ? sf::Style::Fullscreen : sf::Style::Default), windowSettings);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, &this->states));
    // this->states.push(new GameState(this->window, &this->supportedKeys));
}

void Game::initKeys()
{
    std::ifstream ifs("../../config/supportedkeys.ini");

    if(ifs.is_open())
    {
        std::string key = "";
        int key_value = 0;
        while(ifs >> key >> key_value)
        {
            this->supportedKeys[key] = key_value;
        }
    }

    ifs.close();
}

// Constructors/Destructors
Game::Game(/* args */)
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
}

//Functions

void Game::endApplication()
{
    std::cout << "Ending Application!" << std::endl;
}

void Game::updateDt()
{
    /* Maj de la variable dt avec le temps nécessaire pour update et render une image. */

    this->dt = this->dtClock.restart().asSeconds();

}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();

    if(!this->states.empty()) {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
        
    }
    //End of application
    else
    {
        this->endApplication();
        this->window->close();
    }
    

}

void Game::render()
{
    this->window->clear();
    
    if(!this->states.empty())
        this->states.top()->render(this->window);

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();

    }
}