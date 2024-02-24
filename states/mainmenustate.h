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

    std::map<std::string, Button*> buttons;
    
    void initFonts();
    void initKeybinds();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,std::stack<State*>* states);
    virtual ~MainMenuState();

    void endState();

    //Functions
    void updateInput(const float& dt);
    void updateButtons();
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
    void renderButtons(sf::RenderTarget& target);
};

#endif