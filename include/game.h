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

    std::map<std::string, int> supportedKeys;

    //Initialization
    void initWindow();
    void initStates();
    void initKeys();

public:
    //Constructors/Destructors
    Game(/* args */);
    ~Game();

    //Functions

    //Regular
    void endApplication();

    //Update
    void updateDt();
    void updateSFMLEvents();
    void update();

    //Render
    void render();

    //Core
    void run();

};



#endif