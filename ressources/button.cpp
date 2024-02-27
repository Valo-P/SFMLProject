#include "../ressources/button.h"

Button::Button(float x,float y,float width,float height, std::string text, sf::Font* font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->shape.setPosition(sf::Vector2f(x,y));
    this->shape.setSize(sf::Vector2f(width,height));


    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(this->idleColor);
    this->text.setCharacterSize(22);
    this->text.setPosition(
        this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
    );

    this->idleColor = idleColor;
    this->hoverColor = hoverColor;  
    this->activeColor = activeColor;

    this->shape.setFillColor(sf::Color(0,0,0,0));
}

Button::~Button()
{
    
}

bool Button::isPressed()
{
    if(this->text.getFillColor() == this->activeColor)
    {
        return true;
    }
    return false;
}

void Button::update(const sf::Vector2f mousePos)
{
    //Idle
    // this->shape.setFillColor(this->idleColor);
    this->text.setFillColor(this->idleColor);

    //Hover
    if(this->shape.getGlobalBounds().contains(mousePos))
    {
        // this->shape.setFillColor(this->hoverColor);
        this->text.setFillColor(this->hoverColor);
    }

    //Active
    if(this->shape.getGlobalBounds().contains(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // this->shape.setFillColor(this->activeColor);
        this->text.setFillColor(this->activeColor);
    }
}

void Button::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
    target->draw(this->text);
}