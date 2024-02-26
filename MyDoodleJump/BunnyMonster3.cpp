#include "BunnyMonster3.h"

BunnyMonster3::BunnyMonster3(float xPos, float yPos)
{
    this->initTexture();
    this->initSprite();
    this->initAnimation();
    this->sprite->setPosition(xPos, yPos-textureHeight);
}

void BunnyMonster3::initAnimation()
{
    this->animationTimer.restart();
}

void BunnyMonster3::initSprite()
{
    this->sprite->setTexture(this->texture);
    this->currentFrame = sf::IntRect(0,0, 75, 55);
    this->sprite->setTextureRect(this->currentFrame);
}

void BunnyMonster3::initTexture()
{
    sf::Image monster;
    monster.loadFromFile("Textures/bunnymonster2.png");
    monster.createMaskFromColor(sf::Color(255, 255, 255));
    this->texture.loadFromImage(monster);
}

void BunnyMonster3::updateAnimation()
{
    if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5) {
        this->currentFrame.top += 55;
        if (this->currentFrame.top >=110)
            this->currentFrame.top = 0;

        this->animationTimer.restart();
        this->sprite->setTextureRect(this->currentFrame);
    }
}

void BunnyMonster3::update()
{
    this->updateAnimation();
}

sf::FloatRect BunnyMonster3::getBounds() const
{
    return this->sprite->getGlobalBounds();
}

sf::Vector2f BunnyMonster3::getPositions() const
{
    return this->sprite->getPosition();
}

void BunnyMonster3::moveDown(float x, float y)
{
    this->sprite->move(x,y);
}

void BunnyMonster3::render(sf::RenderTarget* target)
{
    target->draw(*this->sprite);
}

void BunnyMonster3::moveUp()
{
    this->sprite->move(0, -10);
}
