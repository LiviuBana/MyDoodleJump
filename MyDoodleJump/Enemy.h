#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
class Enemy
{
private:
	float leftBound;
	float rightBound;
	float bottomBound;
	float topBound;
public:
	//virtual void initAnimation()=0;
	virtual void initAnimation()=0;
	virtual void initSprite() = 0;
	virtual void initTexture()=0;
	virtual void updateAnimation()=0;
	virtual void update() = 0;
	virtual sf::FloatRect getBounds() const=0;
	virtual sf::Vector2f getPositions() const = 0;
	virtual void moveDown(float x,float y) = 0;
	virtual void moveUp() = 0;
	virtual void render(sf::RenderTarget* target) = 0;
};

