#include "player.h"

void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMouvement(*this->sprite,200.f, 10.f, 4.f);
}

Player::Player(float x, float y, sf::Texture* texture_sheet)
{
    this->initVariables();
    this->createSprite(texture_sheet);
    this->initComponents();
    this->setPosition(x, y);
}

Player::~Player()
{
}

void Player::update(const float& dt)
{
    this->mouvement->update(dt);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->move(-1.f, 0.f, dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->move(1.f, 0.f, dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        this->move(0.f, -1.f, dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->move(0.f, 1.f, dt);
    }
}

void Player::render(sf::RenderTarget* target)
{
    if (this->sprite)
    {
        target->draw(*this->sprite);
    }
}