#include "BunnyMonster4.h"

BunnyMonster4::BunnyMonster4(float posX, float posY)
{
	this->initTexture();
	this->initSprite();
	this->initAnimation();
	this->sprite->setPosition(posX, posY - textureHeight);
	this->initialxPos = posX;
}

void BunnyMonster4::moveLeftRight(float x, float movementSpeed)
{
	if (spawnMove == true) {
		this->sprite->move(-movementSpeed, 0);
		if (this->sprite->getPosition().x <= 0||this->sprite->getPosition().x<=initialxPos-xRange) {
			rightMove = true;
			spawnMove = false;
		}
	}
	if (rightMove == true) {
		this->sprite->move(movementSpeed, 0);
		if (this->sprite->getPosition().x >= x - this->sprite->getGlobalBounds().width||this->sprite->getPosition().x>=initialxPos+xRange-this->sprite->getGlobalBounds().width) {
			leftMove = true;
			rightMove = false;
		}
	}
	if (leftMove == true) {
		this->sprite->move(-movementSpeed, 0);
		if (this->sprite->getPosition().x <= 0|| this->sprite->getPosition().x <= initialxPos - xRange) {
			rightMove = true;
			leftMove = false;
		}
	}
}

void BunnyMonster4::initAnimation()
{
	this->animationTimer.restart();
}

void BunnyMonster4::initSprite()
{
	this->sprite->setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 0, 64, 89);
	this->sprite->setTextureRect(this->currentFrame);
}

void BunnyMonster4::initTexture()
{
	sf::Image monster;
	monster.loadFromFile("Textures/bunnymonster4.png");
	monster.createMaskFromColor(sf::Color(255, 255, 255));
	this->texture.loadFromImage(monster);
}

void BunnyMonster4::updateAnimation()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15) {
		this->currentFrame.left += 64;
		if (this->currentFrame.left >=190)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite->setTextureRect(this->currentFrame);
	}
}

void BunnyMonster4::update()
{
	this->updateAnimation();
	this->moveLeftRight(500,2);
}

sf::FloatRect BunnyMonster4::getBounds() const
{
	return this->sprite->getGlobalBounds();
}

sf::Vector2f BunnyMonster4::getPositions() const
{
	return this->sprite->getPosition();
}

void BunnyMonster4::moveDown(float x, float y)
{
	this->sprite->move(x, y);
}

void BunnyMonster4::render(sf::RenderTarget* target)
{
	target->draw(*this->sprite);
}

void BunnyMonster4::moveUp()
{
	this->sprite->move(0, -10);
}
