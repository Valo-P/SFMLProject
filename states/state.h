#ifndef STATE_H
#define STATE_H

#include "../entities/entity.h"

class State
{
private:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;

    bool quit;


public:
    //Constructors/Destructors
    State(sf::RenderWindow* window);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkForQuit();
    virtual void endState() = 0;

    //Functions
    virtual void updateKeybinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif