#pragma once
//#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
class Bullet
{
	sf::Sprite sprite;
	sf::Vector2f direction;
	float movementSpeed;
	bool bulletIsMovingUp = true;
	bool bulletIsMovingRight = false;
	float initialPosition;
	float bulletRange = 200;
	float dy=0;
public:
	Bullet();
	Bullet(sf::Texture* texture,float poX,float posY,float dirX,float dirY,float movementSpeed);
	virtual ~Bullet();

	sf::FloatRect getBounds() const;
	void moveDown(float x, float y);
	void update();
	void render(sf::RenderTarget* target);
};

