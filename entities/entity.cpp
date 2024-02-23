#include "entity.h"

Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.f;
}

Entity::~Entity()
{

}

void Entity::move(const float dirX, const float dirY, const float& dt)
{
    this->shape.move(dirX * this->movementSpeed * dt, dirY * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        this->move(-1.f, 0.f, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->move(1.f, 0.f, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        this->move(0.f, -1.f, dt);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->move(0.f, 1.f, dt);
    }
}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}