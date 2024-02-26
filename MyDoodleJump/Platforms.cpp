#include "Platforms.h"





Platform::Platform(sf::Texture * texture, unsigned posX, unsigned posY)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(posX, posY);

}

const sf::FloatRect Platform::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Platform::getPosition() const
{
	return this->shape.getPosition();
}



Platform::~Platform()
{
}

void Platform::moveDown(float x, float y,float posX,float posY,float height,unsigned& spawningCounter)
{

	this->shape.move(x, y);
	if (this->shape.getPosition().y > height-10) {
		this->shape.setPosition(posX,posY);
	++spawningCounter;
	}
}

void Platform::moveUp()
{
	this->shape.move(0, -(this->movementSpeed));
}



void Platform::update()
{

}

void Platform::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
