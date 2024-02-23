#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "state.h"

class GameState : public State
{
private:
    Entity player;
    
public:
    //Constructors/Destructors
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    void endState();
    //Functions
    void updateKeybinds(const float &dt);
    void update(const float &dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif