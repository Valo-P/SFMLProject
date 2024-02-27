#include "mouvement.h"

Mouvement::Mouvement(sf::Sprite& sprite,float maxVelocity, float acceleration, float deceleration)
    : sprite(&sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
    
}

Mouvement::~Mouvement()
{

}

const sf::Vector2f &Mouvement::getVelocity() const
{
    return this->velocity;
}

void Mouvement::move(const float dirX, const float dirY)
{
    //Acceleration
    this->velocity.x += this->acceleration * dirX;
    this->velocity.y += this->acceleration * dirY;
}

void Mouvement::update(const float &dt)
{

    if(this->velocity.x > 0.f) //Check for positive x
    {
        //Max velocity check
        if(this->velocity.x > this->maxVelocity)
        {
            this->velocity.x = this->maxVelocity;
        }

        this->velocity.x -= deceleration;
        if(this->velocity.x < 0.f)
            this->velocity.x = 0.f;

    }
    else if(this->velocity.x < 0.f) //Check for negative x
    {
        //Max velocity check
        if(this->velocity.x < -this->maxVelocity)
        {
            this->velocity.x = -this->maxVelocity;
        }

        this->velocity.x += deceleration;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    if(this->velocity.y > 0.f) //Check for positive y
    {
        //Max velocity check
        if(this->velocity.y > this->maxVelocity)
        {
            this->velocity.y = this->maxVelocity;
        }

        this->velocity.y -= deceleration;
        if(this->velocity.y < 0.f)
            this->velocity.y = 0.f;

    }
    else if(this->velocity.y < 0.f) //Check for negative y
    {
        //Max velocity check
        if(this->velocity.y < -this->maxVelocity)
        {
            this->velocity.y = -this->maxVelocity;
        }

        this->velocity.y += deceleration;
        if(this->velocity.y > 0.f)
            this->velocity.y = 0.f;
    }

    //Final move
    this->sprite->move(this->velocity * dt); //Uses velocity
    
}
    