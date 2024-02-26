#pragma once
#include "Enemy.h"
class BunnyMonster4 :
    public Enemy
{
private:
    const int upperBound = 10;
    const int leftBound = 0;
    const int rightBound = 0;
    sf::Texture texture;
    sf::Sprite* sprite = new sf::Sprite();
    sf::Clock animationTimer;
    sf::IntRect currentFrame;
    float textureHeight = 89;
    bool spawnMove = true;
    bool leftMove = false;
    bool rightMove = false;
    float initialxPos;
    float xRange = 75;
public:
    BunnyMonster4(float posX, float posY);
    void moveLeftRight(float x, float movementSpeed);
    // Inherited via Enemy
    virtual void initAnimation() override;
    virtual void initSprite() override;
    virtual void initTexture() override;
    virtual void updateAnimation() override;
    virtual void update() override;
    virtual sf::FloatRect getBounds() const override;
    sf::Vector2f getPositions() const;
    virtual void moveDown(float x, float y) override;
    virtual void render(sf::RenderTarget* target) override;

    // Inherited via Enemy
    virtual void moveUp() override;
};

