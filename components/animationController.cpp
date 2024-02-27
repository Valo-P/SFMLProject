#include "animationController.h"

AnimationController::AnimationController(sf::Sprite *sprite, sf::Texture *textureSheet)
: sprite(sprite), textureSheet(textureSheet)
{

}

AnimationController::~AnimationController()
{
    for (auto &i : this->animations)
    {
        delete i.second;
    }
    this->animations.clear();
}

void AnimationController::addAnimation(const std::string key, float speed, int start_frame_x, int start_frame_y, int end_frame_x, int end_frame_y, int width, int height)
{
    this->animations[key] = new Animation(this->sprite, this->textureSheet, speed, start_frame_x, start_frame_y, end_frame_x, end_frame_y, width, height);
    // this->animation = &this->animations[key];
}

void AnimationController::startAnimation()
{
    // this->animation->play();
}

void AnimationController::pauseAnimation()
{

}

void AnimationController::resetAnimation()
{

}

void AnimationController::play(const std::string key,const float &dt)
{
    this->animations[key]->play(dt);
}