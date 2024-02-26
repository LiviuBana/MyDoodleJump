#include "Player.h"

void Player::initLeftTexture()
{
	//this->texture.loadFromFile("Textures/bunny.png");
		//std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	
	sf::Image doodle;
	doodle.loadFromFile("Textures/bunnyleft.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->leftTexture.loadFromImage(doodle);
	this->leftFallingBox.left = 4;
	this->leftFallingBox.width = 60;
	this->leftFallingBox.top = 4;
	this->leftFallingBox.height = 50;

}

void Player::initLeftStandTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/lefttouch.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->leftTouchTexture.loadFromImage(doodle);
	this->leftStandingBox.left = 4;
	this->leftStandingBox.width =43;
	this->leftStandingBox.top = 4;
	this->leftStandingBox.height = 50;
}

void Player::initLeftJumpTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/leftjump.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->leftJumpTexture.loadFromImage(doodle);
	this->leftJumpingBox.left = 4;
	this->leftJumpingBox.width = 43;
	this->leftStandingBox.top = 4;
	this->leftStandingBox.height = 50;
}

void Player::initRightTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/bunnyright.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->rightTexture.loadFromImage(doodle);
	this->rightFallingBox.left = 4;
	this->rightFallingBox.width = 60;
	this->rightFallingBox.top = 4;
	this->rightFallingBox.height = 65;
}

void Player::initRightStandTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/righttouch.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->rightTouchTexture.loadFromImage(doodle);
	this->rightStandingBox.left = 19;
	this->rightStandingBox.width = 60;
	this->rightStandingBox.top = 4;
	this->rightStandingBox.height = 50;


}

void Player::initRightJumpTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/rightjump.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->rightJumpTexture.loadFromImage(doodle);
	this->rightJumpingBox.left = 19;
	this->rightJumpingBox.width = 60;
	this->rightJumpingBox.top = 4;
	this->rightJumpingBox.height = 50;

}

void Player::initShootJumpTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/shootjump.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->shootJumpTexture.loadFromImage(doodle);

}

void Player::initShootTouchTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/shoottouch.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->shootTouchTexture.loadFromImage(doodle);
}

void Player::initShootFallTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/shootfall.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->shootFallTexture.loadFromImage(doodle);
	this->shootingBox.left = 4;
	this->shootingBox.width = 36;
	this->shootingBox.top = 60;
	this->shootingBox.height = 70;

}

void Player::initShootHeadTexture()
{
	sf::Image doodle;
	doodle.loadFromFile("Textures/hophead.png");
	doodle.createMaskFromColor(sf::Color(255, 255, 255));
	this->shootHeadTexture.loadFromImage(doodle);
	this->headBox.left = 4;
	this->headBox.width = 42;
	this->headBox.top = 15;
	this->headBox.height = 44;
}

void Player::initSprite()
{
	
	this->sprite.setTexture(this->leftTexture);
}

void Player::initPosition()
{
	this->sprite.setPosition(210,200);
}

Player::Player()
{
	this->movementSpeed = 4.f;
	this->initLeftTexture();
	this->initShootFallTexture();
	this->initShootJumpTexture();
	this->initShootTouchTexture();
	this->initShootHeadTexture();
	this->initLeftStandTexture();
	this->initLeftJumpTexture();
	this->initRightTexture();
	this->initRightStandTexture();
	this->initRightJumpTexture();
	this->initSprite();
	this->initPosition();
}

Player::~Player()
{

}



float Player::getDY()
{
	return this->dy;
}

void Player::fall()
{
	dy+=0.2;
	this->sprite.move(0, dy);
}

void Player::teleport(float width)
{
	if (this->sprite.getPosition().x > width-20)
		this->sprite.setPosition(0, sprite.getPosition().y);
	if (this->sprite.getPosition().x < -40)
		this->sprite.setPosition(width-40, sprite.getPosition().y);
}

void Player::moveLeft(const float dirX,bool isShooting)
{

	this->sprite.move(dirX*this->movementSpeed,0);
	if (isShooting == true&&shootOn==false) {
		if (isJumping == true)
			this->sprite.setTexture(this->shootJumpTexture);
		else
			this->sprite.setTexture(this->shootFallTexture);
	}
	else
	if (isLeft == false) {
		isLeft = true;
		if (isJumping == true) {
				this->sprite.setTexture(this->leftJumpTexture);
		}

		else {
				this->sprite.setTexture(this->leftTexture);
		}
	}
	}



