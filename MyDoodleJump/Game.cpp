#include "Game.h"



void Game::initBackground()
{
    this->backgroundTexture.loadFromFile("Textures/background2.png");
    this->background.setTexture(this->backgroundTexture);
}

void Game::renderBackground()
{
    this->window->draw(background);
}

void Game::initWindow()
{
    this->videoMode.height = 800;
    this->videoMode.width = 500;
    this->window = new sf::RenderWindow(this->videoMode, "My doodle jump", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
    // this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
    this->player = new Player();
}

void Game::initTextures()
{
    sf::Image platform;
    platform.loadFromFile("Textures/platform.png");
    platform.createMaskFromColor(sf::Color(255, 255, 255));
    this->textures["PLATFORM"] = new sf::Texture();
    this->textures["PLATFORM"]->loadFromImage(platform);

    sf::Image bullet;
    bullet.loadFromFile("Textures/easteregg2.png");
    bullet.createMaskFromColor(sf::Color(255, 255, 255));
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromImage(bullet);
}

void Game::initRandomPlatforms()
{
    std::uniform_int_distribution<unsigned> x(0, 500 - this->textures["PLATFORM"]->getSize().x);
    std::uniform_int_distribution<unsigned> y(100,700);
    std::default_random_engine e(time(0));
    for (int i = 1; i <= 5; i++) {
        this->platforms.push_back(new Platform(this->textures["PLATFORM"], x(e), y(e)));
    }
}

void Game::initPlatforms()
{
    int counter = 60;
    for (int i = 1; i <= 4; i++) {
        this->platforms.push_back(new Platform(this->textures["PLATFORM"], this->giveARandomNumber(0, 500 - this->textures["PLATFORM"]->getSize().x), counter));
        counter += 210;
    }


   //enemies.push_back(new BunnyMonster1(100, 100));


}

//constructors/destuctors
Game::Game()
{
    this->initWindow();
    this->initBackground();
    this->initTextures();
    this->initPlayer();
    this->initPlatforms();
    this->initRandomPlatforms();
    this->initFont();
    this->initText();
}

void Game::initFont()
{
    this->font.loadFromFile("Fonts/ARCADECLASSIC.ttf");
}

Game::~Game()
{
    delete this->window;
    delete this->player;
    for (auto& i : this->textures) {
        delete i.second;
    }
    for (auto* i : this->platforms) {
        delete i;
    }
    for (auto* i :this->bullets) {
        delete i;
    }
    for (auto* i : this->enemies) {
        delete i;
    }


}

void Game::initText()
{
    //gui text init
    this->guiText.setFont(this->font);
    this->guiText.setFillColor(sf::Color::Black);
    this->guiText.setCharacterSize(32);
    this->guiText.setString("Score  " + std::to_string(score));
    this->guiText.setPosition(10, 20);


    this->gameoverText.setFont(this->font);
    this->gameoverText.setCharacterSize(60);
    this->gameoverText.setString("Game Over");
    this->gameoverText.setPosition(this->window->getSize().x / 2.f-this->gameoverText.getGlobalBounds().width/2.f, this->window->getSize().y / 2.f-this->gameoverText.getGlobalBounds().height / 2.f);

}

int Game::giveARandomNumber(unsigned leftBound, unsigned rightBound) {

    std::uniform_int_distribution<unsigned> x(leftBound, rightBound);
    std::default_random_engine e(time(0));
    return x(e);

}
void Game::randomizeNumber(unsigned& randomNumber,unsigned leftBound,unsigned rightBound)
{
    std::uniform_int_distribution<unsigned> x(leftBound,rightBound);
    std::default_random_engine e(time(0));
    randomNumber = x(e);
}

void Game::run()
{
    while (this->window->isOpen()) {
        this->updatePollEvents();
        if(this->player->isDead(this->videoMode.height)==false)
             this->update();
        this->render();
    }
}
void Game::updatePollEvents()
{
    sf::Event e;
    while (this->window->pollEvent(e)) {
        if (e.Event::type == sf::Event::Closed)
            this->window->close();
        if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
            this->window->close();
    }
}
void Game::updateInput()
{
    //Move
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->player->moveLeft(-1.f,isShooting);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->player->moveRight(1.f,isShooting);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        this->shootBullets();
        this->isShooting = true;
    }
    else {
        this->isShooting = false;
    }

}
void Game::updateEnemies()
{
    unsigned counter = 0;
    for (auto* enemy : this->enemies) {
        enemy->update();
        if (enemy->getBounds().top > this->videoMode.height) {
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
        }
       
        ++counter;
    }
}
void Game::updateEnemiesCombat()
{
    for (int i = 0; i < this->enemies.size(); i++) {
        bool enemyDeleted = false;
        for (size_t k = 0; k < this->bullets.size()&&enemyDeleted==false; k++) {
            if (this->bullets[k]->getBounds().intersects(this->enemies[i]->getBounds())) {
                
                delete this->bullets[k];
                this->bullets.erase(this->bullets.begin() + k);
                
                delete this->enemies[i];
                this->enemies.erase(this->enemies.begin() + i);

                enemyDeleted = true;
            }

        }
    }
}
void Game::updatePlatforms()
{

}
//functions
void Game::update()
{
    this->updateScore();
    this->updateBullets();
    this->movePlatforms();
    this->updateEnemies();
    this->updateEnemiesCombat();
    this->updatePlayer();
    //Move Player
    this->player->fall();
    this->player->teleport(this->videoMode.width);
    if (isDead == false) {
        this->updateInput();
        this->JumpOnPlaforms();
    }
    else {
        this->movePlatformsWhenIsDead();
        this->moveEnemiesWhenIsDead();
    }
    this->player->jumpAnimation(isShooting);
    this->player->headWhenShooting(isShooting);
}

