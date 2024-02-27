#ifndef MOUVEMENT_H
#define MOUVEMENT_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Mouvement
{
private:
    /* data */
protected:
    sf::Sprite* sprite;

    float maxVelocity;
    float acceleration;
    float deceleration;
    sf::Vector2f velocity;

public:
    const sf::Vector2f &getVelocity() const;

    Mouvement(sf::Sprite& sprite, float maxVelocity, float acceleration, float deceleration);
    virtual ~Mouvement();

    void move(const float dirX, const float dirY);

    void update(const float &dt);
};

#endif