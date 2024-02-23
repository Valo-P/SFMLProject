#include "game.h"

//Static functions

//Initializer functions
void Game::initWindow()
{
    std::ifstream ifs("../../config/window.ini");

    std::string title = "None";
    sf::VideoMode windowBounds(800,600);
    // sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();

    unsigned framerateLimit = 60;
    bool verticalSyncEnabled = false;

    if(ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> windowBounds.width >> windowBounds.height;
        ifs >> framerateLimit;
        ifs >> verticalSyncEnabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(windowBounds, title);
    this->window->setFramerateLimit(framerateLimit);
    this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

// Constructors/Destructors
Game::Game(/* args */)
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

//Functions

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

}

void Game::render()
{
    this->window->clear();
    //Render game
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