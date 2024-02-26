#pragma once
#include "Enemy.h"
class BunnyMonster1 :public Enemy
{
private:
	const int upperBound=0;
	const int leftBound=0;
	const int rightBound=0;
	const int lowerBound = 46;
	sf::Texture texture;
	sf::Sprite* sprite = new sf::Sprite();
	sf::Clock animationTimer;
	sf::IntRect currentFrame;
	float textureHeight = 51;
	bool isDead=false;
public:
	BunnyMonster1();
	BunnyMonster1(float xPos,float yPos);
	void initTexture();
	void initAnimation();
	void initSprite();
	void update();
	void moveDown(float x,float y);
	sf::FloatRect getBounds() const;
	sf::Vector2f getPositions() const;
	void render(sf::RenderTarget *target);
	void updateAnimation();

	// Inherited via Enemy
	virtual void moveUp() override;

};

