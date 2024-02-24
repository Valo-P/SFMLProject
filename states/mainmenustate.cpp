#include "../states/mainmenustate.h"

void MainMenuState::initKeybinds()
{
    std::ifstream ifs("../../config/keybinds.ini");

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

void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("../../ressources/fonts/Monocraft.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
    : State(window, supportedKeys)
{
    this->initFonts();
    this->initKeybinds();

    this->gamestateBtn = new Button(100,100,150,50,"New Game",&this->font,sf::Color::Green,sf::Color::Red,sf::Color::Yellow);

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
    delete this->gamestateBtn;
}

void MainMenuState::endState()
{
    std::cout << "Ending MainMenuState!" << std::endl;
}

void MainMenuState::updateInput(const float &dt)
{
    this->checkForQuit();
}

void MainMenuState::update(const float &dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->gamestateBtn->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target = this->window;

    target->draw(this->background);
    this->gamestateBtn->render(target);
}