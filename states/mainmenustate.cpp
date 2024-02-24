#include "../states/mainmenustate.h"
#include "mainmenustate.h"

void MainMenuState::initVariables()
{

}

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

void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
    if (!this->backgroundTexture.loadFromFile("../../ressources/images/menubackground.png")) {
        std::cout << "Error loading background texture" << std::endl;
        this->background.setFillColor(sf::Color(0,0,0,255));
    } else {
        this->backgroundTexture.loadFromFile("../../ressources/images/menubackground.png");
        this->background.setTexture(&this->backgroundTexture);
    }
    
}

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(270,210,150,50,"New Game",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);
    this->buttons["SETTINGS"] = new Button(270,310,150,50,"Settings",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);
    this->buttons["EXIT_STATE"] = new Button(270,410,150,50,"Quit",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);
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
    this->initVariables();
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
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

    //TEMP MOUSE POSITION
    /* 
    sf::Text mouseText;
    mouseText.setPosition(this->mousePosView.x, this->mousePosView.y - 50);
    mouseText.setFont(this->font);
    mouseText.setCharacterSize(12);
    std::stringstream ss;
    ss << this->mousePosView.x << " " << this->mousePosView.y;
    mouseText.setString(ss.str());
    target->draw(mouseText);
    */
}