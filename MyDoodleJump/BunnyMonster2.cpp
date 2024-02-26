#include "BunnyMonster2.h"

BunnyMonster2::BunnyMonster2(float posX, float posY)
{
	this->initTexture();
	this->initSprite();
	this->initAnimation();
	this->sprite->setPosition(posX, posY - textureHeight);
	this->initialxPos = posX;
}

void BunnyMonster2::initAnimation()
{

	this->animationTimer.restart();
}

void BunnyMonster2::initSprite()
{
	this->sprite->setTexture(this->texture);
	this->currentFrame = sf::IntRect(0, 0, 82, 45);
	this->sprite->setTextureRect(this->currentFrame);
}

void BunnyMonster2::initTexture()
{
	sf::Image monster;
	monster.loadFromFile("Textures/bunnymonster3.png");
	monster.createMaskFromColor(sf::Color(255, 255, 255));
	this->texture.loadFromImage(monster);
}

void BunnyMonster2::updateAnimation()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.15) {
		this->currentFrame.left += 82;
		if (this->currentFrame.left >= 400)
			this->currentFrame.left = 0;

		this->animationTimer.restart();
		this->sprite->setTextureRect(this->currentFrame);
	}
}

void BunnyMonster2::update()
{
	this->updateAnimation();
	this->moveLeftRight(500, 2);
}

sf::FloatRect BunnyMonster2::getBounds() const
{
	return this->sprite->getGlobalBounds();
}

sf::Vector2f BunnyMonster2::getPositions() const
{
	return this->sprite->getPosition();
}

void BunnyMonster2::moveDown(float x, float y)
{
	this->sprite->move(x, y);
}

void BunnyMonster2::moveLeftRight(float x,float movementSpeed)
{
	if (spawnMove == true) {
		this->sprite->move(-movementSpeed, 0);
		if (this->sprite->getPosition().x <= 0 || this->sprite->getPosition().x <= initialxPos - xRange) {
			rightMove = true;
			spawnMove = false;
		}
	}
	if (rightMove == true) {
		this->sprite->move(movementSpeed, 0);
		if (this->sprite->getPosition().x >= x - this->sprite->getGlobalBounds().width || this->sprite->getPosition().x >= initialxPos + xRange - this->sprite->getGlobalBounds().width) {
			leftMove = true;
			rightMove = false;
		}
	}
	if (leftMove == true) {
		this->sprite->move(-movementSpeed, 0);
		if (this->sprite->getPosition().x <= 0 || this->sprite->getPosition().x <= initialxPos - xRange) {
			rightMove = true;
			leftMove = false;
		}
	}
}

void BunnyMonster2::render(sf::RenderTarget* target)
{
	target->draw(*this->sprite);
}

void BunnyMonster2::moveUp()
{
	this->sprite->move(0, -10);
}
