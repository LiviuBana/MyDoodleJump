#include "BunnyMonster1.h"

void BunnyMonster1::initTexture()
{
	sf::Image monster;
	monster.loadFromFile("Textures/bunnymonster.png");
	monster.createMaskFromColor(sf::Color(255, 255, 255));
	this->texture.loadFromImage(monster);
}

void BunnyMonster1::initAnimation()
{
	this->animationTimer.restart();
}

void BunnyMonster1::initSprite()
{
	this->sprite->setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 0, 75, 46);
	this->sprite->setTextureRect(this->currentFrame);
}

void BunnyMonster1::update()
{
	this->updateAnimation();
}

void BunnyMonster1::moveDown(float x,float y)
{
	this->sprite->move(x, y);

}

sf::FloatRect BunnyMonster1::getBounds() const
{
	return this->sprite->getGlobalBounds();
}

sf::Vector2f BunnyMonster1::getPositions() const
{
	return this->sprite->getPosition();
}

BunnyMonster1::BunnyMonster1(float xPos, float yPos)
{
	this->initTexture();
	this->initSprite();
	this->initAnimation();
	this->sprite->setPosition(xPos, yPos-textureHeight);

}



void BunnyMonster1::render(sf::RenderTarget* target)
{
		target->draw(*this->sprite);
}

void BunnyMonster1::updateAnimation()
{
		if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5) {
			this->currentFrame.left += 75;
			if (this->currentFrame.left >= 150)
				this->currentFrame.left = 0; 

			this->animationTimer.restart();
			this->sprite->setTextureRect(this->currentFrame);
		}
}

void BunnyMonster1::moveUp()
{
	this->sprite->move(0, -10);
}
