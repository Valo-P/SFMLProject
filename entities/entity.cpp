#include "entity.h"

void Entity::initVariables()
{
    this->texture = nullptr;
    this->sprite = nullptr;
    this->mouvement = nullptr;
}

Entity::Entity()
{
    this->initVariables();
}

Entity::~Entity()
{
    delete this->mouvement;
    delete this->animationController;
}

void Entity::createSprite(sf::Texture *texture_sheet)
{
    this->texture = texture_sheet;
    this->sprite = new sf::Sprite(*this->texture);
    this->sprite->setScale(0.1f, 0.1f);
}

void Entity::createMouvement(sf::Sprite& sprite,const float maxVelocity, const float acceleration, const float deceleration)
{
    this->mouvement = new Mouvement(sprite, maxVelocity, acceleration, deceleration);
}

void Entity::createAnimations(sf::Sprite *sprite, sf::Texture *textureSheet)
{
    this->animationController = new AnimationController(sprite, textureSheet);
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
    if (this->sprite && this->mouvement)
    {
        this->mouvement->move(dirX, dirY);
    }
}

void Entity::update(const float &dt)
{
    if (this->mouvement)
    {
        this->mouvement->update(dt);
    }
}

void Entity::render(sf::RenderTarget *target)
{
    if(this->sprite) {
        target->draw(*this->sprite);
    }
}