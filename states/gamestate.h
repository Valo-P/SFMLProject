#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State
{
private:
    //Variables
    
public:
    //Constructors/Destructors
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    //Functions
    void endState();
    void update(const float &dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif