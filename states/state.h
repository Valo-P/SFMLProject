#ifndef STATE_H
#define STATE_H

#include "../entities/entity.h"

class State
{
private:
    bool quit;

    std::vector<sf::Texture> textures;

    //Functions
    virtual void initKeybinds() = 0;
protected:
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;

public:
    //Constructors/Destructors
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;
    virtual void checkForQuit();
    virtual void endState() = 0;

    //Functions
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif