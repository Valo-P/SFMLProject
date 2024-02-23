#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "../states/gamestate.h"
#include "../ressources/button.h"

class MainMenuState :
    public State
{
private:
    sf::RectangleShape background;
    sf::Font font;
    
    void initFonts();
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();

    //Functions
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
};

#endif