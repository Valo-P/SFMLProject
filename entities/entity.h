#ifndef ENTITY_H
#define ENTITY_H

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

class Entity
{
private:
    /* data */

protected:
    sf::RectangleShape shape;
    float movementSpeed;
    

public:
    Entity(/* args */);
    ~Entity();

    //Functions
    virtual void move(const float dirX, const float dirY, const float& dt);




    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);

};

#endif