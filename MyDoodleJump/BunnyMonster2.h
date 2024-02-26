#pragma once
#include "Enemy.h"
class BunnyMonster2 :
    public Enemy
{
private:
    sf::Texture texture;
    sf::Sprite* sprite = new sf::Sprite();
    sf::Clock animationTimer;
    sf::IntRect currentFrame;
    float textureHeight = 51;
    bool spawnMove = true;
    bool leftMove = false;
    bool rightMove = false;
    float initialxPos;
    float xRange = 150;
public:
    BunnyMonster2(float posX, float posY);
    // Inherited via Enemy
    virtual void initAnimation() override;
    virtual void initSprite() override;
    virtual void initTexture() override;
    virtual void updateAnimation() override;
    virtual void update() override;
    virtual sf::FloatRect getBounds() const override;
    sf::Vector2f getPositions() const;
    virtual void moveDown(float x, float y) override;
    void moveLeftRight(float x,float movementSpeed);
    virtual void render(sf::RenderTarget* target) override;

    // Inherited via Enemy
    virtual void moveUp() override;
};

