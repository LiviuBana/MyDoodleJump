#pragma once


#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>
#include"Platforms.h"
#include"Enemy.h"
#include"Bullet.h"
#include<ctime>
class Player
{
private:
	const int bottomBound=70;
	const int leftTextureLeftBound=3;
	const int leftTextureRightBound=28;
	const int rightTextureLeftBound=34;
	const int rightTextureRightBound = 57;
	const int leftShootingBound = 4;
	const int rightShootingBound = 36;
	bool isLeft= true;
	bool isJumping = false;
	bool jumpOn = false;
	bool touchOn = false;
	bool fallOn = true;
	bool shootOn = false;
	bool shootFallingOn = false;
	bool shootTouchingOn = false;
	bool shootJumpingOn = false;
	bool headOn = false;
	sf::FloatRect leftFallingBox;
	sf::FloatRect leftStandingBox;
	sf::FloatRect leftJumpingBox;
	sf::FloatRect rightFallingBox;
	sf::FloatRect rightStandingBox;
	sf::FloatRect rightJumpingBox;
	sf::FloatRect shootingBox;
	sf::FloatRect headBox;
	sf::Clock timer;
	sf::Sprite sprite;
	sf::Sprite *head;
	sf::Texture leftTexture;
	sf::Texture rightTexture;
	sf::Texture leftTouchTexture;
	sf::Texture leftJumpTexture;
	sf::Texture rightTouchTexture;
	sf::Texture rightJumpTexture;
	sf::Texture shootJumpTexture;
	sf::Texture shootTouchTexture;
	sf::Texture shootFallTexture;
	sf::Texture shootHeadTexture;

	float jumpAnimationTimer = 0.f;
	float jumpAnimationTimerMax = 35;
	float touchAnimationTimer = 7;
	float movementSpeed;
	float dy = 0;
	//Private functions
	void initLeftTexture();
	void initLeftStandTexture();
	void initLeftJumpTexture();
	void initRightTexture();
	void initRightStandTexture();
	void initRightJumpTexture();
	void initShootJumpTexture();
	void initShootTouchTexture();
	void initShootFallTexture();
	void initShootHeadTexture();
	void initSprite();
	void initPosition();

public:
	const int height = 350;
	Player();
	virtual ~Player();
	float getDY();
	void fall();
	void teleport(float width);
	void moveLeft(const float dirX,bool isShooting);
	void moveRight(const float dirX,bool isShooting);
	const sf::Vector2f& getPos() const;
	void jumpDetection(Platform* platform,bool isShooting);
	bool Collision(Enemy* enemy,float leftBound,float rightBound,float topBound,float bottomBound);
	bool headCollision(Enemy* enemy);
	bool jumpOnMonstersCollision(Enemy* enemy);
	void jumpOnMonster();
	bool jumpOnMonsterWhenShooting(Enemy* enemy);
	bool monsterCollision(Enemy* enemy);
	bool touchDetection(Platform* platform);
	bool touchShootingDetection(Platform* platform);
	void headWhenShooting(bool isShooting);
	void jumpAnimation(bool isShooting);
	bool isDead(float screenHeight);
	void moveUp();
	bool isUp();
	void update();
	void increaseScore(int& score,sf::Text& scoreText);

	void render(sf::RenderTarget& target);
	void renderHead(sf::RenderTarget* target,bool isShooting);
};