void Player::moveRight(const float dirX,bool isShooting)
{
	this->sprite.move(dirX * this->movementSpeed, 0);
	
	if (isShooting == true&&shootOn==false) {
		if (isJumping == true)
			this->sprite.setTexture(this->shootJumpTexture);
		else
			this->sprite.setTexture(this->shootFallTexture);
	}
	else
	if (isLeft == true) {
		isLeft = false;
		 
		if (isJumping == true) {
				this->sprite.setTexture(this->rightJumpTexture);
		}
		else {
				this->sprite.setTexture(this->rightTexture);
			}
		}
	
}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

void Player::jumpDetection(Platform* platform,bool isShooting)
{
	if (isShooting == true) {
		if (touchShootingDetection(platform )== true) {
			dy = -8;
			isJumping = true;
		}			
	}
	else if (touchDetection(platform)==true){
		dy=-10;
		isJumping = true;
	}
}
void Player::jumpOnMonster()
{
		dy = -12;
		isJumping = true;
}

bool Player::headCollision(Enemy* enemy)
{
	if ((this->head->getPosition().x + headBox.width > enemy->getPositions().x) && (this->head->getPosition().x + headBox.left < enemy->getPositions().x + enemy->getBounds().width)
		&& (this->head->getPosition().y + headBox.height > enemy->getPositions().y) && (this->head->getPosition().y + headBox.top < enemy->getPositions().y + enemy->getBounds().height)) {
		return true;
	}
	return false;
}
bool Player::Collision(Enemy* enemy, float leftBound, float rightBound, float topBound,float bottomBound)
{
	if ((this->sprite.getPosition().x + rightBound > enemy->getPositions().x) && (this->sprite.getPosition().x + leftBound < enemy->getPositions().x + enemy->getBounds().width)
		&& (this->sprite.getPosition().y + bottomBound > enemy->getPositions().y)&&(this->sprite.getPosition().y+topBound < enemy->getPositions().y + enemy->getBounds().height)){
		return true;
	}
	return false;

}
bool Player::monsterCollision(Enemy* enemy)
{
	if (isLeft == true) {
		if (fallOn == true) {
			return Collision(enemy, this->leftFallingBox.left, this->leftFallingBox.width, this->leftFallingBox.top,this->leftFallingBox.height);
		}
		if (touchOn == true) {
			return Collision(enemy, this->leftStandingBox.left, this->leftStandingBox.width, this->leftStandingBox.top,this->leftStandingBox.height);
		}
		if (jumpOn == true) {
			return Collision(enemy, this->leftJumpingBox.left, this->leftJumpingBox.width, this->leftJumpingBox.top,this->leftJumpingBox.height);
		}
	}
	else {
		if (fallOn == true) {
			return Collision(enemy, this->rightFallingBox.left, this->rightFallingBox.width, this->rightFallingBox.top,this->rightFallingBox.height);
		}
		if (touchOn == true) {
			return Collision(enemy, this->rightStandingBox.left, this->rightStandingBox.width, this->rightStandingBox.top,this->rightStandingBox.height);
		}
		if (jumpOn == true) {
			return Collision(enemy, this->rightJumpingBox.left, this->rightJumpingBox.width, this->rightJumpingBox.top,this->rightJumpingBox.height);
		}

	}
}



bool Player::jumpOnMonstersCollision(Enemy* enemy)
{
	if (isLeft == true) {
		return Collision(enemy, 4, 28, 55, 70);
	}
	else
		return Collision(enemy, 34, 62, 55, 70);
}

bool Player::jumpOnMonsterWhenShooting(Enemy* enemy)
{
	return Collision(enemy, this->shootingBox.left, this->shootingBox.width, this->shootingBox.top, this->shootingBox.height);
}


bool Player::touchDetection(Platform* platform)
{
	if (isLeft == true) {
		if ((this->sprite.getPosition().x + leftTextureRightBound > platform->getPosition().x) && (this->sprite.getPosition().x + leftTextureLeftBound < platform->getPosition().x + platform->getBounds().width)
			&& (this->sprite.getPosition().y + bottomBound > platform->getPosition().y) && this->sprite.getPosition().y + bottomBound < platform->getPosition().y + platform->getBounds().height)
			return true;
		return false;
	}
	else {
		if ((this->sprite.getPosition().x + rightTextureRightBound > platform->getPosition().x) && (this->sprite.getPosition().x + rightTextureLeftBound < platform->getPosition().x + platform->getBounds().width)
			&& (this->sprite.getPosition().y + bottomBound > platform->getPosition().y) && this->sprite.getPosition().y + bottomBound < platform->getPosition().y + platform->getBounds().height)
			return true;
		return false;

	}
}

