#include "Bullet.h"

Bullet::Bullet()
{
}

Bullet::Bullet(sf::Texture* texture,float posX,float posY, float dirX, float dirY, float movementSpeed)
{
	this->sprite.setTexture(*texture);
	this->sprite.setPosition(posX, posY-30);
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed;
	this->initialPosition = posY-30;
}

Bullet::~Bullet()
{
}

sf::FloatRect Bullet::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Bullet::moveDown(float x, float y)
{
	this->sprite.move(x, y);
}

void Bullet::update()
{

	dy += 0.2;
	this->sprite.move(1, dy);
	if (bulletIsMovingUp == true) {
		dy = -10;
		bulletIsMovingUp = false;
	}
	/*if (this->sprite.getPosition().y >= (this->initialPosition - this->bulletRange) && bulletIsMovingUp == true) {
		this->sprite.move(0, this->movementSpeed * -1.f);

	}
	else {
		if (bulletIsMovingUp == true)
			bulletIsMovingUp = false;
		this->sprite.move(0.2, this->movementSpeed * 1.f);
	}*/
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
