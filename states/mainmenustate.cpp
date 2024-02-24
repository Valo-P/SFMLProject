#include "../states/mainmenustate.h"
#include "mainmenustate.h"

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("../../config/menukeybinds.ini");

    if(ifs.is_open())
    {
        std::string key = "";
        std::string key2 = "";
        while(ifs >> key >> key2)
        {
            this->keybinds[key] = this->supportedKeys->at(key2);
        }
    }

    ifs.close();
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100,100,150,50,"New Game",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);
    this->buttons["SETTINGS"] = new Button(100,200,150,50,"Settings",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);
    this->buttons["EXIT_STATE"] = new Button(100,300,150,50,"Quit",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);
}

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("../../ressources/fonts/Monocraft.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,std::stack<State*>* states)
    : State(window, supportedKeys, states)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{

    for(auto it = this->buttons.begin(); it != this->buttons.end(); ++it)
    {
        delete it->second;
    }
}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState!" << std::endl;
}

void MainMenuState::updateInput(const float &dt)
{
    this->checkForQuit();
}

void MainMenuState::updateButtons()
{
    for(auto &it : this->buttons)
    {
        it.second->update(this->mousePosView);
    }

    //New game
    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->states->push(new GameState(this->window, this->supportedKeys, this->states));
    }

    //Quit the game
    if(this->buttons["EXIT_STATE"]->isPressed())
    {
        this->quit = true;
    }
}

void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
    for(auto &it : this->buttons)
    {
        it.second->render(&target);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target = this->window;

    target->draw(this->background);
    this->renderButtons(*target);
}