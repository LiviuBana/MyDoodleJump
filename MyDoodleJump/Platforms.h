#pragma once
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include"Enemy.h"
#include"BunnyMonster1.h"
#include<iostream>
#include<vector>
//#include<time.h>
#include<ctime>
#include<random>
class Platform
{
private:
	sf::Sprite shape;
	unsigned counter = 0;
	unsigned randomNumber1=2;
	float movementSpeed = 10;
	bool spawnMonster = false;

public:
	Platform();
	Platform(sf::Texture * texture,unsigned posX,unsigned posY);
	const sf::FloatRect getBounds() const;
	const sf::Vector2f getPosition() const;
	virtual ~Platform();
	void moveDown(float x, float y,float posX,float posY,float height,unsigned& spawningCounter);
	void moveUp();
	void update();
	void render(sf::RenderTarget* target);
};


