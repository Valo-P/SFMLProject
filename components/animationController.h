#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include "animation.h"

class AnimationController
{
private:
    Animation *animation;

    sf::Sprite *sprite;
    sf::Texture *textureSheet;
    std::map<std::string, Animation*> animations;


public:
    AnimationController(sf::Sprite *sprite, sf::Texture *textureSheet);
    virtual ~AnimationController();

    void addAnimation(const std::string key, float speed, int start_frame_x, int start_frame_y, int end_frame_x, int end_frame_y, int width, int height);
    
    void startAnimation();
    void pauseAnimation();
    void resetAnimation();

    void play(const std::string key,const float &dt);
};

#endif