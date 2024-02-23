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

void Game::initStates()
{
    this->states.push(new GameState(this->window));
}

// Constructors/Destructors
Game::Game(/* args */)
{
    this->initWindow();
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

    if(!this->states.empty())
        this->states.top()->update(this->dt);

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