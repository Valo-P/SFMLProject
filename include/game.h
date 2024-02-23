#ifndef GAME_H
#define GAME_H

#include "../states/gamestate.h"

class Game
{
private:
    //Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    //Initialization
    void initWindow();
    void initStates();

public:
    //Constructors/Destructors
    Game(/* args */);
    ~Game();

    //Functions
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();

};



#endif