bool Player::touchShootingDetection(Platform* platform)
{
	if ((this->sprite.getPosition().x + rightShootingBound > platform->getPosition().x) && (this->sprite.getPosition().x + leftShootingBound < platform->getPosition().x + platform->getBounds().width)
		&& (this->sprite.getPosition().y + bottomBound > platform->getPosition().y) && this->sprite.getPosition().y + bottomBound < platform->getPosition().y + platform->getBounds().height)
		return true;
	return false;
}

void Player::headWhenShooting(bool isShooting)
{
	if (isShooting == true) {
		if (headOn == false) {
			this->head = new sf::Sprite();
			this->head->setTexture(shootHeadTexture);
			headOn = true;
		}
			this->head->setPosition(this->sprite.getPosition().x-4  , this->sprite.getPosition().y+12);
	}
	else {
		if (headOn == true) {
			delete this->head;
			headOn = false;
		}
		//delete this->head;
	}
 }

void Player::jumpAnimation(bool isShooting)
{
	if (isJumping == true) {
		//shootFallingOn = false;
		if (jumpAnimationTimer <= touchAnimationTimer) {
			if (isShooting == true) {
				if (shootTouchingOn == false) {
					this->sprite.setTexture(this->shootTouchTexture);
					shootTouchingOn = true;
				}

			}
			if (touchOn == false && isShooting == false) {
				if (isLeft == true)
					this->sprite.setTexture(this->leftTouchTexture);
				else
					this->sprite.setTexture(this->rightTouchTexture);
				touchOn = true;
			}
		}
		else if (jumpAnimationTimer < jumpAnimationTimerMax) {
			touchOn = false;
			shootTouchingOn = false;
			if (isShooting == true) {
				if (shootJumpingOn == false) {
					this->sprite.setTexture(this->shootJumpTexture);
					shootJumpingOn = true;
				}
			}
			else
			if (jumpOn == false) {
					if (isLeft == true)
						this->sprite.setTexture(this->leftJumpTexture);
					else
						this->sprite.setTexture(this->rightJumpTexture);

					jumpOn = true;
				}
			}
		else if (jumpAnimationTimer >= jumpAnimationTimerMax) {
				shootJumpingOn = false;
				jumpOn = false;
				if (isShooting == true) {
					this->sprite.setTexture(this->shootFallTexture);
				}
				else if (isShooting == false) {
					if (isLeft == true)
						this->sprite.setTexture(this->leftTexture);
					else
						this->sprite.setTexture(this->rightTexture);
				}
				isJumping = false;
				jumpAnimationTimer = -1.f;
			}
	++jumpAnimationTimer;
	}
	else if (isJumping == false) {
		if (isShooting == true){
			fallOn = false;
			if (shootFallingOn == false) {
				this->sprite.setTexture(this->shootFallTexture);
				shootFallingOn = true;
			}
		}
		else {
			shootFallingOn = false;
			if (fallOn == false) {
				if (isLeft == true) {
					this->sprite.setTexture(this->leftTexture);
				}
				else
					this->sprite.setTexture(this->rightTexture);
				fallOn = true;
			}

			//shootFallingOn = true;
		}
	}
	
}

bool Player::isDead(float screenHeight)
{
	if (this->sprite.getPosition().y > screenHeight)
		return true;

	return false;
}


void Player::moveUp()
{
	this->sprite.setPosition(this->sprite.getPosition().x, height);
}

bool Player::isUp()
{
	if (this->sprite.getPosition().y < height)
		return true;
	return false;
}



void Player::update()
{
}



void Player::increaseScore(int& score,sf::Text& scoreText)
{
	if (this->sprite.getPosition().y <= height&& this->dy < (-1.62)) {
		score += 1;
		scoreText.setString("Score  " + std::to_string(score));
	}

}






void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}


void Player::renderHead(sf::RenderTarget* target,bool isShooting)
{
	if(isShooting==true)
		target->draw(*this->head);
}





