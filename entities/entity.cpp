#include "entity.h"

void Entity::initVariables()
{
    this->texture = nullptr;
    this->sprite = nullptr;
    this->movementSpeed = 100.f;
}

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete this->texture;
    delete this->sprite;
}

void Entity::createSprite(sf::Texture *texture_sheet)
{
    this->texture = texture_sheet;
    this->sprite = new sf::Sprite(*this->texture);
    this->sprite->setScale(0.1f, 0.1f);
}

void Entity::setPosition(const float x, const float y)
{
    if (this->sprite)
    {
        this->sprite->setPosition(x, y);
    }
}

void Entity::move(const float dirX, const float dirY, const float &dt)
{
    // this->shape.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
    if (this->sprite)
    {
        this->sprite->move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
    }
}

void Entity::update(const float &dt)
{
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

void Entity::render(sf::RenderTarget *target)
{
    if(this->sprite) {
        target->draw(*this->sprite);
    }
}