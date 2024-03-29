#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Button
{
private:
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;


    
public:
    Button(float x,float y,float width,float height, std::string text, sf::Font* font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    bool isPressed();

    //Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);
};


#endif