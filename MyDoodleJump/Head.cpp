#include "Head.h"


Head::Head(sf::Texture* texture,float posX,float posY)
{
	this->sprite->setTexture(*texture);
}

Head::~Head()
{
}

sf::FloatRect Head::getBounds() const
{
	return sf::FloatRect();
}

void Head::update()
{
}

void Head::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
