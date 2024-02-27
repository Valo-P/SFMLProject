#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <map>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Animation
{
private:
    
    sf::Sprite* sprite;
    sf::Texture* textureSheet;
    float speed;
    float timer;
    int width;
    int height;
    sf::IntRect startRect;
    sf::IntRect currentRect;
    sf::IntRect endRect;


    

public:
    Animation(sf::Sprite* sprite, sf::Texture* textureSheet, float speed, int start_frame_x, int start_frame_y, int end_frame_x, int end_frame_y, int width, int height);
    virtual ~Animation();

    void reset();
    void play(const float &dt);
};



#endif 