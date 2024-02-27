#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
private:
    /* data */
    void initVariables();
    void initComponents();

protected:
    /* data */
public:
    Player(float x, float y, sf::Texture *texture_sheet);
    virtual ~Player();

    // Functions
    void update(const float &dt);
    void render(sf::RenderTarget *target);
};

#endif