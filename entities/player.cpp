#include "player.h"

void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMouvement(*this->sprite,250.f, 15.f, 5.f);
    this->createAnimations(this->sprite, this->texture);
    this->initAnimations();
}

void Player::initAnimations() {

    this->animationController->addAnimation("IDLE", 10.f, 1, 1, 4, 1, 86, 86);
    // this->animationController->addAnimation("WALK", 10.f, 0, 1, 3, 1, 64, 64);
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