void Game::render()
{

    this->window->clear();
    this->renderBackground();
    for (auto* enemy : this->enemies) {
        enemy->render(this->window);
    }
    for (auto* bullet : this->bullets) {
        bullet->render(this->window);
    }

    this->player->render(*this->window);
    this->player->renderHead(this->window,isShooting);

    for (auto* platform : this->platforms) {

        platform->render(this->window);
    }
    //Render gui
    this->renderGUI(this->window);
    
    //GameOverScreen
    if (this->player->isDead(this->videoMode.height)==true)
        this->window->draw(this->gameoverText);
    //Draw game objects
    this->window->display();
}

void Game::updatePlayer()
{
    if (isShooting == false) {
        for (auto* enemy : this->enemies) {
            if (this->player->jumpOnMonstersCollision(enemy) == true) {
                enemy->moveDown(0,800);
                if(isDead==false)
                    this->player->jumpOnMonster();
            }
            if (this->player->monsterCollision(enemy) == true)
                isDead = true;
           
        }
    }
    else {
        for (auto* enemy : this->enemies) {
            if (this->player->jumpOnMonsterWhenShooting(enemy) == true) {
                enemy->moveDown(0, 800);
                if (isDead == false)
                    this->player->jumpOnMonster();
            }
            if (this->player->headCollision(enemy) == true)
                isDead = true;
            
        }
    }
}

void Game::movePlatformsWhenIsDead()
{
    unsigned counter = 0;
    for (auto* platform : this->platforms) {
        platform->moveUp();
        if (platform->getPosition().y + platform->getBounds().height <= 0) {
            delete this->platforms.at(counter);
            this->platforms.erase(this->platforms.begin() + counter);
            --counter;
        }
        ++counter;

            
    }
}

void Game::moveEnemiesWhenIsDead()
{
    unsigned counter = 0;
    for (auto* enemy : this->enemies) {
        enemy->moveUp();
        if (enemy->getPositions().y + enemy->getBounds().height <= 0) {
            delete this->enemies.at(counter);
            this->enemies.erase(this->enemies.begin() + counter);
            --counter;
        }
        ++counter;


    }
}

void Game::renderGUI(sf::RenderTarget* target)
{
    target->draw(this->guiText);
}

void Game::updateScore()
{
    this->player->increaseScore(score,guiText);
    
}


void Game::JumpOnPlaforms()
{

    for (size_t i = 0; i < platforms.size(); i++) {
        this->player->jumpDetection(platforms[i],isShooting);
    }
}

void Game::movePlatforms()
{
    unsigned counter = 0;
    std::uniform_int_distribution<unsigned> x(0, 500 - this->textures["PLATFORM"]->getSize().x);
    std::uniform_int_distribution<int> y(-30, 0);
    std::default_random_engine e(time(0));
    if (this->player->isUp()) {
        this->player->moveUp();
        for (int i = 0; i < platforms.size(); i++) {
            platforms[i]->moveDown(0,-(this->player->getDY()),x(e),y(e),this->videoMode.height,spawningCounter);
            if (spawningCounter == randomNumber1) {
                this->randomizeNumber(randomNumber2, 0, 3);
                if (randomNumber2 == 0)
                    enemies.push_back(new BunnyMonster1(this->platforms[i]->getPosition().x, this->platforms[i]->getPosition().y));
                else if(randomNumber2==1)
                    enemies.push_back(new BunnyMonster3(this->platforms[i]->getPosition().x, this->platforms[i]->getPosition().y));
                else if (randomNumber2 == 2) {
                    enemies.push_back(new BunnyMonster2(this->giveARandomNumber(0, 400), this->giveARandomNumber(-200,-20)));
                }
                else if (randomNumber2 == 3) {
                    enemies.push_back(new BunnyMonster4(this->giveARandomNumber(0, 400), this->giveARandomNumber(-200, -20)));
                }
                spawningCounter = 0;

            }
           

        }
        for (int j = 0; j < enemies.size(); j++) {
            enemies[j]->moveDown(0, -this->player->getDY());
        }
        for (int j = 0; j < bullets.size(); j++) {
            bullets[j]->moveDown(0, -this->player->getDY());
        }
    }
}

void Game::updateBullets()
{
    unsigned counter = 0;
    for (auto* bullet : this->bullets) {
        bullet->update();
        if (bullet->getBounds().top > this->videoMode.height) {
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin()+counter);
            --counter;
        }
        ++counter;
    }
}

void Game::shootBullets()
{
    shootBulletTimer++;
    if (this->shootBulletTimer >= this->shootBulletTimerMax) {
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 4.f));
        shootBulletTimer = 0.f;
    }
}
