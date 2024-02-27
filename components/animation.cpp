#include "animation.h"

Animation::Animation(sf::Sprite* sprite, sf::Texture *textureSheet, float speed, int start_frame_x, int start_frame_y, int end_frame_x, int end_frame_y, int width, int height) : sprite(sprite), textureSheet(textureSheet), speed(speed), width(width), height(height)
{
    this->startRect = sf::IntRect(start_frame_x * width, start_frame_y * height, width, height);
    this->currentRect = this->startRect;
    this->endRect = sf::IntRect(end_frame_x * width, end_frame_y * height, width, height);

    this->sprite->setTexture(*this->textureSheet, true);
    this->sprite->setTextureRect(this->currentRect);
}

Animation::~Animation()
{
}

void Animation::play(const float &dt)
{
    //Update timer
    this->timer += 100.f * dt;
    if (this->timer >= this->speed)
    {
        //Reset timer
        this->timer = 0.f;

        //Animate
        if (this->currentRect != this->endRect)
        {
            this->currentRect.left += this->width;
        }
        else
        {
            this->currentRect.left = this->startRect.left;
        }

        this->sprite->setTextureRect(this->currentRect);
    }
}

void Animation::reset()
{
    this->timer = 0.f;
    this->currentRect = this->startRect;
}