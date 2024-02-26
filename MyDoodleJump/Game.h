#pragma once


#include"Player.h"
#include"Platforms.h"
#include"Enemy.h"
#include"BunnyMonster1.h"
#include"BunnyMonster3.h"
#include"BunnyMonster2.h"
#include"BunnyMonster4.h"
#include<ctime>
#include <random>
class Game
{
private:
	

	float shootBulletTimer = 0.f;
	float shootBulletTimerMax = 25.f;
	unsigned randomNumber1=10;
	bool isShooting = false;
	bool isDead = false;
	unsigned spawningCounter = 0;
	unsigned randomNumber2;
	int score = 0;
	// Window
	sf::Texture backgroundTexture;
	sf::Sprite background;
	sf::Font font;
	sf::Text guiText;

	sf::Text gameoverText;
	Player* player;
	std::map<std::string, sf::Texture*>textures;
	//Resources
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event ev;
	//Bullet
	std::vector<Enemy*>enemies;
	std::vector<Bullet*> bullets;
	//Platforms
	sf::Texture GreenPlatformTexture;
	std::vector<Platform*>platforms;
	//Private functions
	void initBackground();
	void renderBackground();
	void initRandomPlatforms();
	void initPlatforms();
	void initWindow();
	void initPlayer();
	void initTextures();
	void initFont();
	void initText();
		
public:
	//constructors/Destructors
	Game();
	virtual ~Game();
	//Functions
	int giveARandomNumber(unsigned leftBound, unsigned rightBound);
	void randomizeNumber(unsigned& randomNumber,unsigned leftBound,unsigned rightBound);
	void spawnEnemies();
	void run();
	void updatePlayer();
	void movePlatformsWhenIsDead();
	void moveEnemiesWhenIsDead();
	void movePlatforms();
	void JumpOnPlaforms();
	void updatePollEvents();
	void updateInput();
	void updateEnemies();
	void updateEnemiesCombat();
	void updatePlatforms();
	void updateBullets();
	void shootBullets();
	void update();
	void renderGUI(sf::RenderTarget* target);
	void updateScore();
	void render();
};

