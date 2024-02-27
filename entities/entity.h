#ifndef ENTITY_H
#define ENTITY_H

#include "../components/mouvement.h"
#include "../components/animationController.h"

class Entity
{
private:
    /* data */
    void initVariables();

protected:
    sf::Texture* texture;
    sf::Sprite* sprite;

    Mouvement* mouvement;
    AnimationController* animationController;

public:
    Entity(/* args */);
    ~Entity();

    void createSprite(sf::Texture* texture_sheet);
    void createMouvement(sf::Sprite& sprite,const float maxVelocity, const float acceleration, const float deceleration);
    void createAnimations(sf::Sprite* sprite, sf::Texture* textureSheet);

    //Functions
    virtual void setPosition(const float x, const float y);
    virtual void move(const float dirX, const float dirY, const float& dt);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);

};

#endif